#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


// Insertion functions
void insertAtBeginning(Node** head, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {printf("Memory allocation failed\n"); return;}
    newNode->data = data;
    newNode->prev = 0;
    if (head){
        newNode->next = *head;
    }
    *head = newNode;
    return;
}

void insertAtEnd(Node** head, int data){
    if (!head) {insertAtBeginning(head, data); return;}
    
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {printf("Memory allocation failed\n"); return;}
    newNode->data = data;
    newNode->next = 0;
    Node *trav = *head;
    while (trav->next!=0) trav = trav->next;
    trav->next = newNode;
    newNode->prev = trav;
    return;
}

void insertAtPosition(Node** head, int data, int position){
    if (!head) {insertAtBeginning(head, data); printf("Empty head, defaulted to beginning insert!\n"); return;}

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {printf("Memory allocation failed\n"); return;}
    newNode->data = data;
    Node *trav = *head;

    for (int i = 2; i < position; i++, trav = trav->next);
    newNode->next = trav->next;
    trav->next->prev = newNode;
    newNode->prev = trav;
    trav->next = newNode;
    
}

// Deletion functions
void deleteFromBeginning(Node** head){
    if (!head){
        printf("List is Empty");
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    if (temp->next) temp->next->prev = 0;
    free(temp);
    return;
}

void deleteFromEnd(Node** head){
    if (!head){
        printf("List is Empty");
        return;
    }

    Node *temp = *head;
    while(temp->next) temp = temp->next;
    if (!temp->prev) {*head = 0; free(temp); return;}
    temp->prev->next = 0;
    free(temp);
    return;

}
void deleteAtPosition(Node** head, int position){
    if (!head){
        printf("List is Empty");
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position; i++, temp = temp->next);
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
    
}

// Other operations
void reverseList(Node** head){
    Node *temp = *head;
    Node *trav = *head;
    // printf("iteration");
    while (trav){
        temp = trav->next;
        trav->next = trav->prev;
        trav->prev = temp;
        if (!temp){
            *head = trav;
        }
        trav = temp;
        
    }
    return;
}



int searchList(Node* head, int target){
    Node *trav = head;
    int index = 1;
    while (trav){
        if (trav->data == target){
            return index;
        }
        trav = trav->next;
        index++;
    }
    printf("Target Not Found!");
    return -1;
}

void displayForward(Node* head){
    Node *trav = head;
    printf("\nhead");
    while (trav){
        printf("->(Node %d)", trav->data);
        trav = trav->next;
    }
    return;
}

void displayBackward(Node* head){
    Node *trav = head;
    printf("\nTail");
    while (trav->next) trav = trav->next;
    while (trav){
        printf("->(Node %d)", trav->data);
        trav = trav->prev;
    }
    return;
    
}



int main(){
    Node *root = 0;
    //Creating List by testing all insert functions
    insertAtBeginning(&root, 3);
    insertAtBeginning(&root, 1);
    insertAtEnd(&root, 4);
    insertAtPosition(&root, 2, 2);
    //Tesing out other operations
    displayForward(root);
    displayBackward(root);
    printf("\nFlipFlop\n");
    reverseList(&root);
    displayForward(root);
    displayBackward(root);

    printf("\nfound at Index: %d\n", searchList(root, 3));
    printf("found at Index: %d\n", searchList(root, 1));
    printf("found at Index: %d\n", searchList(root, 4));
    // //Deleting List using all delete functions
    deleteAtPosition(&root, 2);
    deleteFromBeginning(&root);
    deleteFromEnd(&root);
    displayForward(root);
    displayBackward(root);
    deleteFromBeginning(&root);
    displayForward(root);
    displayBackward(root);
    return 0;
}