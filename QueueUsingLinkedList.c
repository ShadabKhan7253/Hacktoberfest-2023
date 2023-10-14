#include <Stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front=NULL;
struct Queue *rear=NULL;

void insert()
{
    struct Queue *pnode;
    pnode=(struct Queue*)malloc(sizeof(struct Queue));

    if(pnode==NULL)
        printf("\nMemory Overflow!");
    else
    {
        printf("\nEnter the data to be inserted: ");
        scanf("%d",&pnode->data);

        pnode->next=NULL;

        if(front==NULL && rear==NULL)
            front=rear=pnode;
        else
        {
            rear->next=pnode;
            rear=pnode;
        }
    }
}

void Remove()
{
    struct Queue *current;

    if(front==NULL)
        printf("\nQueue Underflow, cannot remove!");
    else
    {
        current=front;
        front=front->next;
        printf("Remove Data %d",current->data);
        free(current);
    }
}

void show()
{
    struct Queue *current;
    if (front==NULL)
        printf("\nNothing to show, as Queue is empty");
    else
    {
        current=front;
        printf("\nQueue element: ");
        
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current=current->next;
        }
    }
}

void main()
{
    int ch, element;
    clrscr();

    while (1)
    {
        printf("\n-----------------Menu---------------");
        printf("\n1. Insert \n2. Remove \n3. Show \n4. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            Remove();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice");
        } // End of Switch
    }     // End of While
} // End of Main
