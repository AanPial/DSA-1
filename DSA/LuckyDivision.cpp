#include <iostream>
using namespace std;
bool check(int n)
{
    bool flag = true;
    while (n > 0)
    {
        int c = n % 10;
        if (c != 4 && c != 7)
        {
            flag = false;
            break;
        }
        n = n / 10;
    }
    if (flag == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    bool flag = false;
    cin >> n;
    
    for(int i=1;i<=n;i++)
    {
        if(check(i)==true && n%i==0)
        {
            flag=true;
            break;
        }
    }
    if(flag== true)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}