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

int GetFreqNumber(int number,short digit)
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

void PrintResult(short digit, int freq)
{
    cout << "\nDigit " << digit << " Frequency is " << freq << " Time(s)." << endl;
}

void PrintFreqInAllDigits(int number)
{
    int freq;
    for (int i = 0; i <= 9; i++)
    {
        freq = GetFreqNumber(number, i);
        if(freq > 0)
        PrintResult(i,freq);
    }
}

int main() {
    
    int number = ReadPositiveNumber("Enter Your Number : ");

    PrintFreqInAllDigits(number);
    return 0;
}