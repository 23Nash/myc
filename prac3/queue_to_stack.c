#include <stdio.h>
#define MAX 10

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;


typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

int isQueueFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int x) {
    if (isQueueFull(q)) {
        printf("Queue Overflow: Cannot enqueue %d\n", x);
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = x;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue Underflow: Cannot dequeue\n");
        return -1;
    }
    int element = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return element;
}


void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements front to rear: ");
    for (int i = q->rear; i >= q->front; i--) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

int isStackFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int x) {
    if (isStackFull(s)) {
        printf("Stack Overflow: Cannot push %d\n", x);
        return;
    }
    s->arr[++(s->top)] = x;
}

int pop(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack Underflow: Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}


void transferQueueToStack(Queue* q, Stack* s) {
    printf("Transferring elements from Queue to Stack...\n");
    while (!isQueueEmpty(q)) {
        int element = dequeue(q);
        push(s, element);
    }
    printf("Transfer complete.\n");
}


void displayStack(Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements  ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


int main() {
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);


    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue elements have been enqueued.\n");
    displayQueue(&q);


    transferQueueToStack(&q, &s);


    displayStack(&s);

    return 0;
}
