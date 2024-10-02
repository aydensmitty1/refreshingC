#include <stdio.h>
#include <stdlib.h>

int** transposeMatrix(int **matrix, int rows, int cols){

    return matrix;
}

void printMatrix(int *matrix){

    for (int i = 0; i < sizeof(matrix); i++){
        printf("[");
        for (int j = 0; j < sizeof(matrix[0]); j++){
            // printf(" %d,", matrix[i][j]);
        }
        printf("]\n");

    }
    
}


int main(){
    int rows, cols = 3;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(matrix);
    transposeMatrix(&matrix, rows, cols);
    printMatrix(matrix);
    return 0;
}