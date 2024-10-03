#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;  // Pointer to the buffer array
    int head;     // Index of the head (where to write)
    int tail;     // Index of the tail (where to read)
    int maxSize;  // Maximum size of the buffer
    int count;    // Number of elements in the buffer
} CircularBuffer;

// Initializes the buffer with the given size.
CircularBuffer* buffer_init(int size) {
    // Allocate memory for the circular buffer structure
    CircularBuffer *cbuff = (CircularBuffer *)malloc(sizeof(CircularBuffer));
    cbuff->buffer = malloc(size * sizeof(char));
    memset(cbuff->buffer, 0, sizeof(cbuff->buffer));
    cbuff->head = 0;
    cbuff->tail = 0;
    cbuff->maxSize = size;
    cbuff->count = 0;

    return cbuff;  // Return the pointer to the initialized buffer
}

// Writes data into the buffer. If the buffer is full, overwrite the oldest data.
void buffer_write(CircularBuffer* buff , char* data){
    int size = strlen(data);
    // printf("Head: %d\n", buff->head);
    if (size >= buff->maxSize){
        printf("WARNING: ATTEMPTED BUFFER OVERFLOW, WRITE FAILED!\n");
        return;
    }
    
    for (int i = 0; i < size; i++){
        if (buff->head >= (buff->maxSize)){
            // printf("Head: %d\n", buff->head);
            // printf("Resetting Head\n");
            buff->buffer[buff->maxSize] = 0;
            buff->head = 0;
        }
        buff->buffer[buff->head] = data[i];
        buff->count++;
        if (buff->count >= buff->maxSize){
            buff->count = 20;
        }
        
        buff->head++;
    }
    

}

// Reads and removes the oldest data from the buffer. If the buffer is empty, return an error.
void buffer_read(CircularBuffer* buff){
    if (buff->tail == buff->head){
        printf("ATTEMPTED BUFFER UNDERFLOW!, READ FAILED!");
        return;
    }
    
    printf("Reading: ");
    for (buff->tail; buff->count > 0 ; buff->tail++){
        if (buff->tail >= buff->maxSize){
            buff->tail = 0;
        }
        printf("%c", buff->buffer[buff->tail]);
        buff->buffer[buff->tail] = 0;
        buff->count--;
    }
    printf("\n");
    return;
} 

void delete_buffer(CircularBuffer* buff){
    free(buff->buffer);
    free(buff);
}

void resizeBuffer(CircularBuffer*buff, int newSize){
    //Dynamically allocate new memory to new array
    char *newbuff = malloc(newSize * sizeof(int));
    //Return an error message if memory allocation fails
    if (!newbuff){
        printf("Memory Allocation Failed!");
        return;
    }
    //Copy over data from first array to new one
    int minSize = (buff->maxSize < newSize) ? buff->maxSize : newSize;
    for (int i = 0; i < minSize; i++){
        *(newbuff + i) = *(buff->buffer + i);
    }
    //Free memory from orginal array
    free(buff->buffer);
    //Transer old array pointer so it points at new array
    buff->buffer = newbuff;
    return;
}


// Returns the current number of elements in the buffer.
int buffer_size(CircularBuffer* buff){ return buff->count;} 

void printBuffContent(CircularBuffer *buff){ printf("buffcontents: %s\n", buff->buffer);}

int buffer_is_empty(CircularBuffer * buff){return (buff->count == 0 ? 1: 0);}

int buffer_is_full(CircularBuffer * buff) {return (buff->count == buff->maxSize? 1: 0);}


int main(){
    
    int buffSize = 20;
    CircularBuffer *buff = buffer_init(buffSize);
    buffer_read(buff);
    printBuffContent(buff);
    buffer_write(buff, "Hello There!");
    printBuffContent(buff);
    buffer_read(buff);
    printBuffContent(buff);
    printf("isempty: %d\n", buffer_is_empty(buff));
    buffer_write(buff, "hi there man how are you!");
    buffer_write(buff, "hi there!");
    printBuffContent(buff);
    buffer_write(buff, "whats up buddy!");
    printBuffContent(buff);
    printf("Count: %d\n", buff->count);
    printf("isFull: %d\n", buffer_is_full(buff));
    buffer_read(buff);
    printBuffContent(buff);
    printf("Count: %d\n", buff->count);
    printf("isempty: %d\n", buffer_is_empty(buff));
    delete_buffer(buff);
    return 0;
}
