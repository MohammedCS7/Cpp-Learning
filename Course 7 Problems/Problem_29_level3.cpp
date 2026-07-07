#include <iostream>
#include <string>

using namespace std;

enum CharType { Small = 1, Capital = 2, All = 3, Other = 4 };

CharType GetCharCase(char ch);

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

short CountLetters(string sen, CharType type = CharType::All)
{
    if (type == CharType::All)
        return sen.length();
    short counter = 0;
        for (int i = 0; i < sen.length(); i++)
        {
            if (GetCharCase(sen[i]) == type)
                counter++;
        }
        return counter;
}

CharType GetCharCase(char ch)
{
    if (ch >= 65 && ch <= 90)
        return CharType::Capital;
    else if (ch >= 97 && ch <= 122)
        return CharType::Small;
    else
        return CharType::Other;
}

short GetSmallLetters(string sen)
{
    short smallCounter = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (islower(sen.at(i)))
            smallCounter++;
    }
    return smallCounter;
}

short GetCapitalLetters(string sen)
{
    short capitalCounter = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (isupper(sen.at(i)))
            capitalCounter++;
    }
    return capitalCounter;
}

void PrintSentenceCounters(short capsCount, short smallCount, short senCount)
{
    cout << "String Length : " << senCount << endl;
    cout << "Capital Letters Count : " << capsCount << endl;
    cout << "Small Letters Count : " << smallCount << endl;
}

int main() {

    string sen = ReadString("Enter Your Sentence : ");

    PrintSentenceCounters(CountLetters(sen,CharType::Capital),CountLetters(sen,CharType::Small),CountLetters(sen));



    return 0;
}