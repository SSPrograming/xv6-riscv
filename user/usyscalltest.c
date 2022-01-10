#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int main() {
    int n = 1000;
    int pid;
    int psz;
    while(n--) {
        pid = getpid();
        psz = ugetsz();
    }
    printf("%d, %d", pid, psz);
    exit(0);
}