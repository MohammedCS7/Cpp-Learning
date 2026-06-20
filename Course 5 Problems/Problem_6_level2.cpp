#include <iostream>
using namespace std;

unsigned long long ReadPositiveNumber(string message)
{
    unsigned long long number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}

int CalcSumOfDigits(unsigned long long number)
{
    int sum = 0;
    int remainder=0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        sum += remainder;
    }
    return sum;
}

void PrintResult(int sum)
{
    cout << "Sum Of Digits = " << sum << endl;
}

int main() {


    PrintResult(CalcSumOfDigits(ReadPositiveNumber("Enter Positive Number : ")));
    
    return 0;
}