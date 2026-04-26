#include<iostream>
#include<string.h>
#include<string>
#include<cctype>
using namespace std;

int main()
{
string str;
cout<<"Enter String: ";
getline(cin,str);

string current_str="";
string arr[str.length()];
int count=0;

for(int i=0;i<str.length();i++)
{
if(str[i]!=' ')
{
current_str+=tolower(str[i]);
}
else
{
arr[count]=current_str;
count++;
current_str="";
}}

arr[count]=current_str;
count++;
current_str="";

for(int j=0;j<count;j++)
{
    cout<<arr[j]<<endl;
}

int f=1;
bool visit[count]={false};

int maxf=0;
string maxword="";

for(int i=0;i<count;i++)
{
    for(int j=i+1;j<count;j++)
{
    if(arr[i]==arr[j] && visit[j]==false )
    {
        f++;
        visit[j]=true;
    }
}
if(visit[i]==false){
 cout<<"frequency of "<<arr[i]<<" is "<<f<<endl;

 if(f>maxf){
    maxf=f;
    maxword=arr[i];
 }

}
    f=1;
}

cout<<"Most frequent word is "<<maxword<<" with frequency "<<maxf<<endl;

int unique=0;
for(int i=0;i<count;i++)
{
    if(visit[i]==false)
    unique++;
}

cout<<"Total unique words: "<<unique<<endl;

}
