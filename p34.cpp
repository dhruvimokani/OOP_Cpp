#include<iostream>
using namespace std;

//FIND MAX 
template<typename T>
T findMAX(T arr[] ,int n)
{
    T Max=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>Max)
        {
            Max=arr[i];
        }
    }
    return Max;
}

//REVERSE ARRAY
template<typename T>
void reverseArray(T arr[], int n)
{
    for(int i=0;i<n/2;i++)
    {
T temp=arr[i];
arr[i]=arr[n-i-1];
arr[n-i-1]=temp;
    }
}

//DISPLAY
template<typename T>
void Display(T arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
}

int main()
{
int ch;

cout<<"1 for int arrray"<<endl<<"2 for float array"<<endl<<"3 for char array"<<endl;
cin>>ch;

switch(ch)
{
case 1:
{int s;
 cout<<"Enter How many Elements You want to add in array:"<<endl;
cin>>s;
int a[s];
cout<<"Enter Array Elements:"<<endl;
for(int i=0;i<s;i++)
    {
       cin >> a[i];
    }
int Maximum=findMAX(a,s);
cout<<"\nMaximum Element:"<<Maximum<<endl;

reverseArray(a,s);

cout<<endl;
Display(a,s);
break;
}
case 2: 
{int m;
cout<<"Enter How many Elements You want to add in array:"<<endl;
cin>>m;
float b[m];
cout<<"Enter Array Elements:"<<endl;
for(int i=0;i<m;i++)
    {
       cin >> b[i];
    }
float maximum=findMAX(b,m);
cout<<"\nMaximum Element:"<<maximum<<endl;

reverseArray(b,m);

cout<<endl;
Display(b,m);
break;
}
case 3: 
{int y;
cout<<"Enter How many Elements You want to add in array:"<<endl;
cin>>y;
char x[y];
cout<<"Enter Array Elements:"<<endl;
for(int i=0;i<y;i++)
    {
       cin >> x[i];
    }
char max=findMAX(x,y);
cout<<"\nMaximum Element:"<<max<<endl;

reverseArray(x,y);

cout<<endl;
Display(x,y);

break;
}
}




    return 0;
}