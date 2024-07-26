#include <stdio.h>
void print(int arr[], int i)
{
    printf("\nThe current array list is : ");
    for (int j = 0; j < i; j++)
    {
        printf("%d ", arr[j]);
    }
}
void delete(int *arr, int pos, int i)
{
    for (int j = pos; j < i; j++)
    {
        arr[j] = arr[j + 1];
    }
}
void bubblesort(int *arr, int i)
{
    int temp;
    for (int j = 0; j < i-1; j++)
    {
        for (int k = 0; k < i-1; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }
}
int binarysrch(int *arr, int i, int sd)
{
    int l = 0, r = i - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == sd)
        {
            return mid;
        }
        else if (arr[mid] < sd)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}
void reversearray(int arr[], int i)
{
    printf("After reverse : ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d ", arr[j]);
    }
}    
void median(int arr[], int i)
{
    bubblesort(arr, i);
    int l=0, r=i, m, n;

    if (i % 2 == 0)
    {
        m = (l + r) / 2;
        printf("Median is : %d", arr[m]);
    }
    else
    {
        m = ((l + r) / 2);
        n = m + 1;
        float x = (arr[m] + arr[n]) / 2.0;
        printf("Median is : %f", x);
    }
}
int main()
{
    int n, choice, pos, new_val, s_val, i = 0, flag;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    while (1)
    {
    err:
        printf("\nMenu : \n");
        printf("1.Print Entire array (index 0 to len)\n2.Access a specific index\n3.Update the value of a specific index\n4.Linear Search\n5.Insert new value at a specific indexn\n6.Delete from an index");
        printf("\n7.Delete nth occurrence of a value\n8.Bubble Sort the existing array\n9.Binary Search on the array\n10.EXIT\n11.Reverse the array\n12.Median of the array\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            print(arr, i);
        }
        else if (choice == 2)
        {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);
        }
        else if (choice == 3)
        {
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            arr[pos] = new_val;
            printf("The new val at index %d: %d", pos, arr[pos]);
        }
        else if (choice == 4)
        {
            int j = 0;
            printf("\nEnter the Search Key : ");
            scanf("%d", &s_val);
            for (j = 0; j < i; j++)
            {
                flag = 0;
                if (s_val == arr[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("\nThe search key %d is at index %d\n", s_val, j);
            }
            else
            {
                printf("\nThe search key is not in the array\n");
            }
        }
        else if (choice == 5)
        {
            printf("Enter element to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert(current array length is: %d, so choose an index between 0 and %d): ", i, i);
            scanf("%d", &pos);
            if (pos < 0 || pos > n || pos > i + 1 || n == i)
            {
                printf("Incorrect positional value. The value can not be inserted.");
                goto err;
            }
            else if (i < n)
            {
                if (pos == i)
                {
                    printf("%d inserted at index %d\n", new_val, pos);
                    arr[pos] = new_val;
                }
                else if (pos >= 0 && pos < i)
                {
                    printf("%d inserted at index %d\n", new_val, pos);
                    int length = i + 1;
                    for (int j = length; j >= pos; j--)
                    {
                        arr[j + 1] = arr[j];
                    }
                    arr[pos] = new_val;
                }
                else
                {
                    printf("Incorrect positional value. The value can not be inserted.");
                    goto err;
                }
                i++;
            }
            else
            {
                printf("Sorry, the array List is full");
            }
            print(arr, i);
        }

        else if (choice == 6)
        {
            printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);
            if (pos <= i)
            {
                printf("\nDeleted from position %d\n", pos);
                delete (arr, pos, i);
                i--;
            }
            else
            {
                printf("\nIncorrect pos value\n");
            }
            print(arr, i);
        }
        else if (choice == 7)
        {
            printf("Enter value to delete : ");
            scanf("%d", &new_val);
            printf("Enter occurance to delete : ");
            scanf("%d", &pos);
            flag = 0;
            int x = 0;
            int y;
            for (int j = 0; j < i; j++)
            {

                if (new_val == arr[j])
                {
                    x++;
                    if (x == pos)
                    {
                        flag = 1;
                        y = j;
                        break;
                    }
                }
            }
            if (flag == 1)
            {
                printf("\nDeleted from position %d\n", pos);
                delete (arr, y, i);
                i--;
            }
            else
            {
                printf("Occurance doesn't exist .\n");
                goto err;
            }
            print(arr, i);
        }
        else if (choice == 8)
        {
            printf("Sorted by bubble sort Algorithm.\n");
            bubblesort(arr, i);
            print(arr, i);
        }
        else if (choice == 9)
        {
            printf("\nEnter the Search Key for binary search: ");
            scanf("%d", &s_val);
            bubblesort(arr, i);
            printf("\nSorted by bubble sort Algorithm.");
            print(arr, i);
            int x = binarysrch(arr, i, s_val);
            if (x == -1)
            {
                printf("\nThe search key is not in the array\n");
            }
            else
            {
                printf("\nThe search key %d is at index %d\n", s_val, x);
            }
        }
        else if (choice == 10)
        {
            printf("Exited!");
            break;
        }
        else if (choice == 11)
        {
            reversearray(arr, i);
        }
        else if (choice == 12)
        {
            median(arr, i-1);
        }
        else
        {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }
    }
}
