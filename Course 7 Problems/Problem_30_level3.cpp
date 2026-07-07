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

char ReadChar(string message)
{
    char ch;
    cout << message << endl;
    cin >> ch;
    return ch;
}

short GetCharCount(string sen,char ch)
{
    short count = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen[i] == ch)
            count++;
    }
    return count;
}

void PrintSentenceCounters(char ch,short charCount)
{
    cout << "Letter '" << ch << "' Count = " << charCount << endl;
}

int main() {

    string sen = ReadString("Enter Your Sentence : ");

    char targetChar = ReadChar("Please Enter the Character : ");

    PrintSentenceCounters(targetChar, GetCharCount(sen,targetChar));



    return 0;
}