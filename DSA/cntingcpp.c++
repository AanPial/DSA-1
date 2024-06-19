#include <iostream>
using namespace std;

int main()
{
    // Input array size
    cout << "Enter array size: ";
    int n;
    cin >> n;

    // Input array elements
    cout << "Enter array elements: ";
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Print the input array
    cout << "Input array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // Find the maximum element in the array
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }

    // Initialize the count array with zeros
    int c[max + 1];
    for (int i = 0; i <= max; i++)
    {
        c[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (int i = 0; i < n; i++)
    {
        c[a[i]] += 1;
    }

    // Update the count array to contain the cumulative sum of counts
    for (int i = 1; i <= max; i++)
    {
        c[i] = c[i] + c[i - 1];
    }

    // Build the output sorted array
    for (int i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }

    // Print the sorted array
    cout << "After using counting sort algorithm: ";
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
