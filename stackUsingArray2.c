#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 3

int stack[max];
int top = -1;

bool isEmpty()
{
    return top == -1;
}

bool isFull(){
    return top == max -1;
}

void push()
{
    if (isFull())
    {
        printf("Overflow");
    }
    else
    {
        int n;
        printf("Enter data\n");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("Item pushed\n");
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("Underflow");
        return -1;
    }
    else
    {
        int el = stack[top];
        top--;
        return el;
    }
}

void peep()
{
    int i;
    if (isEmpty())
    {
        printf("Undeflow");
    }
    else
    {
        printf("Enter position\n");
        scanf("%d", &i);
        printf("%d is at postion %d", stack[top - i + 1], i);
    }
}

void change()
{
    int index;
    int val;
    printf("Enter index:\n");
    scanf("%d", &index);
    printf("Enter value\n");
    scanf("%d", &val);
    if (isEmpty())
    {
        printf("underflow");
    }
    else
    {
        if (index <= -1 || index > max)
        {
            printf("Underflow\n");
        }
        else
        {
            stack[top - index + 1] = val;
            printf("Item changed\n");
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Underflow");
    }
    else
    {
        printf("Stack\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

void main()
{
    int op;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            push();
            break;

        case 2:
            printf("%d was poped", pop());
            break;

        case 3:
            peep();
            break;

        case 4:
            change();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Invalid Operation");
            break;
        }
    }
}
