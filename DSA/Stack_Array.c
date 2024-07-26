#include<stdio.h>
int n,top=-1;
void push(int x,int *stk)
{
    if(top>=n-1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        top++;
        stk[top]=x;
    }
}
int pop(int *stk)
{
    int y;
    if(top<0)
    {
        printf("\nStack Underflow.\n");
        return 1;
    }
    else
    {
        y=stk[top];
        top--;
        return y;
    }
}
void print(int *stk)
{
    for(int i=0;i<=top;i++)
    {
        printf("%d ",stk[i]);
    }
}
int main()
{
    printf("Enter array size : ");
    scanf("%d",&n);
    int arr[n];
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
            push(newval,arr);
        }
        else if(choice == 2)
        {
            int x=pop(arr);
            if(x!=1)
            {
                printf("\nValue %d has been poped.\n",x);
            }
            print(arr);
        }
        else if(choice == 3)
        {
            printf("\nElements : ");
            print(arr);
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