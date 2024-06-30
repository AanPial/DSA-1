#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
};
struct node *head;
void printList()
{
    if(head==NULL)
    {
        printf("\nThe linked list is currently empty.\n");
        return;
    }
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\nEND for now\n");
}
void insertHead(int num)
{
    struct node *newItem;
    newItem=(struct node*)malloc(sizeof(struct node));
    newItem->value=num;
    newItem->next=head;
    head=newItem;
}
void insertTail(int num)
{
    struct node *newItem;
    newItem=(struct node*)malloc(sizeof(struct node));
    newItem->value = num;
    newItem->next = NULL;

    struct node*prev=head;
    while(prev->next != NULL)
    {
        prev=prev->next=newItem;
    }
}
int main()
{
    int n;
    while (1)
    {
        printf("\nMenu : \n1.Insert first\n2.Insert Last\n3.Print\n0.Exit\n");
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        else if(n==1)
        {
            int m;
            printf("Enter number (insert head): ");
            scanf("%d",&m);
            insertHead(m);
        }
        else if(n==2)
        {
            int m;
            printf("Enter number (insert tail): ");
            scanf("%d",&m);
            insertTail(m);
        }
        else if(n==3)
        {
            printf("Linked list is : ");
            printList();
        }

    }
    
}
