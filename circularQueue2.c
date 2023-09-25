#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1 && rear == -1;
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

void enqueue()
{
    int n;
    if (isFull())
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter element\n");
        scanf("%d", &n);
        if (isEmpty())
        {
            front = 0;
        }

        rear = (rear + 1) % size;
        queue[rear] = n;
        printf("Item pushed\n");
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Underflow\n");
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
        printf("%d was removed\n", el);
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
        printf("Queue :\n");
        int i;
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
            enqueue();
            break;

        case 2:
            dequeue();
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