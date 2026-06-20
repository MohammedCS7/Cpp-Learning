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
    int rev=0;
    int rem;
    while (number > 0)
    {
        rem = number % 10;
        number /= 10;
        rev = rev * 10 + rem;
    }
    return rev;
}

bool isPalindrome(int number)
{
    return (ReverseNumber(number) == number);
}

void PrintResult(int number)
{
    if (isPalindrome(number))
        cout << number << " is a Palindrome Number" << endl;
    else
        cout << number << " is not a Palindrome Number" << endl;
}

int main() {
    PrintResult(ReadPositiveNumber("Enter a positive number : "));
    return 0;
}