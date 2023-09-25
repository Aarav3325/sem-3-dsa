#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 5

int queue[max];
int front = -1;
int rear = -1;

bool isEmpty()
{
    return front == -1 && rear == -1;
}

bool isFull()
{
    return rear == max - 1;
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
            rear = 0;
            queue[rear] = n;
        }
        else
        {
            rear++;
            queue[rear] = n;
        }
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
            front++;
        }
        printf("%d was removed\n", el);
    }
}

void display(){
    if(isEmpty()){
        printf("Underflow\n");
    }
    else{
        printf("Queue :\n");
        for(int i=front;i<=rear;i++){
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