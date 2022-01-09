#include "kernel/types.h"
#include "kernel/memlayout.h"
#include "user/user.h"

int str2num(char* number) {
    int len = strlen(number);
    int res = 0;
    for (int i = 0; i<len; i++){
        res = res*10 + number[i]-'0';
    }
    return res;
}

int main(int argc, char* argv[]){
    sbrk(1024*1024);
    vmprint();
    if (argc != 2) {
        printf("please enter specify the size of the matrix\n");
        exit(1);
    }
    int matrix_size = str2num(argv[1]);
    printf("\n%d\n", matrix_size);
    //sbrk(1024*1024*3);
    /*
    vmprint();
    int** matrix = (int **)malloc(matrix_size*sizeof(int *));
    for (int i=0;i<matrix_size;i++){
        matrix[i] = (int *)malloc(matrix_size*sizeof(int));
    }
    for(int i =0;i<matrix_size;i++){
        for (int j =0;j<matrix_size;j++) {
            matrix[i][j] = matrix_size;
        }
    }
    for(int i =0;i<matrix_size;i++){
        printf("%d\t", matrix[i][i]);
        if(i>30) {
            break;
        }
    }
    printf("\n");*/    

    /*
    int matrix_static[64][64];
    vmprint();
    for(int i =0;i<matrix_size;i++){
        for (int j =0;j<matrix_size;j++) {
            matrix_static[i][j] = matrix_size;
        }
    }
    //for(int i =0;i<matrix_size;i++){
    //    printf("%d\t", matrix_static[i][i]);
    //    if(i>30) {
    //        break;
    //    }
    //}
    printf("\n");
    vmprint();
    */
    exit(0);
}