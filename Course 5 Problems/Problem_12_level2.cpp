#include <iostream>
using namespace std;

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

void PrintInvertedPattern(int number)
{
    cout << "\n";
    for (int i = number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {

    PrintInvertedPattern(ReadPositiveNumber("Enter Positive Number : "));

    return 0;
}