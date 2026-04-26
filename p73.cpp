#include<iostream>
using namespace std;
class fahrenheit;
class celsius{
float temp;
public:
celsius(int t=0){
    temp=t;
}
float getTemp()
{
    return temp;
}
operator fahrenheit();
void display()
{
    cout<<temp<<"c"<<endl;
}
bool operator==(celsius c)
{
 return temp=c.getTemp();
}
};

class fahrenheit{
float temp;
public:
fahrenheit(int t=0){
    temp=t;
}
float getTemp()
{
    return temp;
}
operator celsius()
{
float c=(temp-32)*5/9;
return celsius(c);
}
void display()
{
    cout<<temp<<"f"<<endl;
}
bool operator==(fahrenheit f)
{
 return temp=f.getTemp();
}
};
celsius::operator fahrenheit()
{
float f=(temp*9/5)+32;
return fahrenheit(f);
}



int main()
{
    celsius c1(25);
    fahrenheit f1;
    celsius c2;
    fahrenheit f2;


    f1= c1.operator fahrenheit();
    cout<<"Celsius to Fahenheit: ";
    f1.display();

 c2 = f1;
 cout<<"Fahenheit to Celsius  : ";
 c2.display();

  celsius c3(25);
  if(c1==c3)
  {
    cout<<"Temp. are equal..";
  }else
   {
    cout<<"Temp. are not equal..";
  }
}