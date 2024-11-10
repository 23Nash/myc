#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define MAX_SIZE 100


struct Stack 
{
    int top;
    char items[MAX_SIZE];
};


struct Stack* createStack()
 {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}


int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}


void push(struct Stack* stack, char item)
 {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}


char pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}


int isOperator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


int precedence(char c) 
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}


void infixToPostfix(char* infix, char* postfix) 
{
    struct Stack* stack = createStack();
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]) || isalpha(infix[i])) 
        {
            postfix[j++] = infix[i];
        } 
        else if (infix[i] == '(') 
        {
            push(stack, infix[i]);
        }
         else if (infix[i] == ')')
         {
            while (!isEmpty(stack) && stack->items[stack->top] != '(')
             {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && stack->items[stack->top] == '(') 
            {
                pop(stack);
            } 
            else 
            {
                printf("Invalid expression\n");
                return;
            }
        } 
        else if (isOperator(infix[i]))
         {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(stack->items[stack->top])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        }
        i++;
    }

    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[MAX_SIZE];

    printf("Enter a Infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
