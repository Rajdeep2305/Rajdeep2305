#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
    int maxSize;
    int size;
};

struct Queue* createQueue(int maxSize) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    queue->maxSize = maxSize;
    queue->size = 0;
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->maxSize);
}

int isEmpty(struct Queue* queue) 
{
    return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data) 
{
    if (isFull(queue)) 
    {
        printf("Queue is full. Enqueue operation failed.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) 
    {
        queue->front = newNode;
    } 
    else 
    {
        queue->rear->next = newNode;
    }

    queue->rear = newNode;
    queue->size++;

    printf("Enqueued: %d\n", data);
}

int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty. Dequeue operation failed.\n");
        return -1;
    }

    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) 
    {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    printf("Dequeued: %d\n", data);
    return data;
}

void displayMenu() 
{
    printf("\n----- Circular Queue Menu -----\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("-------------------------------\n");
}

int main() 
{
    int choice, data, maxSize;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);

    struct Queue* queue = createQueue(maxSize);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
