#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
int count=0;
void ftraversal()
{
    struct node *t = head;
    if (head == NULL)
    {
        printf("\nList empty");
        return;
    }
    while (t != NULL)
    {
        printf("%d -> ", t->value);
        t = t->next;
    }
}

void btraversal()
{
    struct node *t = tail;
    if (tail == NULL)
    {
        printf("\nList empty");
        return;
    }
    while (t != NULL)
    {
        printf("%d -> ", t->value);
        t = t->prev;
    }
}
void insertFirst(int newVal)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = newVal;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        count++;
    }
}
void insertLast(int newVal)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->value = newVal;
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        count++;
    }
}
void insertMid1(int newVal, int n)
{
    if (head == NULL)
    {
        printf("\nEmpty and cannot be insert.\n");
        return;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->value = newVal;
    struct node *temp = head;
    while (temp!=NULL && temp->value != n )
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\nValue doesnt exist.\n");
        free(newnode); 
        return;
    }
    if (temp->next == NULL)
    {
        newnode->prev = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        count++;
    }
    else
    {
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
        count++;
    }
}
void insertMid2(int newVal,int n)
{
   if (n > count || n < 0)
    {
        printf("\nIncorrect position.\n");
        return;
    }
    if(head == NULL)
    {
        printf("\nEmpty couldn't be instead.\n");
        return;
    }
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp=head;
    newnode->value=newVal;
    for(int i=0;i<n;i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        newnode->prev =temp->prev;
        temp->prev->next=newnode;
        newnode->next=temp;
        temp->prev=newnode;
        count++;
    }
    else
    {
         newnode->next = temp;
        newnode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newnode;
        } else {
            head = newnode;  
        }
        temp->prev = newnode;
    }
}
void deletenode(struct node* temp)
{
    if(temp==head)
    {
        head=head->next;
    }
    if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }
    if(temp->prev!=NULL)
    {
        temp->prev->next=temp->next;
    }
    if(temp==tail)
    {
        tail=temp->prev;
    }
    free(temp);
    return;
}
int main()
{
    int choice, newVal, n;
    while (1)
    {
    err:
        printf("\n\n1. F Traversal\n2. B Traversal \n3. Insert First \n4. Insert Last \n5. Insert After a val \n6. Insert at a middle pos \n");
        printf("7. Delete \n8. Search \n9. Your custom function!  \n10. EXIT\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            ftraversal();
        }
        else if (choice == 2)
        {
            btraversal();
        }
        else if (choice == 3)
        {
            printf("Enter element for insert first : ");
            scanf("%d", &newVal);
            insertFirst(newVal);
        }
        else if (choice == 4)
        {
            printf("Enter element for insert Last : ");
            scanf("%d", &newVal);
            insertLast(newVal);
        }
        else if (choice == 5)
        {
            printf("Enter value for insert : ");
            scanf("%d", &newVal);
            printf("Enter the value to insert after : ");
            scanf("%d", &n);
            insertMid1(newVal, n);
        }
        else if (choice == 6)
        {
            printf("Enter value to insert   : ");
            scanf("%d",&newVal);
            printf("Enter index postion to enter : ");
            scanf("%d",&n);
            insertMid2(newVal,n);
        }
        else if (choice == 7)
        {
            printf("Enter value to delete : ");
            scanf("%d",&newVal);
            struct node*temp=head;
            while(temp!=NULL && temp->value!=newVal)
            {
                temp=temp->next;
            }
            if(temp!=NULL)
            {
                deletenode(temp);
            }
            else
            {
                printf("\nValue dosn't exist.So,it cannot be deleted.\n");
            }
            ftraversal();
        }
        else if (choice == 8)
        {
            // WRITE APPROPRIATE CODE HERE
        }
        else if (choice == 9)
        {
            // WRITE APPROPRIATE CODE HERE
        }

        else if (choice == 10)
        {
            break;
        }

        else
        {
            printf("Wrong choice, enter again");
            goto err;
        }
    }
}
