#include <iostream>
using namespace std;

enum PerfectNotPerfect {Perfect=1,NotPerfect=2};

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

PerfectNotPerfect CheckIsPerfect(int number)
{
    int sum = 0;
    if (number <= 5)
        return PerfectNotPerfect::NotPerfect;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
            sum += i;
        if (sum > number)
            return PerfectNotPerfect::NotPerfect;
    }
    if (sum == number)
        return PerfectNotPerfect::Perfect;
    else
        return PerfectNotPerfect::NotPerfect;
}

void PrintResult(int number)
{
    if (CheckIsPerfect(number) == PerfectNotPerfect::Perfect)
        cout << number << " is Perfect" << endl;
    else
        cout << number << " is not Perfect" << endl;
}

int main() {

    PrintResult(ReadPositiveNumber("Enter your Number : "));


    return 0;
}