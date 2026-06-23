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

double GetFloor(double number)
{
    int intNum = int(number);

    
    
        if (number > 0 || intNum == number)
            return intNum;
    else
        return --intNum;
}

int main() {

    double myNum = ReadNumber("Enter a Number : ");

    cout << "My Floor Result : " << GetFloor(myNum) << endl;

    cout << "C++ Floor Result : " << floor(myNum) << endl;

    return 0;
}