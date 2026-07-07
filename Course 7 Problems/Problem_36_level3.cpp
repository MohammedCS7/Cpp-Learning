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

short GetWordsNum(string sen)
{
    short counter = 0;
    sen.append(" ");
    short wordStart = 0;
    for (size_t i = 0; i < sen.length();i++)
    {
        if (sen[wordStart] == ' ')
            wordStart++;
        else if (sen[i] == ' ' && sen[wordStart] != ' ')
        {
            counter++;
            wordStart = i;
        }
    }
    return  counter;
}

short GetWordsNumTeacherStyle(string sen)
{
    string delim = " ";
    string word;
    short counter = 0;
    short pos;
    while ((pos = sen.find(delim)) != std::string::npos)
    {
        word = sen.substr(0, pos);
        if (word != "")
        {
            counter++;
        }
        sen.erase(0, pos + delim.length());
    }
    if (sen != "")
        counter++;
    return counter;
}

void PrintWordsCount(short count)
{
    cout << "The number of words in your string is : " << count << endl;
}

int main() {

    string sen = ReadSentence("Please Enter a Sentence : ");

    PrintWordsCount(GetWordsNum(sen));



    return 0;
}