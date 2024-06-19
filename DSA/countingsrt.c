#include<stdio.h>
int main()
{
    printf("Enter array size : ");
    int n;
    scanf("%d",&n);
    printf("Enter array element : ");
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    int c[max+1];
    for(int i=0;i<=max;i++)
    {
        c[i]=0;
    }
    for(int i = 0; i < n; i++)
    {
        c[a[i]] += 1;
    }
    for(int i=1;i<=max;i++)
    {
        c[i]=c[i]+c[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]=c[a[i]]-1;
    }
    printf("\nAfter using counting sort Algorithm : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}