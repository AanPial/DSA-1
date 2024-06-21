#include<iostream>
using namespace std;
int binarysrch(int arr[],int n,int sd)
{
    int l=0,r=n-1;
    

    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==sd)
        {
            return mid;
        }
        else if(arr[mid]<sd)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n,sd;
    
    cout<<"Enter array size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements(You must enter value in sorted order) : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter value to find : ";
    cin>>sd;
    int x=binarysrch(arr,n,sd);

    if(x == -1)
    {
        cout<<"This value is not present in the array"<<endl;
    }
    else
    {
        cout<<"The value is at "<<x<<" index."<<endl;
    }

    return 0;
}