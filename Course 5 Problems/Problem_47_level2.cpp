#include <iostream>
#include <cmath>
using namespace std;

double ReadNumber(string message)
{
    double number;
    cout << message << endl;
    cin >> number;
    return number;
}

double GetFraction(double number)
{
    return number - int(number);
}

double GetRound(double number)
{
    /*int rem = (int)(number * 10) % 10;
    if (rem >= 5)
        return (int)number + 1;
    if (rem < 5 && rem > -5)
        return (int)number;
    if (rem <= -5 )
        return (int)number - 1;*/

    int intNum = int(number);
    double frac = GetFraction(number);

    if (abs(frac) >= 0.5)
    {
        if (number > 0)
            return ++intNum;
        else
            return --intNum;
    }
    else
        return intNum;
}

int main() {

    double myNum = ReadNumber("Enter a Number : ");

    cout << "My Round Result : " << GetRound(myNum) << endl;

    cout << "C++ Round Result : " << round(myNum) << endl;

    return 0;
}