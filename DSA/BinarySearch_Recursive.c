#include<stdio.h>
void bubblesort(int *arr,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int binarysearch(int *arr,int l,int r,int data)//cause array must be in sorted order for binary search
{
    if(l>r)
    {
        return -1;
    }
    else
    {
        int mid=(l+r)/2;
        if(arr[mid] == data)
        {
            return mid;
        }
        else if(arr[mid]>data)
        {
            binarysearch(arr,l,mid-1,data);
        }
        else
        {
            binarysearch(arr,mid+1,r,data);
        }
    }
}
int main()
{
    int n;
    printf("Enter size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    bubblesort(arr,n);
    int data;
    printf("Enter data : ");
    scanf("%d",&data);
    int x=binarysearch(arr,0,n-1,data);
    if(x == -1)
    {
        printf("Value not found!");
    }
    else
    {
        printf("Value found at %d ",x);
    }
}