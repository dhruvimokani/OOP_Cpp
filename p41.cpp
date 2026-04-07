#include <iostream>
using namespace std;

class arrays
{
    int *arr;
    int size;

public:
    arrays()
    {
        arr=NULL;
        size=0;
    }

    void insert(int v)
    {
        int *newarr=new int[size+1];
        for(int i=0;i<size;i++)
        {
            newarr[i]=arr[i];
        }
        newarr[size]=v;
        size++;
        delete[] arr;
        arr=newarr;
    }

    void insertAt(int position,int value)
    {
        int *newarr=new int[size+1];
        int j=0;
        for(int i=0;i<size+1;i++)
        {
            if(i==position)
            {
                newarr[i]=value;
            }
            else
            {
                newarr[i]=arr[j];
                j++;
            }
        }
        size++;
        delete[] arr;
        arr=newarr;
    }

    void deletion(int position)
    {
        int *newarr=new int[size-1];
        int j=0;
        for(int i=0;i<size;i++)
        {
            if(i!=position)
            {
                newarr[j]=arr[i];
                j++;
            }
        }
        size--;
        delete[] arr;
        arr=newarr;
    }

    int search(int value)
    {
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                return i;
            }
        }
        return -1;
    }

    int countOccurrences(int value)
    {
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                count++;
            }
        }
        return count;
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    arrays s1;
    int ch;
    char c='y';
    while(c=='y')
    {
        cout<<"\n1.insert\t2.delete\t3.display\t4.insert at index\t5.search\t6.count\n";
        cin>>ch;
        if(ch==1)
        {
            int value;
            cout<<"Enter value: ";
            cin>>value;
            s1.insert(value);
        }
        else if(ch==2)
        {
            int position;
            cout<<"Enter position: ";
            cin>>position;
            s1.deletion(position);
        }
        else if(ch==3)
        {
            s1.display();
        }
        else if(ch==4)
        {
            int pos,val;
            cout<<"Enter position and value: ";
            cin>>pos>>val;
            s1.insertAt(pos,val);
        }
        else if(ch==5)
        {
            int val;
            cout<<"Enter value to search: ";
            cin>>val;
            int result=s1.search(val);
            if(result==-1)
                cout<<"Element not found\n";
            else
                cout<<"Found at index: "<<result<<endl;
        }
        else if(ch==6)
        {
            int val;
            cout<<"Enter value: ";
            cin>>val;
            cout<<"Occurrences: "<<s1.countOccurrences(val)<<endl;
        }
        cout<<"Continue? (y/n): ";
        cin>>c;
    }
    return 0;
}
