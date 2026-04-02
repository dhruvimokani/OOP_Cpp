
#include<iostream>
using namespace std;

class Rectangle
{
private:
   int len,width;


public:
void getdetail()
{
    static int id;
x: 
cout<<"Enter Length:";
cin>>len;
cout<<"\nEnter Width:";
cin>>width;

if(len<=0 || width<=0)
{
    cout<<"Dimension can not be 0 or negative";
    goto x;
}
else
{
cout<<"\nRectangle ID :"<<++id;
}
}
int area()
{
   return len*width;
}

int perimeter()
{
   
   return 2*(len+width);
}

void display()
{
    int a=area();
    int b=perimeter();
 cout<<"\nLength:"<<len;
 cout<<"\nWidth:"<<width;
 cout<<"\nArea:"<<a;
 cout<<"\nPerimeter:"<<b;
}
void check()
{
    if(len==width)
    {
        cout<<"\nRectangle is Square";
    }
    else
    {
        cout<<"\nRectangle is not Square";
    }
}

};

int main()
{
    int n;
    int i;
 
    cout<<"\nEnter the number of rectangles:";
    cin>>n;
    Rectangle r[n];
    int a[n];
    
    
    for(i=0;i<n;i++)
{
   r[i].getdetail();
  a[i]=r[i].area();
   r[i].perimeter();
   r[i].display();
   r[i].check();
}

int maxArea;
for(i=0;i<n;i++)
{
for(int j=i+1;j<n;j++)
{
    if(a[i]>a[j])
    {
        maxArea=a[i];
    }
    else
    {
        maxArea=a[j];
    }
}

}
cout<<"\nmaxArea:"<<maxArea;
}