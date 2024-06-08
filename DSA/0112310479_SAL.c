#include <stdio.h>
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
       printf("\n1.Print \n2.Update\n3.Search\n4.Insert\n5.Delete (bonus)\n0.EXIT");
       printf("\n\nEnter choice: ");
       scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);
        }
        
        else if (choice == 2)
        {
            printf("\nEnter the index to update: ");
            scanf("%d", &pos);
            printf("\nEnter the new value: ");
            scanf("%d", &new_val);
            arr[pos] = new_val;
            printf("The new val at index %d: %d", pos, arr[pos]);
        }
        else if (choice == 3)
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
        else if (choice == 4)
        {
            printf("Enter element to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert(current array length is: %d, so choose an index between 0 and %d): ", i, i);
            scanf("%d", &pos);
            if (i < n)
            {
                printf("%d inserted at index %d\n", new_val, pos);
                if (pos == i)
                {
                    arr[pos] = new_val;
                }
                else if (pos >= 0 && pos < i)
                {
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
            printf("\nThe current array list is:");
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
        }
        
        else if (choice == 5)
        {
            printf("\nEnter the position (index) to delete from: ");
            scanf("%d", &pos);
            if (pos <= i)
            {
                printf("\nDeleted from position %d\n", pos);
                for (int j = pos; j < i; j++)
                {
                    arr[j] = arr[j + 1];
                }
                i--;
            }
            else
            {
                printf("\nIncorrect pos value\n");
            }
            printf("\nThe current array list is:");
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
        }
        else if(choice==0)
            break;
        else
        {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }
    }
}