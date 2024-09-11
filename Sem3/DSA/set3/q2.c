#include <stdio.h>
#include <stdlib.h>

// Definition of the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the index of a value in the in-order array
int search(int inOrder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to construct the binary tree from preOrder and inOrder traversals
struct Node* buildTree(int inOrder[], int preOrder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    // The current element in preOrder is the root of this subtree
    struct Node* root = createNode(preOrder[*preIndex]);
    (*preIndex)++;

    // If the node has no children, return the node
    if (inStart == inEnd) {
        return root;
    }

    // Find the index of this node in the inOrder array
    int inIndex = search(inOrder, inStart, inEnd, root->data);

    // Recursively build the left and right subtrees
    root->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// Function to perform pre-order traversal of the binary tree
void preOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;

    // Input the number of nodes
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int inOrder[n], preOrder[n];
    
    // Input the in-order traversal
    printf("Enter the in-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }

    // Input the pre-order traversal
    printf("Enter the pre-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preOrder[i]);
    }

    // Initialize preIndex to 0
    int preIndex = 0;

    // Build the tree
    struct Node* root = buildTree(inOrder, preOrder, 0, n - 1, &preIndex);

    // Display the in-order traversal of the constructed tree
    printf("In-order traversal of the constructed tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Display the pre-order traversal of the constructed tree
    printf("Pre-order traversal of the constructed tree: ");
    preOrderTraversal(root);
    printf("\n");
    
    printf("Post-order traversal of the constructed tree: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
