#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
struct CircularQueue 
{
    int items[MAX_SIZE];
    int front, rear;
};

struct CircularQueue* createCircularQueue() 
{
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct CircularQueue* queue) 
{
    return (queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1);
}

int isEmpty(struct CircularQueue* queue) 
{
    return queue->front == -1;
}

void enqueue(struct CircularQueue* queue, int value) 
{
    if (isFull(queue)) 
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct CircularQueue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int removedValue = queue->items[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    printf("%d dequeued from the queue.\n", removedValue);
    return removedValue;
}

void display(struct CircularQueue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->items[i]);
    printf("%d\n", queue->items[i]);
}

int main() 
{
    struct CircularQueue* queue = createCircularQueue();
    int choice, value;
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
