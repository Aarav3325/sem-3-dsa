#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void addFirst(){
    int n;
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node*));
    if(newNode == NULL){
        printf("Overflow\n");
    }
    else{
        printf("Enter element\n");
        scanf("%d",&n);
        newNode->data = n;
        newNode->next = head;
        head = newNode;
        printf("Item inserted\n");
    }
}

void display(){
    if(head == NULL){
        printf("Underflow");
    }
    else{
        struct Node *currNode = head;
        while (currNode != NULL)
        {
            printf("%d -> ", currNode->data);
            currNode = currNode->next;
        }
        printf("NULL\n");
        
    }
}

void main()
{
    int op = 0;

    while (op != 3)
    {
        printf("1. Add First\n");
        printf("2. Display\n");
        printf("3. Exit\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            addFirst();
            break;

        case 2:
            display();
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid Operation");
            break;
        }
    }
}