#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = data;
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}
int dequeue()
{
    struct node *temp;
    int y;
    if (front == NULL)
    {
        printf("\nQueue underflow.\n");
        return -1;
    }
    else
    {
        temp = front;
        y = front->value;
        front = front->next;
        if (front == NULL) { 
            rear = NULL;
        }
        free(temp);
        return y;
    }
}
void print()
{
    if (front == NULL)
    {
        printf("\nEmpty!\n");
        return;
    }
    struct node *temp;
    temp = front;
    printf("\nElements : ");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int choice, newval;
    while (1)
    {
    err:
        printf("\nMenu:\n1.Enqueue\n2.Dequeue\n3.Print\n0.Exit\nEnter : ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("\nExited!\n");
            break;
        }
        else if (choice == 1)
        {
            printf("Enter value for enqueue : ");
            scanf("%d", &newval);
            enqueue(newval);
        }
        else if (choice == 2)
        {
            int x = dequeue();
            printf("\n%d id dequeued\n", x);
            print();
        }
        else if (choice == 3)
        {
            print();
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
    return 0;
}