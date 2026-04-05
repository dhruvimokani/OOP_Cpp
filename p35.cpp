#include<iostream>
#include<string>
using namespace std;

int depth = 0;
int maxDepth;

int superdigit(int n)
{
    depth++;

    cout << "Level " << depth << " -> Current number: " << n << endl;

    if(depth > maxDepth)
    {
        cout << "Stopped early at level limit!" << endl;
        return n;
    }

    if(n < 10)
    {
        return n;
    }

    int Sum = 0;

    while(n > 0)
    {
        int c = n % 10;
        n = n / 10;
        Sum += c;
    }
    cout << "Sum at Level " << depth << " = " << Sum << endl;

    return superdigit(Sum);
}

int main()
{
    string str;
    long long sum = 0;

    cout << "Enter String: ";
    cin >> str;

    int len = str.length();
    cout << "String Length: " << len << endl;

    for(int i = 0; i < len; i++)
    {
        sum = sum + (str[i] - '0');
    }

    int k;
    cout << "\nHow many times it is concatenated: ";
    cin >> k;

    sum = sum * k;

    cout << "Enter max recursion depth: ";
    cin >> maxDepth;

    int result = superdigit(sum);

    cout << "\nFinal Super Digit: " << result << endl;
    cout << "Total Recursion Depth Used: " << depth << endl;

    return 0;
}
