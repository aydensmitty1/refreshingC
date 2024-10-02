typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct QueueUsingStacks {
    StackNode* stack1;
    StackNode* stack2;
} QueueUsingStacks;

// Queue operations
void enqueue(QueueUsingStacks* q, int data);
int dequeue(QueueUsingStacks* q);
int isEmpty(QueueUsingStacks* q);

// Stack utility functions
void push(StackNode** top, int data);
int pop(StackNode** top);
int peek(StackNode* top);

