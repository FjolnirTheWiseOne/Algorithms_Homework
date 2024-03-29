#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int *array;
    int front, rear;
    int size;
} CircularQueue;

CircularQueue* createQueue() {
    CircularQueue *queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->array = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

int isEmpty(CircularQueue *queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue *queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

int peek(CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return queue->array[queue->front];
}

int getSize(CircularQueue *queue) {
    return queue->size;
}

int main() {
    CircularQueue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Front element: %d\n", peek(queue));

    printf("Dequeued item: %d\n", dequeue(queue));
    printf("Dequeued item: %d\n", dequeue(queue));

    printf("Front element after dequeue: %d\n", peek(queue));

    printf("Current size of queue: %d\n", getSize(queue));

    free(queue->array);
    free(queue);
    return 0;
}
