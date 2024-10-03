#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1000

typedef struct {
    char *buffer;  // Pointer to the buffer array
    int head;     // Index of the head (where to write)
    int tail;     // Index of the tail (where to read)
    int maxSize;  // Maximum size of the buffer
} FileBuffer;


FileBuffer* FileBufferInit(int size){
    FileBuffer* fb = (FileBuffer*)calloc(1,sizeof(FileBuffer));
    fb->buffer = calloc(size, sizeof(char));
    fb->head = 0;
    fb->tail = 0;
    fb->maxSize = size;

    return fb;
}

void deleteFileBuffer(FileBuffer* fb){
    free(fb->buffer);
    free(fb);
    printf("Buffer Memory Freed");
    return;
}

void readFileToBuff(FileBuffer* fb, char* filename, int numBytes){
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error opening file");
      return;
   }
    fread(fb->buffer, 1, numBytes - 2, fp);
    fb->buffer[numBytes-1] = '\0'; 
    // printf("%s\n", fb->buffer);
    fclose(fp);
}

void writeFileFromBuff(FileBuffer* fb, char* filename, int numBytes){
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
      printf("Error opening file");
      return;
   }
   fwrite(fb->buffer, sizeof(char), numBytes, fp);
   memset(fb->buffer, 0, numBytes);
   printf("Puffer Contents: %s\n", fb->buffer);
   fclose(fp);
}


int main(){
    FileBuffer * fb = FileBufferInit(BUFFSIZE);
    readFileToBuff(fb, "Read.txt", BUFFSIZE);
    writeFileFromBuff(fb, "Write.txt", BUFFSIZE);
    deleteFileBuffer(fb);
    return 0;
}