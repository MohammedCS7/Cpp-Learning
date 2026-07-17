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

int GetYearDays(int year)
{
    return IsLeapYear(year) ? 366 : 365;
}

int GetYearHours(int year)
{
    return GetYearDays(year) * 24;
}

int GetYearMinutes(int year)
{
    return GetYearHours(year) * 60;
}

int GetYearSeconds(int year)
{
    return GetYearMinutes(year) * 60;
}

void PrintTimeOfYear(int year,int days,int hours,int minutes,int seconds)
{
    cout << "Number of Days    in Year [" << year << "] is : " << days << endl;
    cout << "Number of Hours   in Year [" << year << "] is : " << hours << endl;
    cout << "Number of Minutes in Year [" << year << "] is : " << minutes << endl;
    cout << "Number of Seconds in Year [" << year << "] is : " << seconds << endl;;
}

int main() {

    int year = ReadYear();
    PrintTimeOfYear(year, GetYearDays(year), GetYearHours(year), GetYearMinutes(year), GetYearSeconds(year));

    return 0;
}