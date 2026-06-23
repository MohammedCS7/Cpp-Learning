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

double GetSqrt(double number)
{
    return pow(number, 0.5);
}

int main() {

    double myNum = ReadNumber("Enter a Number : ");

    cout << "My Sqrt Result : " << GetSqrt(myNum) << endl;

    cout << "C++ Sqrt Result : " << sqrt(myNum) << endl;

    return 0;
}