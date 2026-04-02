#include<iostream>
using namespace std;

class inventory
{
    int id;
    string it_name;
    float price;
    int quantity;

public:
    inventory()
    {
        id = 0;
    }

    inventory(int idd,string name,float p,int q)
    {
        id=idd;
        it_name=name;
        price=p;
        quantity=q;
    }

    void increaseStock(int q)
    {
        if(q<=0)
        {
            cout<<"Invalid input..quantity can not be negative or zero";
        }
        else
        {
            quantity+=q;
        }
    }

    void decreaseStock(int q)
    {
        if(q<=0)
        {
            cout<<"Invalid input..quantity can not be negative or zero";
        }
        else if(q>quantity)
        {
            cout<<"Not Enough stock";
        }
        else
        {
            quantity-=q;
        }
    }

    void updatePrice(float newPrice)
    {
        if(newPrice <= 0)
        {
            cout<<"Invalid price";
        }
        else
        {
            price = newPrice;
        }
    }

    int getquantity()
    {
        return quantity;
    }

    void display()
    {
        cout<<"\nId:"<<id;
        cout<<"\nItem name:"<<it_name;
        cout<<"\nPrice:"<<price;
        cout<<"\nQuantity:"<<quantity;
    }
};

int main()
{
    inventory I[20];
    int idd;
    string name;
    float p;
    int q;
    int n,ch;

    cout<<"How many items you want to add:";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Id for item "<<i+1<<": ";
        cin>>idd;

        cout<<"Enter Item name for item "<<i+1<<": ";
        cin>>name;

        cout<<"Enter Price for item "<<i+1<<": ";
        cin>>p;

        cout<<"Enter Quantity for item "<<i+1<<": ";
        cin>>q;

        I[i]=inventory(idd,name,p,q);
    }

    for(int i=0;i<n;i++)
    {
        I[i].display();
        cout<<"\n";
    }

    cout<<"\n-----Selection Menu-----";
    cout<<"\n1 for increase stock";
    cout<<"\n2 for decrease stock";
    cout<<"\n3 for update price";

    int qua;
    float newPrice;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Choice for item "<<i+1<<": ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"How many quantity you want to increase:";
            cin>>qua;
            I[i].increaseStock(qua);
        }
        else if(ch==2)
        {
            cout<<"How many quantity you want to decrease:";
            cin>>qua;
            I[i].decreaseStock(qua);
        }
        else if(ch==3)
        {
            cout<<"Enter new price:";
            cin>>newPrice;
            I[i].updatePrice(newPrice);
        }
        else
            break;
    }

    cout<<"\n-----Updated Item Details-----\n";
    for(int i=0;i<n;i++)
    {
        I[i].display();
        cout<<"\n";
    }

    // Low inventory alert
    cout<<"\n-----Low Inventory (Quantity < 5)-----\n";
    for(int i=0;i<n;i++)
    {
        if(I[i].getquantity()<5)
        {
            I[i].display();
            cout<<"\n";
        }
    }

    // Sorting based on quantity 
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(I[i].getquantity() > I[j].getquantity())
            {
                inventory temp = I[i];
                I[i] = I[j];
                I[j] = temp;
            }
        }
    }

    cout<<"\n-----Items Sorted by Quantity-----\n";
    for(int i=0;i<n;i++)
    {
        I[i].display();
        cout<<"\n";
    }

    return 0;
}