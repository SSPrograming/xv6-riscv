#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int main(){
    sbrk(10000);
    exit(0);
}