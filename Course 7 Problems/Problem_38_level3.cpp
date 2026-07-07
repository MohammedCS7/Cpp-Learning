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

string TrimLeft(string sentence)
{
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            return sentence.substr(i, sentence.length() - i);
        }
    }
    return "";
}

string TrimRight(string sentence)
{
    while (!sentence.empty() && sentence.back() == ' ')
    {
        sentence.pop_back();
    }
    return sentence;
}

string TrimAll(string sentence)
{
    return TrimLeft(TrimRight(sentence));
}

void PrintTrims(string rTrimmed, string lTrimmed, string allTrimmed)
{
    cout << "Trim Left  : " << lTrimmed << endl;
    cout << "Right Trim : " << rTrimmed << endl;
    cout << "Trim       : " << allTrimmed << endl;
}

int main() {

    string sentence = ReadString("Please Enter Your Sentence : ");

    PrintTrims(TrimRight(sentence), TrimLeft(sentence), TrimAll(sentence));

    return 0;
}