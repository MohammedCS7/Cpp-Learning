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

void PrintWordByWord(string sen)
{
    string word;
    sen.append(" ");
    short wordStart = 0;
    for (size_t i = 0; i < sen.length();i++)
    {
        if (sen[wordStart] == ' ')
            wordStart++;
        else if (sen[i] == ' ' && sen[wordStart] != ' ')
        {
            cout << sen.substr(wordStart, i-wordStart) << endl;
            wordStart = i;
        }
    }
}

void PrintEachWordTeacherStyle(string sen)
{
    string delim = " ";
    string word;
    short pos;
    while ((pos = sen.find(delim)) != std::string::npos)
    {
        word = sen.substr(0, pos);
        if (word != " ")
        {
            cout << word << endl;
        }
        sen.erase(0, pos + delim.length());
    }
    if (sen != "")
        cout << sen << endl;
}

int main() {

    string sen = ReadSentence("Please Enter a Sentence : ");

    PrintEachWordTeacherStyle(sen);



    return 0;
}