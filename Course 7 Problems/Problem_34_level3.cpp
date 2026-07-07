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

bool IsVowel(char ch)
{
    switch (ch)
    {
    case 'a': case 'A':
    case 'e': case 'E':
    case 'i': case 'I':
    case 'o': case 'O':
    case 'u': case 'U':
        return true;
    default:
        return false;
    }
}

void PrintVowelsInSentence(string sen)
{
    for (size_t i = 0; i < sen.length(); i++)
    {
        if (IsVowel(sen[i]))
            cout << sen[i] << "    ";
    }
    cout << "\n";
}

int main() {

    string sen = ReadSentence("Please Enter a Sentence : ");

    cout << "Vowels in sentence are : ";
    PrintVowelsInSentence(sen);



    return 0;
}