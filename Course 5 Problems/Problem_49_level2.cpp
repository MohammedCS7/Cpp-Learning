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

double GetCeil(double number)
{
    int intNum = int(number);

    if (intNum != number && number > 0)
        return intNum+1;
    else
        return intNum;
}

int main() {

    double myNum = ReadNumber("Enter a Number : ");

    cout << "My Floor Result : " << GetCeil(myNum) << endl;

    cout << "C++ Floor Result : " << ceil(myNum) << endl;

    return 0;
}