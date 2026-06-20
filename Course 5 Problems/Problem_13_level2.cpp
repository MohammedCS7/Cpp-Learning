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

void PrintRegularPattern(int number)
{
    cout << "\n";
    for (int i = 1; i <= number; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {

    PrintRegularPattern(ReadPositiveNumber("Enter Positive Number : "));

    return 0;
}