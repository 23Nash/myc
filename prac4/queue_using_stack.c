#include <stdio.h>
#define MAX 10

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;


typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;


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


void initQueue(Queue* q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(Queue* q, int x) {
    push(&q->stack1, x);
    printf("Enqueued: %d\n", x);
}

int dequeue(Queue* q) {
    if (isStackEmpty(&q->stack2)) {
        while (!isStackEmpty(&q->stack1)) {
            int element = pop(&q->stack1);
            push(&q->stack2, element);
        }
    }

    if (isStackEmpty(&q->stack2)) {
        printf("Queue Underflow: Cannot dequeue\n");
        return -1;
    }

    return pop(&q->stack2);
}

void displayQueue(Queue* q) {
    if (isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    Stack tempStack = q->stack2;


    for (int i = tempStack.top; i >= 0; i--) {
        printf("%d ", tempStack.arr[i]);
    }


    for (int i = 0; i <= q->stack1.top; i++) {
        printf("%d ", q->stack1.arr[i]);
    }

    printf("\n");
}


int main() {
    Queue q;
    initQueue(&q);

    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;

            case 2:
                element = dequeue(&q);
                if (element != -1) {
                    printf("Dequeued: %d\n", element);
                }
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
