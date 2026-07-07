#include <iostream>
#include <string>

using namespace std;

string ReadSentence(string message)
{
    string sen;
    cout << message << endl;
    getline(cin, sen);
    return sen;
}

void PrintFCharInSen(string sen)
{
    short wordStart = 0;
    sen.append(" ");
    
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen.at(wordStart) == ' ')
            wordStart++;
        else if (sen.at(i) == ' ')
        {
            cout << sen.at(wordStart) << endl;
            wordStart = i + 1;
        }

    }
}

int main() {


    string sentence = ReadSentence("Please enter your sentence : ");

    cout << "First Letters of this string : " << endl;
    PrintFCharInSen(sentence);


    return 0;
}