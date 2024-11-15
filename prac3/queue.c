#include <stdio.h>
#define MAX 100  


typedef struct Queue {
    int arr[MAX];  
    int front;     
    int rear;      
} Queue;


void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(Queue* q) {
    return q->front == -1;
}


int isFull(Queue* q) {
    return q->rear == MAX - 1;
}


void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        printf("Queue Overflow: Cannot enqueue %d\n", x);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  
    }
    q->arr[++(q->rear)] = x;
    printf("Enqueued: %d\n", x);
}


int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow: Cannot dequeue\n");
        return -1;
    }
    int dequeuedElement = q->arr[q->front];
    if (q->front == q->rear) {

        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedElement;
}


void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
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
                display(&q);
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
