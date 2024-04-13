#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) 
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) 
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) 
{
    if (isFull(queue)) 
    {
        printf("Queue is full, cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue.\n", item);
}

int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty, cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int main() 
{
    int maxSize, choice, element;
    
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);
    
    struct Queue* queue = createQueue(maxSize);

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                element = dequeue(queue);
                if (element != -1)
                    printf("Dequeued element: %d\n", element);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
