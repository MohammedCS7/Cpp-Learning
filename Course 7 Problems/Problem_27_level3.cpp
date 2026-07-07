#include <iostream>

using namespace std;

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

int main() {

    char ch = ReadChar("Please Enter a Character : ");

    cout << "Char after inverting case : " << InvertCharCase(ch) << endl;

    return 0;
}