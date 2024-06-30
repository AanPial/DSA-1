#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int n,flag=1;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            flag=0;
            break;
        }
    }
    if(flag == 1)
    {
        cout<<"EASY"<<endl;
    }
    else
    {
        cout<<"HARD"<<endl;
    }

    return 0;
}