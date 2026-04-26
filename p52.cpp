#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    ifstream file;
    file.open("input.txt");

    if(!file)
    {
        cout<<"Error: File could not be opened"<<endl;
        return 0;
    }

    string line;
    int lines = 0, words = 0, characters = 0;
    int blankLines = 0;
    int vowels = 0, consonants = 0;

    int maxLength = 0;
    string longestLine = "";

    while(getline(file, line))
    {
        lines++;

        if(line.length() == 0)
        {
            blankLines++;
        }

        if(line.length() > maxLength)
        {
            maxLength = line.length();
            longestLine = line;
        }

        bool inWord = false;

        for(int i = 0; i < line.length(); i++)
        {
            characters++;

            char ch = line[i];

            if(isalpha(ch))
            {
                ch = tolower(ch);

                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                    vowels++;
                else
                    consonants++;
            }

            if(ch != ' ' && ch != '\t')
            {
                if(!inWord)
                {
                    words++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }

        for(int i = 0, j = line.length()-1; i < j; i++, j--)
        {
            char temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }

        cout<<"Reversed Line: "<<line<<endl;
    }

    file.close();

    cout<<"\nTotal Lines: "<<lines<<endl;
    cout<<"Blank Lines: "<<blankLines<<endl;
    cout<<"Total Words: "<<words<<endl;
    cout<<"Total Characters: "<<characters<<endl;
    cout<<"Vowels: "<<vowels<<endl;
    cout<<"Consonants: "<<consonants<<endl;
    cout<<"Longest Line Length: "<<maxLength<<endl;
    cout<<"Longest Line: "<<longestLine<<endl;

    return 0;
}
