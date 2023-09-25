#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

bool isEmpty()
{
    return head == NULL;
}

void addFirst()
{
    int n;
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node *));
    if (newNode == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter element\n");
        scanf("%d", &n);
        newNode->data = n;
        newNode->next = head;
        head = newNode;
        printf("Item inserted\n");
    }
}

void addLast()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter element\n");
    scanf("%d", &n);
    newNode->data = n;

    if (isEmpty())
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {

        struct Node *currNode = head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
        newNode->next = NULL;

        printf("Item inserted\n");
    }
}
void deleteFirst()
{
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {
        int el = head->data;
        head = head->next;
        printf("%d is deleted\n", el);
    }
}

void deleteLast()
{
    if (isEmpty())
    {
        printf("Underflow\n");
    }
    else
    {

        if (head->next == NULL)
        {
            head = NULL;
            free(head);
        }

        else
        {
            struct Node *secondLast = head;
            struct Node *lastNode = head->next;
            while (lastNode->next != NULL)
            {
                secondLast = secondLast->next;
                lastNode = lastNode->next;
            }
            int el = lastNode->data;
            secondLast->next = NULL;
            free(lastNode);
            printf("%d was deleted\n", el);
        }
    }
}

void insertAt()
{
    int p;
    int el;
    int i = 1;
    printf("Enter position\n");
    scanf("%d", &p);
    printf("Enter element\n");
    scanf("%d", &el);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = el;

    struct Node *currNode = head;
    while (i < p - 1)
    {
        currNode = currNode->next;
        i++;
    }
    newNode->next = currNode->next;
    currNode->next = newNode;
}

void deleteAt()
{
    int i = 1;
    int p;
    printf("Enter position\n");
    scanf("%d", &p);

    if (isEmpty())
    {
        printf("Underflow");
    }
    else
    {
        struct Node *previous = head;
        while (i < p - 1)
        {
            previous = previous->next;
            i++;
        }
        previous->next = previous->next->next;
    }
}

void sortedInsert()
{
    int n;
    printf("Enter element\n");
    scanf("%d", &n);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = n;
    if (isEmpty())
    {
        newNode->next = head;
        head = newNode;
    }
    else if (head->data > newNode->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        struct Node *currNode = head;
        while (currNode->next != NULL && currNode->next->data < newNode->data)
        {
            currNode = currNode->next;
        }
        newNode->next = currNode->next;
        currNode->next = newNode;
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

    while (op != 9)
    {
        printf("1. Add First\n");
        printf("2. Display\n");
        printf("3. Add Last\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Insert At\n");
        printf("7. Delete At\n");
        printf("8. Sorted Insert\n");
        printf("9. Exit\n");

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
            addLast();
            break;

        case 4:
            deleteFirst();
            break;

        case 5:
            deleteLast();
            break;

        case 6:
            insertAt();
            break;

        case 7:
            deleteAt();
            break;

        case 8:
            sortedInsert();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("Invalid Operation");
            break;
        }
    }
}