#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
int stackSize = 0;
int currentSize = 0;

void push(int a) {
    if (currentSize == stackSize) {
        printf("Stack overflow.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = a;
    newNode->next = top;
    top = newNode;
    currentSize++;
}

void pop() {
    if (top == NULL) {
        printf("Underflow.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("Pop done.\n");
    currentSize--;
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d\n", top->data);
}

int main() {
    char key;
    while (1) {
        printf("Enter 's' or 'S' to start the program: ");
        scanf(" %c", &key);
        if (key == 's' || key == 'S') {
            printf("Enter the size of stack: ");
            scanf("%d", &stackSize);
            while (1) {
                printf("Enter 'e' or 'E' for Push.\nEnter 'd' or 'D' for Pop.\nEnter 'p' or 'P' for Peek.\nEnter 'x' or 'X' for exit.\n");
                char pass;
                scanf(" %c", &pass);
                switch (pass) {
                    case 'e':
                    case 'E': {
                        if(currentSize == stackSize)
                        {
                            printf("Stack overflow.\n");
                        }
                        else
                        {
                            printf("Enter the element for push");
                            int a;
                            scanf("%d",&a);
                            push(a);   
                        }
                        break;
                    }
                    case 'd':
                    case 'D': {
                        pop();
                        break;
                    }
                    case 'p':
                    case 'P': {
                        peek();
                        break;
                    }
                    case 'x':
                    case 'X': {
                        while (top != NULL) {
                            pop();
                        }
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    default: {
                        printf("Invalid option.\n");
                        break;
                    }
                }
            }
        } else {
            printf("Enter the correct key.\n");
        }
    }
    return 0;
}
