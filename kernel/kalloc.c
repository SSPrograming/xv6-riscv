// Physical memory allocator, for user processes,
// kernel stacks, page-table pages,
// and pipe buffers. Allocates whole 4096-byte pages.

#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "riscv.h"
#include "defs.h"

void freerange(void *pa_start, void *pa_end);

extern char end[]; // first address after kernel.
                   // defined by kernel.ld.

struct run {
  struct run *next;
};

struct {
  struct spinlock lock;
  struct run *freelist;
} kmem;

#define PA2MAP(PA)((PA - KERNBASE) >> PGSHIFT)
struct {
  struct spinlock lock;
  uint32 page_ref[PA2MAP(PHYSTOP)];
} kmap;

void
kinit()
{
  initlock(&kmem.lock, "kmem");
  initlock(&kmap.lock, "kmap");
  freerange(end, (void*)PHYSTOP);
}

void
freerange(void *pa_start, void *pa_end)
{
  char *p;
  p = (char*)PGROUNDUP((uint64)pa_start);
  acquire(&kmap.lock);
  memset(kmap.page_ref, 0, sizeof(kmap.page_ref));
  release(&kmap.lock);
  for(; p + PGSIZE <= (char*)pa_end; p += PGSIZE)
    kfree(p);
}

// Free the page of physical memory pointed at by v,
// which normally should have been returned by a
// call to kalloc().  (The exception is when
// initializing the allocator; see kinit above.)
void
kfree(void *pa)
{
  struct run *r;

  if(((uint64)pa % PGSIZE) != 0 || (char*)pa < end || (uint64)pa >= PHYSTOP)
    panic("kfree");

  acquire(&kmap.lock);
  // Only when ref count == 0, free pa
  if (kmap.page_ref[PA2MAP((uint64)pa)] == 0)
  {
  }
  else if (--kmap.page_ref[PA2MAP((uint64)pa)] > 0)
  {
    release(&kmap.lock);
    return;
  }
  release(&kmap.lock);

  // Fill with junk to catch dangling refs.
  memset(pa, 1, PGSIZE);

  r = (struct run*)pa;

  acquire(&kmem.lock);
  r->next = kmem.freelist;
  kmem.freelist = r;
  release(&kmem.lock);
}

// Allocate one 4096-byte page of physical memory.
// Returns a pointer that the kernel can use.
// Returns 0 if the memory cannot be allocated.
void *
kalloc(void)
{
  struct run *r;

  acquire(&kmem.lock);
  r = kmem.freelist;
  if(r)
    kmem.freelist = r->next;
  release(&kmem.lock);

  if(r) {
    memset((char*)r, 5, PGSIZE); // fill with junk
    acquire(&kmap.lock);
    kmap.page_ref[PA2MAP((uint64)r)] = 1; // Set reference count = 1
    release(&kmap.lock);
  }
  return (void*)r;
}

// Increase ref count
void 
kincrease(void *pa) {
  acquire(&kmap.lock);
  kmap.page_ref[PA2MAP((uint64)pa)]++; // increase reference count
  release(&kmap.lock);
}

// Decrease ref count
void 
kdecrease(void *pa) {
  acquire(&kmap.lock);
  kmap.page_ref[PA2MAP((uint64)pa)]--; // decrease reference count
  release(&kmap.lock);
}

// Get ref count
uint64 
kref(void* pa) {
  return kmap.page_ref[PA2MAP((uint64)pa)];
}

// Get the amount of free memory available
uint64
kspare(void)
{
  struct run *r;

  acquire(&kmem.lock);
  r = kmem.freelist;
  uint64 spare_count;
  // compute the amount of free memory available
  spare_count = 0;
  while (r)
  {
    spare_count++;
    r = r->next;
  }
  release(&kmem.lock);

  return spare_count * PGSIZE;
}
