#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* elements;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->elements = (int*) malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int element) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->elements[++stack->top] = element;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->elements[stack->top--];
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue* queue, int element) {
    push(queue->stack1, element);
}

int dequeue(Queue* queue) {
    
    if (queue->stack2->top == -1) {
        while (queue->stack1->top != -1) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main() {
    Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    return 0;
}

/*
Dequeued element: 1
Dequeued element: 2
Dequeued element: 3
Dequeued element: 4
Dequeued element: 5
/*