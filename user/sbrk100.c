#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int main(){
    sbrk(100);
    exit(0);
}