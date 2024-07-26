#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node*next;
};
struct node*top=NULL;

void push(int x)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode)
    {
        printf("\nHeap Overflow.\n");
        return;
    }
    newnode->val=x;
    newnode->next=top;
    top=newnode;
}
void print()
{
    if(top == NULL)
    {
        printf("\nStack empty.\n");
    }
    else
    {
        struct node*temp;
        temp=top;
        while (temp !=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        
    }
}
int pop()
{
    if(top == NULL)
    {
        printf("\nStack Underflow.\n");
        return 1;
    }
    struct node*temp;
    int y;
    temp=top;
    y=top->val;
    top=top->next;
    free(temp);
    return y;
}
int main()
{
    int choice,newval;
    while(1)
    {
        err:
        printf("\nMenu:\n1.Push\n2.Pop\n3.Print\n0.Exit\nEnter : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter value to push : ");
            scanf("%d",&newval);
            push(newval);
        }
        else if(choice == 2)
        {
            int x=pop();
            if(x!=1)
            {
                printf("\nValue %d has been poped.\n",x);
            }
            print();
        }
        else if(choice == 3)
        {
            printf("\nElements : ");
            print();
        }
        else if (choice == 0)
        {
            printf("\nExited.\n");
            break;
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
}