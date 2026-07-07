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

string UpperCaseForAllSentence(string sen)
{
    for (int i = 0; i < sen.length(); i++)
    {
        sen.at(i) = toupper(sen.at(i));
    }
    return sen;
}

string LowerCaseForAllSentence(string sen)
{
    for (int i = 0; i < sen.length(); i++)
    {
        sen.at(i) = tolower(sen.at(i));
    }
    return sen;
}

void PrintConversionFromUpptoLow(string sen, string senUpp,string senLow)
{
    cout << "String Before Conversion : " << sen << endl;
    cout << "String After Upper Conversion : " << senUpp << endl;
    cout << "String After Lower Conversion : " << senLow << endl;
}

int main() {


    string sentence = ReadSentence("Please enter your sentence : ");

    PrintConversionFromUpptoLow(sentence, UpperCaseForAllSentence(sentence), LowerCaseForAllSentence(sentence));


    return 0;
}