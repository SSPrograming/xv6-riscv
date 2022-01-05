#include "kernel/types.h"
#include "user/user.h"

int main() {
    uint64 available = kspare();
    printf("available memory: %lB\n", available);
    vmprint();
    exit(0);
}
