#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Define the stack structure
struct Stack {
    int data[MAX];
    int top;
};

// Function prototypes
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int peek(struct Stack *s);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void display(struct Stack *s);
void delete_n(struct Stack *s, int n);

int main() {
    struct Stack stack;
    stack.top = -1;  // Initialize the stack's top

    int choice, value, ele;

    do {
        // Display menu
        printf("\n\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("6. delete n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                value = pop(&stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;

            case 4:
                display(&stack);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            case 6:
                printf("enter element u want to remove:");
                scanf("%d", &ele);
                delete_n(&stack, ele);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Push function to add element to the stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->data[s->top] = value;
    printf("%d pushed onto stack\n", value);
}

// Pop function to remove element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

// Peek function to view the top element of the stack
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->data[s->top];
}

// Check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Display function to show all elements of the stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

//delete nth element
void delete_n(struct Stack *s, int n){
    struct Stack temp;
    temp.top = -1;
    int flag = 0;
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return;
    }

    while (s->data[s->top] != n)
    {
       push(&temp,pop(s)); 
    }
    pop(s);
    printf("Deleted : %d\n",&n);
    while (!isEmpty(&temp))
    {
        push(s,pop(&temp));
    }
    

}