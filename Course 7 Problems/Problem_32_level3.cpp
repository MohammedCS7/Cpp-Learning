#include <iostream>

using namespace std;



char ReadChar(string message)
{
    char ch;
    cout << message << endl;
    cin >> ch;
    return ch;
}

bool IsVowel(char ch)
{
    char vowels[] = { 'a','A','e','E','i','I','o','O','u','U' };
    for (int i = 0; i < 10; i++)
    {
        if (ch == vowels[i])
            return true;
    }
    return false;
}

string GetVowelResult(bool isVowel)
{
    return isVowel ? "A Vowel" : "NOT a Vowel";
}

void PrintVowelResult(char ch,string result)
{
    cout << "Letter '" << ch << "' is " << result << endl;
}

int main() {

    char ch = ReadChar("Please Enter a Character : ");

    PrintVowelResult(ch, GetVowelResult(IsVowel(ch)));



    return 0;
}