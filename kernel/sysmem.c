#include "types.h"
#include "riscv.h"
#include "defs.h"
#

// Get the amount of free memory available
uint64
sys_kspare(void)
{
  return kspare();
}
