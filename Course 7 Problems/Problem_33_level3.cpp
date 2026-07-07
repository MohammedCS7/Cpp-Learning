#include <iostream>
#include <string>

using namespace std;

string ReadSentence(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

bool IsVowel(char ch)
{
    switch (ch)
    {
    case 'a' : case 'A':
    case 'e' : case 'E':
    case 'i' : case 'I':
    case 'o' : case 'O':
    case 'u' : case 'U':
        return true;
    default :
        return false;
    }
}

short GetVowelsCount(string sen)
{
    short counter = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if(IsVowel(sen[i]))
            counter++;
    }
    return counter;
}

void PrintVowelResult(short vowNum)
{
    cout << "Number of vowels is : " << vowNum << endl;
}

int main() {

    string sen = ReadSentence("Please Enter a Sentence : ");

    PrintVowelResult(GetVowelsCount(sen));



    return 0;
}