#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *tail = NULL;
void insrtBgging(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = x;
    if (tail == NULL)
    {
        tail = newnode;
        newnode->next = tail;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
void insrtLast(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = x;
    if (tail == NULL)
    {
        tail = newnode;
        newnode->next = tail;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insrtMid(struct node *prevNode, int newval)
{
    if (prevNode == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->value = newval;
    newnode->next = prevNode->next;
    prevNode->next = newnode;
    if (prevNode == tail)
    {
        tail = newnode;
    }
}
void print()
{
    struct node *temp;
    if (tail == NULL)
    {
        printf("\nLinked list is empty.\n");
        return;
    }
    else
    {
        temp = tail->next;
        do
        {
            printf("%d->", temp->value);
            temp = temp->next;
        } while (temp != tail->next);
        printf("\n");
        printf("\n");
    }
}
void delete(struct node*targetNode)
{
    if(tail == NULL || targetNode == NULL)
    {
        printf("\nCannot delete.\n");
    }
    if(tail == targetNode && tail->next == tail)
    {
        tail = NULL;
        free(targetNode);
        return;
    }
    struct node*current = tail->next;
    struct node*previous = tail;

    while(current != tail && current!=targetNode)
    {
        previous = current;
        current = current->next;
    }
    if(current == targetNode)
    {
        previous->next = current->next;
        if(tail == targetNode)
        {
            tail = previous;
        }
        free(current);
        return;
    }
}
int main()
{
    int choice, newval, target;
    while (1)
    {
    err:
        printf("Menu : \n1.Print\n2.Insert first\n3.Insert Last\n4.Insert after position\n5.Delete\n0.Exit\nEnter : ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("\nExited\n");
            break;
        }
        else if (choice == 1)
        {
            print();
        }
        else if (choice == 2)
        {
            printf("Enter value for insert First : ");
            scanf("%d", &newval);
            insrtBgging(newval);
        }
        else if (choice == 3)
        {
            printf("Enter value for insert Last : ");
            scanf("%d", &newval);
            insrtLast(newval);
        }
        else if (choice == 4)
        {
            printf("Enter the value to insert after: ");
            scanf("%d", &target);
            printf("Enter value to insert: ");
            scanf("%d", &newval);
            struct node *temp = tail->next;
            do
            {
                if (temp->value == target)
                {
                    insrtMid(temp, newval);
                    break;
                }
                temp = temp->next;
            } while (temp != tail->next);
            if (temp == tail->next && tail->next->value != target)
            {
                printf("\nValue doesn't exist. So, it cannot be inserted.\n");
            }
        }
        else if (choice == 5)
        {
            printf("Enter index to delete : ");
            scanf("%d", &target);
            struct node *temp=tail->next;
            for(int i=0;i<target;i++)
            {
                temp=temp->next;
            }
            delete(temp);
            print();
            
        }
        else
        {
            goto err;
        }
    }
}
