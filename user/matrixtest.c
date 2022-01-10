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
    if (argc != 2) {
        printf("please enter specify the size of the matrix\n");
        exit(1);
    }
    int matrix_size = str2num(argv[1]);
    int** matrix = (int **)malloc(matrix_size*sizeof(int *));
    for (int i=0;i<matrix_size;i++){
        matrix[i] = (int *)malloc(matrix_size*sizeof(int));
    }
    vmprint();
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
    printf("\n");
    vmprint();
    exit(0);
}