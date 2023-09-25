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

bool isFull()
{
    return top == max - 1;
}

void push()
{
    if (isFull())
    {
        printf("Underflow\n");
    }
    else
    {
        int n;
        printf("Enter element\n");
        scanf("%d", &n);
        top++;
        stack[top] = n;
        printf("Item pushed\n");
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
        int el = stack[top];
        top--;
        printf("%d was poped\n", el);
    }
}

void peep()
{
    int i;
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Enter position\n");
        scanf("%d", &i);
        printf("%d is at position %d\n", stack[top-i+1], i);
    }
}

void change()
{
    int i;
    int el;
    printf("Enter position\n");
    scanf("%d", &i);
    printf("Enter element\n");
    scanf("%d", &el);
    if (isEmpty())
    {
        printf("Underflow");
    }
    else
    {
        if (top - i + 1 <= 0 || top - i + 1 >= max)
        {
            printf("Invalid position");
        }
        else
        {
            stack[top - i + 1] = el;
            printf("Element changed\n");
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Underflow\n");
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
            pop();
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
