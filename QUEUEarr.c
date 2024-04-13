#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int front, rear;
    int capacity;
    int* array;
};

struct Deque* createDeque(int capacity) 
{
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = 0;
    deque->array = (int*)malloc(deque->capacity * sizeof(int));
    return deque;
}

int isFull(struct Deque* deque) 
{
    return ((deque->front == 0 && deque->rear == deque->capacity - 1) || deque->front == deque->rear + 1);
}

int isEmpty(struct Deque* deque) 
{
    return (deque->front == -1);
}

void addToFront(struct Deque* deque, int key) 
{
    if (isFull(deque)) 
    {
        printf("Deque Overflow\n");
        return;
    }
    if (deque->front == -1) 
    {
        deque->front = 0;
        deque->rear = 0;
    } 
    else if (deque->front == 0)
        deque->front = deque->capacity - 1;
    else
        deque->front = deque->front - 1;

    deque->array[deque->front] = key;
    printf("Added %d to the front of deque\n", key);
}

void addToRear(struct Deque* deque, int key) 
{
    if (isFull(deque)) 
    {
        printf("Deque Overflow\n");
        return;
    }
    if (deque->front == -1) 
    {
        deque->front = 0;
        deque->rear = 0;
    } 
    else if (deque->rear == deque->capacity - 1)
        deque->rear = 0;
    else
        deque->rear = deque->rear + 1;

    deque->array[deque->rear] = key;
    printf("Added %d to the rear of deque\n", key);
}

void deleteFromFront(struct Deque* deque) 
{
    if (isEmpty(deque))
    {
        printf("Deque Underflow\n");
        return;
    }

    if (deque->front == deque->rear) 
    {
        printf("Deleted %d from the front of deque\n", deque->array[deque->front]);
        deque->front = -1;
        deque->rear = -1;
    } 
    else if (deque->front == deque->capacity - 1)
        deque->front = 0;
    else
        deque->front = deque->front + 1;
}

void deleteFromRear(struct Deque* deque)
{
    if (isEmpty(deque)) 
    {
        printf("Deque Underflow\n");
        return;
    }
    if (deque->front == deque->rear) 
    {
        printf("Deleted %d from the rear of deque\n", deque->array[deque->rear]);
        deque->front = -1;
        deque->rear = -1;
    } 
    else if (deque->rear == 0)
        deque->rear = deque->capacity - 1;
    else
        deque->rear = deque->rear - 1;
}

void display(struct Deque* deque) 
{
    if (isEmpty(deque))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements are: ");
    int i;
    if (deque->front <= deque->rear) 
    {
        for (i = deque->front; i <= deque->rear; i++)
            printf("%d ", deque->array[i]);
    } 
    else 
    {
        for (i = deque->front; i < deque->capacity; i++)
            printf("%d ", deque->array[i]);
        for (i = 0; i <= deque->rear; i++)
            printf("%d ", deque->array[i]);
    }
    printf("\n");
}

void displayMenu() 
{
    printf("\nDeque Operations Menu:\n");
    printf("1. Add to Front\n");
    printf("2. Add to Rear\n");
    printf("3. Delete from Front\n");
    printf("4. Delete from Rear\n");
    printf("5. Display Deque\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int capacity, choice, data;
    printf("Enter the maximum size of the deque: ");
    scanf("%d", &capacity);

    struct Deque* deque = createDeque(capacity);

    while (1) 
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to add to the front: ");
                scanf("%d", &data);
                addToFront(deque, data);
                break;
            case 2:
                printf("Enter the element to add to the rear: ");
                scanf("%d", &data);
                addToRear(deque, data);
                break;
            case 3:
                deleteFromFront(deque);
                break;
            case 4:
                deleteFromRear(deque);
                break;
            case 5:
                display(deque);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
