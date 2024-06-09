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
        printf("\n\nMax Size of SAL is set to %d\n", n);
        printf("\nMenu : ");
        printf("\n1.Insert \n2.Update\n3.Search\n4.Print\n5.Delete (bonus)\n6.Print Current Array\n7.Delete occurence\n8.Bubble sort\n0.EXIT");
        printf("\n\nEnter choice : ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            printf("Enter element to insert: ");
            scanf("%d", &new_val);
            printf("\nEnter the position (index) to insert(current array length is: %d, so choose an index between 0 and %d): ", i, i);
            scanf("%d", &pos);
            if(pos<0 || pos>n || pos>i+1 || n == i)
            {
                 printf("Out of Bound");
                 goto err;
            }
            else if (i < n)
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
            printf("\nEnter the index to print: ");
            scanf("%d", &pos);
            printf("\nThe val at index %d: %d", pos, arr[pos]);
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
        else if(choice==6)
        {
            printf("\nThe current array list is:");
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
        }
        else if(choice == 7)
        {
            printf("Enter value to delete : ");
            scanf("%d",&new_val);
            printf("Enter occurance to delete : ");
            scanf("%d",&pos);
            flag=0;
            int x=0;
            int y;
            for (int j = 0; j < i; j++)
            {

                if(new_val == arr[j] )
                {
                    x++;
                    if(x==pos){
                       flag=1;
                       y=j;
                       break;
                    }
                }

            }
            if(flag==1)
            {
                printf("\nDeleted from position %d\n", pos);
                for (int j = y; j < i; j++)
                {
                    arr[j] = arr[j + 1];
                }
                i--;
            }
            else
            {
                printf("Occurance doesn't exist .\n");
                goto err;
            }
            printf("\nThe current array list is:");
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
        }
        else if (choice == 8)
        {
            printf("Sorted by bubble sort Algorithm.\n");
            int temp;
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<i;k++)
                {
                    if(arr[k]>arr[k+1])
                    {
                        temp=arr[k];
                        arr[k]=arr[k+1];
                        arr[k+1]=temp;
                    }
                }
            }
            printf("\nThe current array list is:");
            for (int j = 0; j < i; j++)
            {
                printf("%d ", arr[j]);
            }
        }
        
        else
        {
            printf("\nWrong Choice. Enter again.\n\n");
            goto err;
        }
    }
}
