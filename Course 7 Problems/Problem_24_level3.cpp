#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadSentence(string message)
{
    string sen;
    cout << message << endl;
    getline(cin, sen);
    return sen;
}


string UpperCaseForFirstCharTeacherStyle(string sen)
{
    bool isFirstLetter = true;
    char currentChar;
    for (int i = 0; i < sen.length(); i++)
    {
        currentChar = sen.at(i);
        if (currentChar != ' ' && isFirstLetter)
            sen.at(i) = toupper(sen.at(i));
        isFirstLetter = (currentChar == ' ');
    }
    return sen;
}


string UpperCaseForFirstChar(string sen)
{
    short wordStart = 0;
    sen.append(" ");
    
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen.at(wordStart) == ' ')
            wordStart++;
        else if (sen.at(i) == ' ')
        {
            sen.at(wordStart) = toupper(sen.at(wordStart));
            wordStart = i + 1;
        }
    }
    sen.pop_back();
    return sen;
}

void PrintConversionFromLowtoUpp(string senBefore, string senAfter)
{
    cout << "String Before Conversion : " << senBefore << endl;
    cout << "String After Conversion : " << senAfter << endl;
}

int main() {


    string sentence = ReadSentence("Please enter your sentence : ");

    PrintConversionFromLowtoUpp(sentence, UpperCaseForFirstChar(sentence));


    return 0;
}