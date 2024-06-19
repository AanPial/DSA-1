#include<iostream>
using namespace std;
int main()
{
    printf("Enter array size : ");
    int n;
    cin>>n;
    printf("Enter array element : ");
    int taba[n];
    for(int i=0;i<n;i++)
    {
        cin>>taba[i];
    }
    int temp;
    for(int i=0;i<n;i++)
    {
        cout<<taba[i]<<" ";
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
        cout<<taba[i]<<" ";
    }

    return 0;
}
