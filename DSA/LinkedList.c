#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *head;
void insertFirst(int x)
{
    struct node *newItem;
    newItem = (struct node *)malloc(sizeof(struct node));
    newItem->value = x;
    newItem->next = NULL;
    newItem->next = head;
    head = newItem;
}
void print()
{
    if (head == NULL)
    {
        printf("Linked list is empty.");
        return;
    }
    printf("The current Linked List is : ");
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}
void insertLast(int x) {
    struct node *newItem = (struct node*)malloc(sizeof(struct node));
    newItem->value = x;
    newItem->next = NULL;

    if (head == NULL) {
        head = newItem;
    } else {
        struct node *prev;
        prev = head;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        prev->next = newItem;
    }
}
void insertMid1(int newval,int n)
{
    struct node*newitem;
    newitem = (struct node*)malloc(sizeof(struct node));
    newitem->value=newval;
    struct node* prev=head;
    for(int i=0;i<n-1;i++)
    {
        prev=prev->next;
    }
    newitem->next=prev->next;
    prev->next=newitem;
}
void insertMid2(int newval,int n)
{
    struct node*newitem;
    newitem = (struct node*)malloc(sizeof(struct node));
    newitem->value=newval;
    struct node* prev=head;
    while (prev != NULL && prev->value != n) {
        prev = prev->next;
    }
    if (prev != NULL) {
        newitem->next = prev->next;
        prev->next = newitem;
    } else {
        printf("Value doesn't Exist!");
    }
}
int main()
{
    int choice, newval,i;
    while (1)
    {
    err:
        printf("\nOptions : \n1.Insert first.\n2.Insert Last\n3.Insert middle(According to index)\n4.Insert middle(According to value)\n5.Print\n0.Exit\n");
        printf("Enter : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter value for insert first : ");
            scanf("%d", &newval);
            insertFirst(newval);
        }
        else if (choice == 2)
        {
            printf("Enter value for Last insert : ");
            scanf("%d", &newval);
            insertLast(newval);
        }
        else if (choice == 3)
        {
            printf("Enter value for middle insert(according to index) : ");
            scanf("%d", &newval);
            printf("Enter index number : ");
            scanf("%d", &i);
            insertMid1(newval,i);
        }
        else if(choice == 4)
        {
            printf("Enter value for middle insert(after a desired node value) : ");
            scanf("%d", &newval);
            printf("Enter value : ");
            scanf("%d", &i);
            insertMid2(newval,i);
        }
        else if (choice == 5)
        {
            print();
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
}
