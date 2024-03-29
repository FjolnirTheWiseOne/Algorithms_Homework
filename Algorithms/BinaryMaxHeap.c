#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap() {
    MaxHeap *heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->array = (int*)malloc(MAX_SIZE * sizeof(int));
    heap->size = 0;
    heap->capacity = MAX_SIZE;
    return heap;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(MaxHeap *heap, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);
        maxHeapify(heap, largest);
    }
}

void insert(MaxHeap *heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow, cannot insert element.\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = key;

    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow, cannot extract max.\n");
        return -1;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);
    return max;
}

int peek(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty, cannot peek.\n");
        return -1;
    }
    return heap->array[0];
}

void increaseKey(MaxHeap *heap, int i, int newKey) {
    if (newKey < heap->array[i]) {
        printf("New key is smaller than current key, cannot increase.\n");
        return;
    }
    heap->array[i] = newKey;
    while (i != 0 && heap->array[parent(i)] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[parent(i)]);
        i = parent(i);
    }
}

int main() {
    MaxHeap *heap = createHeap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 25);

    printf("Max element: %d\n", peek(heap));

    printf("Extracted max element: %d\n", extractMax(heap));

    printf("Max element after extraction: %d\n", peek(heap));

    increaseKey(heap, 2, 40);

    printf("Max element after increaseKey: %d\n", peek(heap));

    free(heap->array);
    free(heap);
    return 0;
}
