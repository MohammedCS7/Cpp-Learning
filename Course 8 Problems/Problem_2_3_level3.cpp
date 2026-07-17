#include <iostream>
using namespace std;

int ReadYear()
{
    int year;
    cout << "Enter Year : ";
    cin >> year;
    return year;
}

bool IsLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

string GetIsLeapYear(bool isLeap)
{
    return isLeap ? "Leap Year" : "Not Leap Year";
}

void PrintLeapResult(string isLeap)
{
    cout << isLeap << endl;
}

int main() {


    PrintLeapResult(GetIsLeapYear(IsLeapYear(ReadYear())));

    return 0;
}