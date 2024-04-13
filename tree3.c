#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to add a node to the binary tree
struct Node* addNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = addNode(root->left, data);
    else if (data > root->data)
        root->right = addNode(root->right, data);

    return root;
}

// Function to find the minimum node in a binary tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to perform Breadth First Traversal of the binary tree
void breadthFirstTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data, maxSize;
    printf("Enter the maximum size of the binary tree: ");
    scanf("%d", &maxSize);

    do {
        printf("\nBinary Tree Operations:\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Breadth First Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (maxSize <= 0) {
                    printf("Invalid maximum size\n");
                    break;
                }
                if (root == NULL) {
                    printf("Enter data for root node: ");
                    scanf("%d", &data);
                    root = addNode(root, data);
                    maxSize--;
                } else if (maxSize > 0) {
                    printf("Enter data for the node: ");
                    scanf("%d", &data);
                    root = addNode(root, data);
                    maxSize--;
                } else {
                    printf("Binary tree is full\n");
                }
                break;
            case 2:
                if (root == NULL) {
                    printf("Binary tree is empty\n");
                    break;
                }
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node with data %d deleted successfully\n", data);
                break;
            case 3:
                if (root == NULL) {
                    printf("Binary tree is empty\n");
                    break;
                }
                printf("Breadth First Traversal: ");
                breadthFirstTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
