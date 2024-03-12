#include<stdio.h>
#define SIZE 40

// Assuming implicit declarations of exit and isdigit
extern int isdigit(int);
extern void exit(int);

int pop();
void push(int);
char postfix[SIZE];
int stack[SIZE],top=-1;

int main() // Corrected typo here
{
    int i, a, b, result, peval;
    char ch;

    printf("\nEnter a postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            b = pop();
            a = pop();
            switch (ch)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero.\n");
                        exit(-1);
                    }
                    result = a / b;
                    break;
            }
            push(result);
        }
    }
    peval = pop();
    printf("\nThe postfix evaluation is: %d\n", peval);
    return 0;
}

void push(int n)
{
    if (top < SIZE - 1)
    {
        stack[++top] = n;
    }
    else
    {
        printf("Stack is full\n");
        exit(-1);
    }
}

int pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack is empty\n");
        exit(-1);
    }
}
