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

char InvertCharCase(char ch)
{
    if (ch >= 65 && ch <= 90)
        return ch + 32;
    else if (ch >= 97 && ch <= 122)
        return ch - 32;
    else
        return ch;
}

//short GetCharCountCaseSense(string sen, char ch)
//{
//    short count = 0;
//    for (int i = 0; i < sen.length(); i++)
//    {
//        if (sen[i] == ch)
//            count++;
//    }
//    return count;
//}

short GetCharCount(string sen, char ch,bool isCaseSensitve = true)
{
    /*short count = 0;
    if (ch >= 65 && ch <= 90)
    {
        count = GetCharCountCaseSense(sen, ch) + GetCharCountCaseSense(sen, ch + 32);
    }
    else if (ch >= 97 && ch <= 122)
    {
        count = GetCharCountCaseSense(sen, ch) + GetCharCountCaseSense(sen, ch - 32);
    }
    else
        count = GetCharCountCaseSense(sen, ch);
    return count;*/

    short count = 0;
    for (int i = 0; i < sen.length(); i++)
    {
        if (ch == sen[i])
            count++;
        else if (InvertCharCase(ch) == sen[i] && !isCaseSensitve)
            count++;
    }
    return count;
}

void PrintCharCountCaseSen(char ch,short charCount)
{
        cout << "Letter '" << ch << "' Count = " << charCount << endl;
}

void PrintCharCountNotCaseSen(char ch, char invCh, short charCount)
{
    cout << "Letter '" << ch << "' Or '" << invCh << "' Count = " << charCount << endl;
}

int main() {

    string sen = ReadString("Enter Your Sentence : ");

    char targetChar = ReadChar("Please Enter the Character : ");

    PrintCharCountCaseSen(targetChar, GetCharCount(sen, targetChar));
    PrintCharCountNotCaseSen(targetChar, InvertCharCase(targetChar), GetCharCount(sen, targetChar, false));



    return 0;
}