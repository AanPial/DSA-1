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
void insertLast(int x)
{
    struct node *newItem = (struct node *)malloc(sizeof(struct node));
    newItem->value = x;
    newItem->next = NULL;

    if (head == NULL)
    {
        head = newItem;
    }
    else
    {
        struct node *prev;
        prev = head;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        prev->next = newItem;
    }
}
void insertMid1(int newval, int n)
{
    struct node *newitem;
    newitem = (struct node *)malloc(sizeof(struct node));
    newitem->value = newval;
    struct node *prev = head;
    for (int i = 0; i < n - 1; i++)
    {
        prev = prev->next;
    }
    newitem->next = prev->next;
    prev->next = newitem;
}
void insertMid2(int newval, int n)
{
    struct node *newitem;
    newitem = (struct node *)malloc(sizeof(struct node));
    newitem->value = newval;
    struct node *prev = head;
    while (prev != NULL && prev->value != n)
    {
        prev = prev->next;
    }
    if (prev != NULL)
    {
        newitem->next = prev->next;
        prev->next = newitem;
    }
    else
    {
        printf("Value doesn't Exist!");
    }
}
void delete1st()
{
    if (head == NULL)
    {
        return;
    }
    struct node *cur;
    cur = head;
    head = head->next;
    free(cur);
}
void deletelast()
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct node *cur = head;
    struct node *prev;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    free(cur);
}
void deletepos(int num)
{
    if (head == NULL)
    {
        return;
    }

    struct node *cur = head;
    if (num == 0)
    {
        head = head->next;
        free(cur);
        return;
    }

    struct node *prev = NULL;
    for (int i = 0; i < num; i++)
    {
        prev = cur;
        cur = cur->next;
        if (cur == NULL)
        {
            return;
        }
    }

    prev->next = cur->next;
    free(cur);
}
void deleteval(int num)
{
    if (head == NULL)
    {
        return;
    }

    struct node* cur = head;
    struct node* prev = NULL;
    if (cur->value == num)
    {
        head = cur->next;
        free(cur);
        return;
    }
    while (cur != NULL && cur->value != num)
    {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
    {
        return;
    }
    prev->next = cur->next;
    free(cur);
}

int main()
{
    int choice, newval, i;
    while (1)
    {
    err:
        printf("\nOptions : \n1.Insert first.\n2.Insert Last\n3.Insert middle(According to index)\n4.Insert middle(According to value)\n5.Print\n");
        printf("6.Delete first\n7.Delete Last\n8.Delete from position\n9.Delete value\n0.Exit\n");
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
            insertMid1(newval, i);
        }
        else if (choice == 4)
        {
            printf("Enter value for middle insert(after a desired node value) : ");
            scanf("%d", &newval);
            printf("Enter value : ");
            scanf("%d", &i);
            insertMid2(newval, i);
        }
        else if (choice == 5)
        {
            print();
        }
        else if (choice == 6)
        {
            delete1st();
            print();
        }
        else if (choice == 7)
        {
            deletelast();
            print();
        }
        else if (choice == 8)
        {
            printf("Enter position for delete : ");
            scanf("%d", &newval);
            deletepos(newval);
            print();
        }
        else if (choice == 9)
        {
            printf("Enter value for delete : ");
            scanf("%d", &newval);
            deleteval(newval);
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
