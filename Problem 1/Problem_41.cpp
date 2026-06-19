#include <iostream>
#include <cmath>
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

float CalcWeeks(int hours)
{
    float weeks = (float)hours / 24 / 7;
    return round(weeks * 100) / 100;
}

float CalcDays(int hours)
{
    float days = (float)hours / 24 ;
    return round(days * 100) / 100;
}


void PrintTime(float weeks,float days)
{
    cout << endl << weeks << " Weeks." << endl;
    cout << days << " Days." << endl;
}

int main() {
    int hours = ReadPositiveNumber("Enter Hours : ");
    float weeks = CalcWeeks(hours);
    float days = CalcDays(hours);
    PrintTime(weeks,days);

    return 0;
}