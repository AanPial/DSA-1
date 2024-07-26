#include <stdio.h>

int n, front = -1, rear = -1, count = -1;
void enqueue(int *arr, int x)
{
    if (front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        arr[rear] = x;
        count++;
    }
    else if ((rear + 1) % n == front)
    {
        printf("\nQueue Overflow.\n");
    }
    else
    {
        rear = (rear + 1) % n;
        arr[rear] = x;
        count++;
    }
}
int dequeue(int *arr)
{
    int y;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue underflow.\n");
    }
    else if (rear == front)
    {
        y = arr[front];
        rear = 0, front = 0;
        count--;
    }
    else
    {
        y = arr[front];
        front = (front + 1) % n;
        count--;
    }
    return y;
}
void print(int *arr)
{
    printf("\nElements : ");
    if (count < 0)
    {
        printf("Empty!");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d ", arr[i]);
            i = (i + 1) % n;
        }
        printf("%d", arr[rear]);
    }
}
int main()
{
    printf("Enter Size : ");
    scanf("%d", &n);
    int arr[n];
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
            enqueue(arr, newval);
        }
        else if (choice == 2)
        {
            int x = dequeue(arr);
            printf("\n%d id dequeued\n", x);
            print(arr);
        }
        else if (choice == 3)
        {
            print(arr);
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
}