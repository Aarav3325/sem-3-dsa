#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return rear == -1;
}

bool isFull()
{
    if (front == 0 && rear == size - 1)
    {
        return true;
    }
    if (front == rear + 1)
    {
        return true;
    }
    return false;
}

void push()
{
    if (isFull())
    {
        printf("'Overflow");
    }
    else
    {
        if (isEmpty())
        {
            front = 0;
        }
        int n;
        printf("Enter Element\n");
        scanf("%d", &n);

        rear = (rear + 1) % size;
        queue[rear] = n;
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
        int el = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        return el;
    }
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Underflow");
    }
    else
    {
        printf("Queue :\n");
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[i]);
    }
}

void main()
{
    int op = 0;

    while (op != 4)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

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