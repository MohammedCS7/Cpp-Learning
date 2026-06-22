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

double GetAbs(double number)
{
    if (number < 0)
        return number * -1;
    return number;
}

int main() {

    double myNum = ReadNumber("Enter a Number : ");

    cout << "My abs Result : " << GetAbs(myNum) << endl;

    cout << "C++ abs Result : " << abs(myNum) << endl;

    return 0;
}