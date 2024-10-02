#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtBeginning(Node** head, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {printf("Memory allocation failed\n"); return;}
    newNode->data = data;
    if (head){
        newNode->next = *head;
    }
    *head = newNode;
    return;
}

void displayLL(Node* head){
    Node *trav = head;
    printf("\nhead");
    while (trav){
        printf("->(Node %d)", trav->data);
        trav = trav->next;
    }
    return;
}

int main(){
    Node *root = 0;
    insertAtBeginning(&root, 3);
    insertAtBeginning(&root, 2);
    insertAtBeginning(&root, 7);
    displayLL(root);
    return 0;
}