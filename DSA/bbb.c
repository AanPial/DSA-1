#include<stdio.h>
int main()
{
    printf("Enter array size : ");
    int n;
    scanf("%d",&n);
    printf("Enter array element : ");
    int taba[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&taba[i]);
    }
    int temp;
    for(int i=0;i<n;i++)
    {
        printf("%d ",taba[i]);
    }
    printf("\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(taba[j]>taba[j+1])
            {
                temp=taba[j];
                taba[j]=taba[j+1];
                taba[j+1]=temp;
            }
        }
    }
    printf("After using Bubble sort: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",taba[i]);
    }

    return 0;
}