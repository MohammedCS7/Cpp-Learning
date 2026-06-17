#include <iostream>
using namespace std;

enum OddOrEven { Odd = 1, Even = 2 };
int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}
OddOrEven CheckOddOrEven(int number)
{
    if (number % 2 == 0)
        return OddOrEven::Even;
    else
        return OddOrEven::Odd;
}
int SumEvenNumbersFromOneToNumberUsingFor(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i++)
    {
        if (CheckOddOrEven(i) == OddOrEven::Even)
            sum += i;
    }
    return sum;
}

void PrintResult(int sum)
{
    cout << "The sum is : " << sum << endl;
}
int main() {

    PrintResult(SumEvenNumbersFromOneToNumberUsingFor(ReadNumber()));
    return 0;
}