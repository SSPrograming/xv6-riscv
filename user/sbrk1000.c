#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int main(){
    int n=20;
    while(n--) {
        sbrk(1000);
        sbrk(-1000);
    }
    exit(0);
}