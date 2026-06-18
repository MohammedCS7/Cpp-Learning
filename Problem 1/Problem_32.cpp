#include <iostream>

using namespace std;

int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}

int ReadPower()
{
    int power;

    cout << "Enter Power : " << endl;
    cin >> power;

    return power;
}

void ReadPowerAndNumber(int& number, int& power)
{
    number = ReadNumber();
    power = ReadPower();
}

int GetPower(int number, int power)
{
    int result = 1;
    if (power == 0)
        return 1;
    for (int i = 1; i <= power; i++)
    {
        result *= number;
    }
    return result;
}
void PrintPowers(int number,int power)
{
    cout << "The power of " << power << " for number " << number << " is : " << GetPower(number, power) << endl;
}

int main() {
    int number, power;
    ReadPowerAndNumber(number, power);
    PrintPowers(number,power);
    return 0;
}