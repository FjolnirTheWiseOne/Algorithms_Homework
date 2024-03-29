#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}


void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->items[++stack->top] = value;
}


int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}


int top(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}

void display(Stack *stack) {
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}


int size(Stack *stack) {
    return stack->top + 1;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack); 

    printf("Top element: %d\n", top(&stack)); 

    printf("Popped element: %d\n", pop(&stack)); 

    display(&stack); 

    printf("Size of stack: %d\n", size(&stack)); 

    return 0;
}
