#include<stdio.h>
int merge(int *arr,int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1],R[n2+1];

    for(int i=0;i<n1;i++)
    {
        L[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=arr[q+i+1];
    }
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
    }
}
int mergesort(int *arr,int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main()
{
    int n;
    printf("Enter array size : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}