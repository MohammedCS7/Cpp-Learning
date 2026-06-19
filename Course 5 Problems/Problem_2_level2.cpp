#include <iostream>

using namespace std;

enum PrimeNotPrime { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber()
{
    int number = 0;
    do
    {
        cout << "Enter Positive Number : " << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

PrimeNotPrime isPrime(int number)
{
    if (number == 2)
        return PrimeNotPrime::Prime;
    if (number % 2 == 0 || number == 1)
        return PrimeNotPrime::NotPrime;
    int half = number / 2;
    for (int i = 3; i <= half; i += 2)
    {
        if (number % i == 0)
            return PrimeNotPrime::NotPrime;
    }
    return PrimeNotPrime::Prime;
}

void PrintResultFromOneToNumber(int number)
{
    cout << "\n";
    for (int i = 1; i <= number; i++)
    {
        if (isPrime(i) == PrimeNotPrime::Prime)
        {
            cout  << i << endl;
        }
    }
}
int main() {

    PrintResultFromOneToNumber(ReadPositiveNumber());


    return 0;
}