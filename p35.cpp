#include<iostream>
#include<string.h>
using namespace std;
int superdigit(int n)
{
    if(n<10)
    {return n;}
    int Sum=0;
    while(n>0)
    {
        int c=n%10;
        n=n/10;
        Sum+=c;
    }
    superdigit(Sum);
return Sum;
}


int main()
{
 int sum=0;
string str;

cout<<"Enter String:";
cin>>str;

int len=str.length();
cout<<"String Length:"<<len<<endl;


for(int i=0;i<len;i++)
{
sum=sum+(str[i]-'0');
}
int k;
cout<<endl;
cout<<"How many times it is concatenated:";
cin>>k;
sum=sum*k;
sum=superdigit(sum);
cout<<sum;
return 0;
}