#include<iostream>
using namespace std;

int main()
{
    printf("Enter array size : ");
    int n;
    cin>>n;
    printf("Enter array element : ");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(key<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printf("\nAfter using insertion sort: ");
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}