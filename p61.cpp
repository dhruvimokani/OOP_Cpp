#include<iostream>
using namespace std;

class Shape
{
protected:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{ 
public:
    float area()
    {
        return 3.14 * radius * radius;
    }

    float circumference()
    {
        return 2 * 3.14 * radius;
    }

    void display()
    {
        float a = area();

        cout<<"Radius: "<<radius
            <<", Area: "<<a
            <<", Circumference: "<<circumference();

        if(a < 50)
            cout<<" -> Small";
        else if(a < 150)
            cout<<" -> Medium";
        else
            cout<<" -> Large";

        cout<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter number of circles: ";
    cin>>n;

    Circle *c = new Circle[n];
 
    for(int i=0;i<n;i++)
    {
        float r;
        cout<<"Enter radius "<<i+1<<": ";
        cin>>r;
        c[i].setRadius(r);
    }

    cout<<"\n--- Circle ---\n";
    for(int i=0;i<n;i++)
    {
        c[i].display();
    }

    delete[] c;

    cout<<"\n--- Static Array Example ---\n";

    Circle s[2];

    for(int i=0;i<2;i++)
    {
        float r;
        cout<<"Enter radius "<<i+1<<": ";
        cin>>r;
        s[i].setRadius(r);
    }

    cout<<"\nStatic Circles:\n";
    for(int i=0;i<2;i++)
    {
        s[i].display();
    }

    return 0;
}
