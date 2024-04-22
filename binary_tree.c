#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binary_tree
{
    int val;
    struct binary_tree*left;
    struct binary_tree*right;
}tree;

tree*CreateNode(int);
tree*Insert(int,tree*);
tree*Display(tree*);
tree*Find_the_path(int,tree*);
tree*Delete(tree*);
void Queue(tree*);
tree* queue[50];
int front = -1, rear = -1;

int main(){
    tree*root = NULL;
    
    char key2[100];
    int a;
    char key1[100];
    while (strcmp(key1,"Start") != 0) {
        printf("Enter 'Start' for start the program\n");
        scanf("%[^\n]s", key1);
        if(strcmp(key1,"Start") == 0) {
            while(1) {
                printf("\t-:Menu:-\t\n");
                printf("Enter 'Insert (enter the number for insert)' for insert the value.\n");
                printf("Enter 'Display the tree' for display the tree.\n");
                // printf("Enter 'Display the path of (enter the number for find)' for display the tree.\n");
                // printf("Enter 'Delete (enter the number for delete)' for delete from tree.\n");
                printf("Enter 'Exit' for exit from the program\n");
                fflush(stdin);
                fgets(key2,100,stdin);
                key2[strcspn(key2, "\n")] = '\0';
                if(strncmp(key2,"Insert ",7) == 0) {
                    if (sscanf(key2 + 7, "%d", &a) == 1) {
                        printf("Insert %d into the tree\n", a);
                        if (root == NULL)
                        {
                            root = Insert(a,root);
                        }
                        else
                        {
                            root = Insert(a,root);
                        }
                    } else {
                        printf("Please enter a valid number to delete.\n");
                    }
                } else if(strcmp(key2,"Display the tree") == 0) {
                    if (root == NULL) {
                        printf("You have not planted any trees in this desert.\n");
                    } else {
                        Display(root);
                    }
                }
                //  else if(strncmp(key2,"Display the path of ", 20) == 0) {
                //     if (root == NULL) {
                //         printf("You have not planted any trees in this desert.\n");
                //     } else {
                //         if (sscanf(key2 + 20, "%d", &a) == 1) {
                //             printf("The path of %d is : ", a);
                //             Find_the_path(a,root);
                //             printf("\n");
                //         } else {
                //             printf("Please enter a valid number to delete.\n");
                //         }
                //     }
                // } else if(strncmp(key2,"Delete ",7) == 0) {
                //     if (root == NULL) {
                //         printf("You have not planted any trees in this desert.\n");
                //     } else {
                //         if (sscanf(key2 + 7, "%d", &a) == 1) {
                //             printf("Delete %d from tree\n", a);
                //             Delete(a,root);
                //         } else {
                //             printf("Please enter a valid number to delete.\n");
                //         }
                //     }
                // } 
                else if(strcmp(key2,"Exit") == 0) {
                    printf("Thank you.");
                    exit(EXIT_SUCCESS);
                } else {
                    printf("Enter the correct prompt\n");
                }
            }
        } else {
            printf("Please enter the correct key word\n");
        }
    }
    return 0;
}
void Queue(tree*num) {
    if(front = -1) {
        front = rear = 0;
        queue[front] = num;
    } else {
        queue[++front] = num;
    }
}

tree*Insert(int num,tree*root) {
    rear = 0;
    tree*m = root;
    if(m == NULL) {
        Queue(m);
        return CreateNode(num);
    } else {
        tree* tmp = queue[rear]; 
        if(tmp -> left != NULL && tmp -> left != NULL) {
            rear++;
            Insert(num,root);
        } else {
            if (tmp -> left == NULL) {
                Insert(num,tmp->left);
            } else if (tmp -> left == NULL) { 
                Insert(num, tmp->right);
            }
        }
    }
    return root;
}

tree* CreateNode(int value) {
    tree* newNode = (tree*)malloc(sizeof(tree));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree*Display(tree*root) {
    rear = 0;
    tree*tmp = queue[rear];
    printf("%d - ",tmp -> val);
    printf("%d - ",tmp -> left -> val);
    printf("%d - ",tmp -> right -> val);
    Display(queue[++rear]);
}