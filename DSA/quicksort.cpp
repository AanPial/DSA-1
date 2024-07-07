#include<iostream>
using namespace std;

int partition(int *arr, int p, int r) 
{
    int pivot=arr[r];
    int i=p-1;
    int temp;
    for(int j=p;j<r;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;

    return i+1;
}
void quicksort(int *arr,int p,int r)
{
    if(p<r)
    {
        int k = partition(arr, p, r);
        quicksort(arr, p, k - 1); 
        quicksort(arr, k + 1, r);
    }
}

int main()
{
    int n;
    cout<<"Enter array limit : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}