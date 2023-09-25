#include <stdio.h>
#include <stdbool.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return rear == max - 1;
}

void push()
{
    if (isFull())
    {
        printf("Overflow");
    }
     int n;
     printf("Enetr element");
     scanf("%d", &n);
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        queue[rear] = n;
    }
    else
    {
        rear++;
        queue[rear] = n;
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
        int el = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
        return el;
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
        printf("Queue :\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
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
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid Operation");
            break;
        }
    }
}