#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    printf("-------------------------------------\n");
    printf("Before sbrk(1)\n");
    vmprint();
    sbrk(1);
    printf("After sbrk(1)\n");
    vmprint();
    printf("-------------------------------------\n");
    
    exit(0);
}
