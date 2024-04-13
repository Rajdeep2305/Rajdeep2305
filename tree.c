#include <stdio.h>
#include <stdlib.h>

struct tree {
    int val;
    struct tree* left;
    struct tree* right;
};

struct tree* createNode(int value);
struct tree* insert(struct tree* root, int value);
void inorderTraversal(struct tree* root);
void preorderTraversal(struct tree* root) ;
void postorderTraversal(struct tree* root);
struct tree* deletion(struct tree* root, int a);

int main() {
    struct tree*root = NULL;
    char pass;
    while(pass != 's' || pass != 'S')
    {
        printf("Enter 's' or 'S' for start the program: ");
        pass = getchar();
        if(pass == 's' || pass == 'S')
        {
            if(root == NULL)
            {
                printf("Enter the value of Root: ");
                int a;
                scanf("%d",&a);
                root = insert(root,a);
            }
            printf("\n");
            while(1)
            {
                printf("Enter 'i' or 'I' for insert value. \n");
                printf("Enter 'a' or 'A' for inorder the program. \n");
                printf("Enter 'b' or 'B' for preorder the program. \n");
                printf("Enter 'c' or 'C' for postorder the program. \n");
                printf("Enter 'd' or 'D' for deletion.\n");
                printf("Enter 'x' or 'X' for exit the program. \n");
                char key;
                key = getchar();
                key = getchar();
                switch(key)
                {
                    case 'i':
                    case 'I':
                    {
                        if(root == NULL)
                        {
                            printf("Enter the value of Root: ");
                            int a;
                            scanf("%d",&a);
                            root = insert(root,a);
                        }
                        else
                        {
                            printf("Enter the value: ");
                            int a;
                            scanf("%d",&a);
                            root = insert(root,a);
                        }
                        break;
                    }
                    case 'a':
                    case 'A':
                    {
                        if(root == NULL)
                        {
                            printf("Your tree is empty");
                        }
                        else
                        {
                            printf("Inorder Traversal: ");
                            inorderTraversal(root);
                            printf("\n");
                            break;
                        }
                        break;
                    }
                    case 'b':
                    case 'B':
                    {
                        if(root == NULL)
                        {
                            printf("Your tree is empty");
                        }
                        else
                        {
                            printf("Preorder Traversal: ");
                            preorderTraversal(root);
                            printf("\n");
                        }
                        break;
                    }
                    case 'c':
                    case 'C':
                    {
                        if(root == NULL)
                        {
                            printf("Your tree is empty");
                        }
                        else
                        {
                            printf("Postorder Traversal: ");
                            postorderTraversal(root);
                            printf("\n");
                        }
                        break;
                    }
                    case 'd':
                    case 'D':
                    {
                        if(root == NULL)
                        {
                            printf("Your tree is empty");
                        }
                        else
                        {
                            printf("Enter the number which you want to delete :");
                            int z;
                            scanf("%d",&z);
                            root = deletion(root,z);
                        }
                        break;
                    }
                    case 'x':
                    case 'X':
                    {
                        printf("Good bye.");
                        exit(EXIT_SUCCESS);
                        break;
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("Enter the current password\n");
        }
        scanf("%c",&pass);
    }   
    return 0;
}

struct tree* createNode(int value) 
{
    struct tree* newNode = (struct tree*)malloc(sizeof(struct tree));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct tree* insert(struct tree* root, int value) 
{
    if (root == NULL) 
    {
        return createNode(value);
    }
    if (value < root->val) 
    {
        root->left = insert(root->left, value);
    } 
    else if (value > root->val) 
    {
        root->right = insert(root->right, value);
    }
    else 
    {
        printf("Please Give a uniq value\n");
    }
    return root;
}

void inorderTraversal(struct tree* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct tree* root) 
{
    if (root != NULL) 
    {
        printf("%d ", root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct tree* root) 
{
    if (root != NULL) 
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->val);
    }
}

struct tree* deletion(struct tree* root, int a)
{
    int r;
    if(root == NULL)
    {
        printf("This is not available in this tree. \n");
    }
    else
    {
        if(root -> val == a)
        {
            if(root -> left == NULL && root -> right == NULL)
            {
                free(root);
                root = NULL;
            }
            else
            {
                r = root -> val;
                if(root -> right != NULL && root -> left != NULL)
                {
                    root-> val = root -> left -> val;
                    root -> left -> val = r;
                    root -> left = deletion(root -> left, a);
                }
                else if(root -> left == NULL)
                {
                    root-> val = root -> right -> val;
                    root -> right -> val = r;
                    root -> right = deletion(root -> right, a);
                }
                else
                {
                    root-> val = root -> left -> val;
                    root -> left -> val = r;
                    root -> left = deletion(root -> left, a);
                }
            }
        }
        else
        {
            if (a < root->val) 
            {
                root -> left = deletion(root -> left, a);
            } 
            else if (a > root->val) 
            {
                root -> right = deletion(root->right, a);
            }
        }
    }
    return root;
}