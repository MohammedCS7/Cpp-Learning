#include <iostream>
#include <cstdlib>

using namespace std;

enum CharType { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4 };

int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

char GetRandomChar(CharType type)
{
    switch (type)
    {

    case CharType::CapitalLetter:

        return (char)RandomNumber(65, 90);

    case CharType::SmallLetter:
        return (char)RandomNumber(97, 122);

    case CharType::Digit:
        return (char)RandomNumber(48, 57);

    case CharType::SpecialChar:
        return (char)RandomNumber(33, 47);

    }
}

string GenerateWord(CharType type, short length)
{
    string word;

    for (int i = 0; i < length; i++)
    {
        word = word + GetRandomChar(type);
    }

    return word;
}

string GenerateKey(CharType type, short length)
{
    string key = "";

    for (int i = 1; i <= length; i++)
    {
        key = key + GenerateWord(type, 4);
        if (i < length)
            key = key + '-';
    }

    return key;
}

void GenerateKeys(short numKeys)
{
    cout << "\n";
    for (int i = 1; i <= numKeys; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey(CharType::CapitalLetter, 4) << endl;
    }
}

void FillArrayWithKeys(string keys[100], short numKeys)
{
    for (int i = 0; i < numKeys; i++)
    {
        keys[i] = GenerateKey(CharType::CapitalLetter, 4);
    }
}

void PrintArray(string keys[100], short numKeys)
{
    for (int i = 0; i < numKeys; i++)
    {
        cout << "Array[" << i + 1 << "] : " << keys[i] << endl;;
    }
}

int main() {

    srand((unsigned)time(NULL));

    short numKeys = ReadPositiveNumber("Enter Number of Keys : ");

    string keys[100];

    FillArrayWithKeys(keys, numKeys);

    PrintArray(keys, numKeys);

    return 0;
}