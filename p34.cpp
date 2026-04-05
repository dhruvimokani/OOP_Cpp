#include<iostream>
using namespace std;

template<typename T>
T findMAX(T arr[], int n)
{
    T Max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;
}

template<typename T>
T findMIN(T arr[], int n)
{
    T Min = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;
}

template<typename T>
void reverseArray(T arr[], int n)
{
    for(int i = 0; i < n/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

template<typename T>
void Display(T arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void findLeaders(T arr[], int n)
{
    cout << "Leader Elements: ";
    T leader = arr[n-1];
    cout << leader << " ";

    for(int i = n-2; i >= 0; i--)
    {
        if(arr[i] > leader)
        {
            leader = arr[i];
            cout << leader << " ";
        }
    }
    cout << endl;
}

template<typename T>
int searchElement(T arr[], int n, T key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return 0;
}

template<typename T>
int countOccurrences(T arr[], int n, T key)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            count++;
    }
    return count;
}

int main()
{
    int ch;

    cout<<"1 for int array\n2 for float array\n3 for char array\n";
    cin>>ch;

    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    switch(ch)
    {
    case 1:
    {
        int arr[n];
        cout<<"Enter elements:\n";
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<"Maximum: "<<findMAX(arr,n)<<endl;
        cout<<"Minimum: "<<findMIN(arr,n)<<endl;

        reverseArray(arr,n);
        cout<<"Reversed Array: ";
        Display(arr,n);

        findLeaders(arr,n);

        int key;
        cout<<"Enter element to search: ";
        cin>>key;

        int pos = searchElement(arr,n,key);
        cout<<"Position: "<<pos<<endl;

        cout<<"Occurrences: "<<countOccurrences(arr,n,key)<<endl;
        break;
    }

    case 2:
    {
        float arr[n];
        cout<<"Enter elements:\n";
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<"Maximum: "<<findMAX(arr,n)<<endl;
        cout<<"Minimum: "<<findMIN(arr,n)<<endl;

        reverseArray(arr,n);
        cout<<"Reversed Array: ";
        Display(arr,n);

        findLeaders(arr,n);

        float key;
        cout<<"Enter element to search: ";
        cin>>key;

        int pos = searchElement(arr,n,key);
        cout<<"Position: "<<pos<<endl;

        cout<<"Occurrences: "<<countOccurrences(arr,n,key)<<endl;
        break;
    }

    case 3:
    {
        char arr[n];
        cout<<"Enter elements:\n";
        for(int i=0;i<n;i++) cin>>arr[i];

        cout<<"Maximum: "<<findMAX(arr,n)<<endl;
        cout<<"Minimum: "<<findMIN(arr,n)<<endl;

        reverseArray(arr,n);
        cout<<"Reversed Array: ";
        Display(arr,n);

        findLeaders(arr,n);

        char key;
        cout<<"Enter element to search: ";
        cin>>key;

        int pos = searchElement(arr,n,key);
        cout<<"Position: "<<pos<<endl;

        cout<<"Occurrences: "<<countOccurrences(arr,n,key)<<endl;
        break;
    }
    }

    return 0;
}
