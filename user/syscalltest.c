#include "kernel/types.h"
#include "user/user.h"

int main() {
    uint64 available = kspare();
    printf("available memory: %lB\n", available);
    printf("pid: %d\n", ugetpid());
    printf("sz: %lB\n", ugetsz());
    vmprint();
    exit(0);
}
