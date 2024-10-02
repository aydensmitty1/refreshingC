#include <stdio.h>
#include <stdlib.h>

#define ROWSIZE  4
#define COLSIZE  5

// Prints Matrix to help see results of Transpose
void printMatrix(int **matrix, int rows, int cols){
    for (int i = 0; i < rows; i++){
        printf("ROW: %d|", i);
        for (int j = 0; j < cols; j++){
            printf("\t%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

// Frees Boths Columns and rows of the matrix
void deleteMatrix(int ** mat, int rows){
    for (int i = 0; i < rows; i++){
        free(mat[i]);
    }
    free(mat);
    return;
}

// Populates matrix with by incrementing by one each input
void populateMatrix(int **mat, int rows, int cols){
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            mat[i][j] = count;
            count++;
        }
        
    }
    
}
// Dynamically allocates Memory and creates a matrix of zeros
int** matrixInit(int rows, int cols){
    int **mat = calloc(rows, sizeof(int*));
    if (!mat){
        printf("Row Memory Allocation Failed, Quitting.....");
        return NULL;
    }
    
    for (int i = 0; i < rows; i++){
       mat[i] = calloc(cols, sizeof(int));
       if (!mat[i]){
        printf("Col Memory Allocation Failed, Quitting.....");
        return NULL;
    }
    }
    return mat;
}
// Transposes matrix
int** transposeMatrix(int **matrix, int rows, int cols){
    int **newMat;
    newMat = matrixInit(COLSIZE, ROWSIZE);
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            newMat[i][j] = matrix[j][i];
        }
    }
    deleteMatrix(matrix, cols);
    return newMat;
}

int main(){
    int **matrix;
    matrix = matrixInit(ROWSIZE, COLSIZE);
    populateMatrix(matrix, ROWSIZE, COLSIZE);
    printMatrix(matrix, ROWSIZE, COLSIZE);
    matrix = transposeMatrix(matrix, ROWSIZE, COLSIZE);
    printf("----------------TRANSPOSED-------------------\n");
    printMatrix(matrix, COLSIZE, ROWSIZE);
    matrix = transposeMatrix(matrix, COLSIZE, ROWSIZE);
    printf("----------------UNTRANSPOSED-----------------\n");
    printMatrix(matrix, ROWSIZE, COLSIZE);
    deleteMatrix(matrix, ROWSIZE);
    return 0;
}