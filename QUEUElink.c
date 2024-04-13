#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addToFront(struct Node** front, struct Node** rear, int data) 
{
    struct Node* newNode = createNode(data);
    if (*front == NULL) 
    {
        *front = *rear = newNode;
    } 
    else 
    {
        newNode->next = *front;
        (*front)->prev = newNode;
        *front = newNode;
    }
    printf("Added %d to the front of the deque.\n", data);
}

void addToRear(struct Node** front, struct Node** rear, int data) 
{
    struct Node* newNode = createNode(data);
    if (*rear == NULL) 
    {
        *front = *rear = newNode;
    } 
    else 
    {
        (*rear)->next = newNode;
        newNode->prev = *rear;
        *rear = newNode;
    }
    printf("Added %d to the rear of the deque.\n", data);
}

void deleteFromFront(struct Node** front, struct Node** rear) 
{
    if (*front == NULL) 
    {
        printf("Deque is empty, cannot delete from front.\n");
    } 
    else 
    {
        struct Node* temp = *front;
        *front = (*front)->next;
        if (*front == NULL) 
        {
            *rear = NULL;
        } 
        else 
        {
            (*front)->prev = NULL;
        }
        printf("Deleted %d from the front of the deque.\n", temp->data);
        free(temp);
    }
}

void deleteFromRear(struct Node** front, struct Node** rear) 
{
    if (*rear == NULL) 
    {
        printf("Deque is empty, cannot delete from rear.\n");
    }
    else 
    {
        struct Node* temp = *rear;
        *rear = (*rear)->prev;
        if (*rear == NULL) 
        {
            *front = NULL;
        } 
        else 
        {
            (*rear)->next = NULL;
        }
        printf("Deleted %d from the rear of the deque.\n", temp->data);
        free(temp);
    }
}

void display(struct Node* front) 
{
    if (front == NULL) 
    {
        printf("Deque is empty.\n");
    } 
    else 
    {
        printf("Deque elements: ");
        while (front != NULL) {
            printf("%d ", front->data);
            front = front->next;
        }
        printf("\n");
    }
}

int main() 
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int maxSize;
    int choice, data;

    printf("Enter the maximum size of the deque: ");
    scanf("%d", &maxSize);

    do {
        printf("\n--- Deque Menu ---\n");
        printf("1. Add to Front\n");
        printf("2. Add to Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                if (maxSize <= 0 || maxSize > 0) 
                {
                    printf("Enter data to add to front: ");
                    scanf("%d", &data);
                    addToFront(&front, &rear, data);
                    break;
                }
            case 2:
                if (maxSize <= 0 || maxSize > 0) 
                {
                    printf("Enter data to add to rear: ");
                    scanf("%d", &data);
                    addToRear(&front, &rear, data);
                    break;
                }
            case 3:
                deleteFromFront(&front, &rear);
                break;
            case 4:
                deleteFromRear(&front, &rear);
                break;
            case 5:
                display(front);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
