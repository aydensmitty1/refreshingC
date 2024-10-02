#include <stdlib.h>
#include <stdio.h>

void resizeArray(int **parr, int currentSize, int newSize){
    //Dynamically allocate new memory to new array
    int *newParr = (int*)malloc(newSize * sizeof(int));
    //Return an error message if memory allocation fails
    if (!newParr){
        printf("Memory Allocation Failed!");
        return;
    }
    //Copy over data from first array to new one
    int minSize = (currentSize < newSize) ? currentSize : newSize;
    for (int i = 0; i < minSize; i++){
        *(newParr + i) = *(*parr + i);
    }
    //Free memory from orginal array
    free(*parr);
    //Transer old array pointer so it points at new array
    *parr = newParr;
    return;
}

//Helper function that prints array to save file space
void printArray(int *arr, int size){
    printf("Array: ");
    for (int i = 0; i < size; i++){
        printf("%d, ", arr[i]);
    }
}
//Helper function that adds to array to save file space
void addToArray(int *arr, int start, int size){
    for (int i = start; i < size; i++){
        *(arr + i) = i * 5;
    }
}

int main(){
    //Initilize Vars and dynamic array
    int initSize = 10;
    int newSize = 5;
    int *parr = (int*)malloc(initSize * sizeof(int));
    //Returns error message if memory allocation fails
    if (!parr){
        printf("Memory Allocation Failed!");
        return 1;
    }

    addToArray(parr, 0, initSize);

    printArray(parr, initSize);
    
    printf("\nResizing from %d to %d........\n", initSize, newSize);
    //Resize the array
    resizeArray(&parr,initSize, newSize);

    addToArray(parr, initSize, newSize);

    printArray(parr, newSize);
    //Free the array's Memory
    free(parr);
    return 0;
}