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

void PrintNumberInOrder(int number)
{
    int rem;
    number = ReverseNumber(number);
    while (number > 0)
    {
        rem = number % 10;
        number /= 10;
        cout << rem << endl;
    }
}

int main() {

    PrintNumberInOrder(ReadPositiveNumber("Enter Number : "));

    return 0;
}