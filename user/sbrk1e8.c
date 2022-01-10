#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int main(){
    int n=20;
    while(n--) {
        sbrk(100000000);
        sbrk(-100000000);
    }
    exit(0);
}