#include <stdio.h>
#define maxsize 5

int top = -1;
int stack[maxsize];

void push(int st[], int data)
{
    if (top == maxsize - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int pop(int st[])
{
    if (top == -1)
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

int peek(int st[])
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        int el = stack[top];
        return el;
    }
}

void display(int st[])
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

void main()
{
    // push(stack, 1);
    // push(stack, 2);
    // push(stack, 3);
    // push(stack, 4);

    // display(stack);

    int val;
    int op = 0;

    while (op != 5)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter option");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            scanf("%d", &val);
            push(stack, val);
            printf("Item pushed\n");
            break;

        case 2:
            val = pop(stack);
            if (val != -1)
            {
                printf("%d is deleted", val);
            }
            break;

        case 3:
            val = peek(stack);
            printf("Peek value is %d\n", val);
            break;

        case 4:
            display(stack);
            break;

        }
    }
}
