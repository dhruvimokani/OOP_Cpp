#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

void additem()
{
    char name[50];
    int quantity;
    float price;

    ofstream fout("inventory.txt",ios::app);
    cout<<"enter name of item:";
    cin>>name;
    cout<<"enter number of quantity of item:";
    cin>>quantity;
    cout<<"enter price of item:";
    cin>>price;

    fout<<name<<" "<<quantity<<" "<<price<<endl;
    fout.close();
    cout<<"item is added succesfully!!"<<endl;
}

void viewitems()
{
    char name[50];
    int quantity;
    float price;
    ifstream fin("inventory.txt",ios::in);
    if(!fin)
    {
        cout<<"file not found"<<endl;
        return;
    }
    while(fin >> name >> quantity >> price)
    {
        cout<<"Name: "<<name
            <<", Quantity: "<<quantity
            <<", Price: "<<price<<endl;
    }
    fin.close();
}

void searchitem()
{
    char name[50], searchName[50];
    int quantity;
    float price;
    int found = 0;

    ifstream fin("inventory.txt");

    if(!fin)
    {
        cout<<"file not found"<<endl;
        return;
    }

    cout<<"Enter item name to search: ";
    cin>>searchName;

    for(int i=0; searchName[i]; i++)
        searchName[i]=tolower(searchName[i]);

    while(fin>>name>>quantity>>price)
    {
        char temp[50];
        strcpy(temp,name);

        for(int i=0; temp[i]; i++)
            temp[i]=tolower(temp[i]);

        if(strcmp(temp, searchName) == 0)
        {
            cout<<"Item Found!\n";
            cout<<"Name: "<<name
                <<", Quantity: "<<quantity
                <<", Price: "<<price<<endl;
            found = 1;
            break;
        }
    }
    if(!found)
    {
        cout<<"item not found!!"<<endl;
    }
    fin.close();
}

void deleteitem()
{
    char name[50], delName[50];
    int quantity;
    float price;
    int found=0;

    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");

    cout<<"Enter item name to delete: ";
    cin>>delName;

    while(fin>>name>>quantity>>price)
    {
        if(strcmp(name,delName)==0)
        {
            found=1;
        }
        else
        {
            fout<<name<<" "<<quantity<<" "<<price<<endl;
        }
    }

    fin.close();
    fout.close();

    remove("inventory.txt");
    rename("temp.txt","inventory.txt");

    if(found)
        cout<<"Item deleted successfully"<<endl;
    else
        cout<<"Item not found"<<endl;
}

void modifyitem()
{
    char name[50], modName[50];
    int quantity;
    float price;
    int found=0;

    ifstream fin("inventory.txt");
    ofstream fout("temp.txt");

    cout<<"Enter item name to modify: ";
    cin>>modName;

    while(fin>>name>>quantity>>price)
    {
        if(strcmp(name,modName)==0)
        {
            found=1;
            cout<<"Enter new quantity: ";
            cin>>quantity;
            cout<<"Enter new price: ";
            cin>>price;
        }
        fout<<name<<" "<<quantity<<" "<<price<<endl;
    }

    fin.close();
    fout.close();

    remove("inventory.txt");
    rename("temp.txt","inventory.txt");

    if(found)
        cout<<"Item modified successfully"<<endl;
    else
        cout<<"Item not found"<<endl;
}

void countitems()
{
    char name[50];
    int quantity;
    float price;
    int count=0;

    ifstream fin("inventory.txt");

    while(fin>>name>>quantity>>price)
    {
        count++;
    }

    fin.close();

    cout<<"Total items: "<<count<<endl;
}

int main()
{
    int ch;
    do{
    cout<<"1.additem\t"
        <<"2.viewitems\t"
        <<"3.searchitem\t"
        <<"4.deleteitem\t"
        <<"5.modifyitem\t"
        <<"6.countitems\t"
        <<"7.exit"<<endl;

    cout<<"enter your choice :";
    cin>>ch;

    switch(ch)
    {
        case 1:additem(); break;
        case 2:viewitems(); break;
        case 3:searchitem(); break;
        case 4:deleteitem(); break;
        case 5:modifyitem(); break;
        case 6:countitems(); break;
        case 7:break;
        default:
        cout<<"inavlid choice"<<endl;
    }

}while(ch!=7);

    return 0;
}
