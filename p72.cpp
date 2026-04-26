#include<iostream>
using namespace std;
class Complex{
int real;
int image;
public:
Complex(int r=0,int i=0)
{
    real=r;
    image=i;
}
Complex operator+(Complex i)
{
    return Complex(real+i.real,image+i.image);
}
Complex operator-(Complex i)
{
    return Complex(real-i.real,image-i.image);
}  
 Complex& operator+=(Complex c) {
        real += c.real;
        image += c.image;
        return *this;
    }

    Complex& operator*=(Complex c) {
        int r = real * c.real - image * c.image;
        int i = real * c.image + image * c.real;
        real = r;
        image = i;
        return *this;}
void display()
{
    cout<<real<<" "<<image<<"i"<<endl;
}


};

int main()
{
Complex i1(2,3);
Complex i2(3,4);
Complex i3=i1.operator+(i2);
Complex i4=i1.operator-(i2);
    cout<<"i1- ";i1.display();
     cout<<"i2 - ";i2.display();
     cout<<"i3=i1+i2 - ";i3.display();
    cout<<"i4=i1-i2 - ";i4.display();

    i1 += i2;
    i2 *= Complex(1, 2);
    cout<<"i1=i1+i2 - "; i1.display();
    cout<<"i2*=(1,2) - ";i2.display();
}
