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

int GetFreqNumber(int number,int digit)
{
    int rem;
    int freqCounter=0;
    while (number > 0)
    {
        rem = number % 10;
        number /= 10;
        if (rem == digit)
            freqCounter++;
    }
    return freqCounter;
}

void PrintResult(int digit, int freq)
{
    cout << "\nDigit " << digit << " Frequency is " << freq << " Time(s)." << endl;
}

int main() {
    
    int number = ReadPositiveNumber("Enter Your Number : ");
    int digit = ReadPositiveNumber("Enter Your Digit : ");

    PrintResult(digit, GetFreqNumber(number, digit));
    return 0;
}