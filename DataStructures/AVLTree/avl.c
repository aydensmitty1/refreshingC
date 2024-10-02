typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Core operations
AVLNode* insertAVL(AVLNode* root, int data);
AVLNode* deleteAVL(AVLNode* root, int data);
AVLNode* searchAVL(AVLNode* root, int target);

// Traversal functions
void inorderTraversal(AVLNode* root);
void preorderTraversal(AVLNode* root);
void postorderTraversal(AVLNode* root);

// Utility functions
int getHeight(AVLNode* node);
int getBalanceFactor(AVLNode* node);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
