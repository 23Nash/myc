#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 25

void push(int);
int pop();
void display();
int s[MAX] = {0};
int top = -1;

void main()
{
    char postfix[MAX] = {'\0'}, ele;
    int i, num1, num2, ans;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Postfix expression: %s\n", postfix);

    i = 0;
    while (i < strlen(postfix))
    {
        ele = postfix[i];

        if (isdigit(ele))
        {
            push(ele - '0');
        }
        else
        {
            num1 = pop();
            num2 = pop();

            switch (ele)
            {
                case '^':
                    ans = pow(num2, num1);
                    break;
                case '/':
                    ans = num2 / num1;
                    break;
                case '*':
                    ans = num2 * num1;
                    break;
                case '+':
                    ans = num2 + num1;
                    break;
                case '-':
                    ans = num2 - num1;
                    break;
                default:
                    printf("Invalid operator encountered.\n");
                    return;
            }
            push(ans);
        }
        display();
        i++;
    }
    printf("Answer = %d\n", pop());
}

void push(int ele)
{
    if (top == MAX - 1)
        printf("Stack is full\n");
    else
    {
        top++;
        s[top] = ele;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return -1;  
    }
    else
    {
        int ch = s[top];
        top--;
        return ch;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack = ");
        for (int i = 0; i <= top; i++)
            printf("%d ", s[i]);
        printf("\n");
    }
}
 /* Output:
Enter postfix expression: 89*6/7+9*7/3
Postfix expression: 89*6/7+9*7/3
Stack = 8
Stack = 8 9
Stack = 72
Stack = 72 6
Stack = 12
Stack = 12 7
Stack = 19
Stack = 19 9
Stack = 171
Stack = 171 7
Stack = 24
Stack = 24 3
Answer = 3
*/