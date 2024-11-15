#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

typedef struct twoStacks {
    int arr[MAX]; 
    int top1;     
    int top2;     
} twoStacks;


void initStack(twoStacks* stacks) {
    stacks->top1 = -1; 
    stacks->top2 = MAX; 
}


int isFull(twoStacks* stacks) {
    return stacks->top1 + 1 == stacks->top2;
}


int isEmpty(int stack_number, twoStacks* stacks) {
    if (stack_number == 1)
        return stacks->top1 == -1;
    else if (stack_number == 2)
        return stacks->top2 == MAX;
    return 1;
}


void push(twoStacks* stacks, int x, int stack_number) {
    if (isFull(stacks)) {
        printf("Overflow: No space to push %d into stack %d\n", x, stack_number);
        return;
    }
    
    if (stack_number == 1) {
        stacks->arr[++(stacks->top1)] = x;  
    } else if (stack_number == 2) {
        stacks->arr[--(stacks->top2)] = x; 
    }
}


int pop(twoStacks* stacks, int stack_number) {
    if (isEmpty(stack_number, stacks)) {
        printf("Underflow: Stack %d is empty\n", stack_number);
        return -1; 
    }
    
    if (stack_number == 1) {
        return stacks->arr[(stacks->top1)--];  
    } else if (stack_number == 2) {
        return stacks->arr[(stacks->top2)++];  
    }
    return -1;
}


void displayStack1(twoStacks* stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 is empty\n");
        return;
    }
    
    printf("Stack 1 elements: ");
    for (int i = 0; i <= stacks->top1; i++) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}


void displayStack2(twoStacks* stacks) {
    if (stacks->top2 == MAX) {
        printf("Stack 2 is empty\n");
        return;
    }
    
    printf("Stack 2 elements: ");
    for (int i = MAX - 1; i >= stacks->top2; i--) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}


int main() {
    twoStacks stacks;
    initStack(&stacks);
    int choice, stack_number, element;

    do {
        printf("\nMenu:\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Display stack 1\n");
        printf("4. Display stack 2\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stack_number);
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&stacks, element, stack_number);
                break;

            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stack_number);
                element = pop(&stacks, stack_number);
                if (element != -1) {
                    printf("Popped element: %d\n", element);
                }
                break;

            case 3:
                displayStack1(&stacks);
                break;

            case 4:
                displayStack2(&stacks);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
