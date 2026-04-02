#include<iostream>
using namespace std;

// Recursive Sum
int recursion(int a[], int n)
{
    if(n == 0)
    {
        return 0;
    }
    return recursion(a, n-1) + a[n-1];
}

// Iterative Maximum
int maxIterative(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }
    return max;
}

// Recursive Maximum
int maxRecursive(int a[], int n)
{
    if(n == 1)
        return a[0];

    int m = maxRecursive(a, n-1);

    if(a[n-1] > m)
        return a[n-1];
    else
        return m;
}

// Prefix Sum using Recursion
void prefixSum(int a[], int n)
{
    if(n == 0)
        return;

    prefixSum(a, n-1);

    if(n-2 >= 0)
        a[n-1] = a[n-1] + a[n-2];
}

int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int a[n]; 
    
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Element "<<i+1<<": ";
        cin>>a[i];
    }
    
    cout<<"\nArray Elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    // Iterative Sum
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    cout<<"\n\nIterative Sum: "<<sum;

    // Recursive Sum
    int rsum = recursion(a, n);
    cout<<"\nRecursive Sum: "<<rsum;

    // Maximum Element
    cout<<"\n\nMaximum (Iterative): "<<maxIterative(a, n);
    cout<<"\nMaximum (Recursive): "<<maxRecursive(a, n);

    // Prefix Sum
    prefixSum(a, n);

    cout<<"\n\nPrefix Sum Array:\n";
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
