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

int ReverseNumber(int number)
{
    int rev = 0;
    int rem;
    while (number > 0)
    {
        rem = number % 10;
        number /= 10;
        rev = rev * 10 + rem;
    }
    return rev;
}

void PrintResult(int number)
{
    cout << "Reverse is:\n" << number << endl;
}

int main() {

    PrintResult(ReverseNumber(ReadPositiveNumber("Enter Number : ")));

    return 0;
}