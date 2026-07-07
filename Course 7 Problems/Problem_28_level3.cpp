#include <iostream>
#include <string>

using namespace std;

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

char InvertCharCase(char ch)
{
    if (ch >= 65 && ch <= 90)
        return ch + 32;
    else if (ch >= 97 && ch <= 122)
        return ch - 32;
    else
        return ch;
}

string InvertSentenceCase(string sen)
{
    for (int i = 0; i < sen.length(); i++)
    {
        sen.at(i) = InvertCharCase(sen.at(i));
    }
    return sen;
}

int main() {

    string str = ReadString("Please Enter a String : ");

    cout << "String after inverting all letters case : \n" << InvertSentenceCase(str) << endl;

    return 0;
}