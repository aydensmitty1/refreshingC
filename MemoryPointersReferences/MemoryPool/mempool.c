#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the size of each memory chunk
#define CHUNK_SIZE 32
#define NUM_CHUNKS 10  // Memory pool will have space for 10 chunks

typedef struct MemoryPool {
    unsigned char pool[CHUNK_SIZE * NUM_CHUNKS];
    bool freeBlocks[NUM_CHUNKS];
} MemoryPool;


MemoryPool memoryPool;

void initMemoryPool(){
    for (int i = 0; i < NUM_CHUNKS; i++){
        memoryPool.freeBlocks[i] = true;
    }
}
void* allocateMemory(){
    for (int i = 0; i < NUM_CHUNKS; i++){
        if (memoryPool.freeBlocks[i]){
            memoryPool.freeBlocks[i] = false;
            return (void*)&memoryPool.pool[i * CHUNK_SIZE];
        }
        
    }
    printf("Memory Pool is Full!");
    return NULL;
}

void freeMemory(void* ptr){
    int index = ((unsigned char*)ptr - memoryPool.pool)/CHUNK_SIZE;
    if (index >= 0 && index < NUM_CHUNKS && !memoryPool.freeBlocks[index]){
        memset(ptr, 0, sizeof(*ptr));
        memoryPool.freeBlocks[index] = true;
    }else{
        printf("Invalid Free or Double Free!");
    }
    return;
}



void testMemoryPool() {
    printf("Initializing memory pool...\n");
    initMemoryPool();
    
    printf("\nTest 1: Basic allocation and freeing\n");
    void* p1 = allocateMemory();
    char *str = p1;
    if (p1) {
        strncpy(str, "HELLO THERE!", 13);
        printf("Memory allocated at address: %p\n", p1);
        printf("Memory at address %p stores value %s\n", str, str);
    } else {
        printf("Memory allocation failed!\n");
    }

    freeMemory(p1);
    printf("Memory at address %p has been freed.\n", p1);
    printf("Memory at address %p stores value %s\n", str, str);

    // Reallocate to check if the freed block can be reused
    void* p2 = allocateMemory();
    if (p2 == p1) {
        printf("Memory reused correctly: %p\n", p2);
    } else {
        printf("Error: Freed memory was not reused!\n");
    }
    freeMemory(p2);

    printf("\nTest 2: Allocate until exhaustion\n");
    void* allocatedBlocks[NUM_CHUNKS];
    for (int i = 0; i < NUM_CHUNKS; i++) {
        allocatedBlocks[i] = allocateMemory();
        if (allocatedBlocks[i]) {
            printf("Allocated block %d at address: %p\n", i + 1, allocatedBlocks[i]);
        } else {
            printf("Memory allocation failed at block %d\n", i + 1);
        }
    }

    // Try to allocate more than the pool size
    void* pExhaust = allocateMemory();
    if (pExhaust == NULL) {
        printf("No more memory available, as expected.\n");
    } else {
        printf("Error: Allocated more memory than available!\n");
    }

    printf("\nTest 3: Free and reallocate blocks\n");
    // Free all blocks
    for (int i = 0; i < NUM_CHUNKS; i++) {
        freeMemory(allocatedBlocks[i]);
        printf("Freed block %d at address: %p\n", i + 1, allocatedBlocks[i]);
    }

    // Reallocate all blocks
    for (int i = 0; i < NUM_CHUNKS; i++) {
        allocatedBlocks[i] = allocateMemory();
        if (allocatedBlocks[i]) {
            printf("Reallocated block %d at address: %p\n", i + 1, allocatedBlocks[i]);
        } else {
            printf("Memory allocation failed at block %d\n", i + 1);
        }
    }

    printf("\nTest 4: Double-free detection\n");
    freeMemory(allocatedBlocks[0]);
    printf("Freed block 1 at address: %p\n", allocatedBlocks[0]);

    printf("Attempting to double-free block 1...\n");
    freeMemory(allocatedBlocks[0]);  // This should trigger an error
}

int main() {
    testMemoryPool();
    return 0;
}