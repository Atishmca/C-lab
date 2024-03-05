#include<stdio.h>
#define MAX 3
int top=1,stack[MAX];
void push();
void pop();
void display();

void main()
{
    int ch;
    while(1)
    {
        printf("\n 1.push\n 2.pop\n 3.display\n 4.exit");
        printf("enter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push();
                 break;
            case 2: pop();
                 break;
            case 3: display();
                 break;
            case 4: return;
            default: printf("\n wrong choice");     
        }
    }
}
void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("stack is overflow");
        return;
    }
    printf("\n enter the stack element");
    scanf("%d",&item);
    top=top+1;
    stack[top]=item;
}
void pop()
{
    int elem;
    if(top==-1)
    {
        printf("stack is underflow");
        return;
    }
    elem=stack[top--];
    printf("\n deletion element=%d",elem);
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n stack is empty");
        return;
    }
    for(i=0;i<=top;i++)
    {
        printf("%d\n",stack[i]);
    }
    
}