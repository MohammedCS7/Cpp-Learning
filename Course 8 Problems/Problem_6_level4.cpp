#include <iostream>
using namespace std;


int ReadYear()
{
    int year;
    cout << "Enter Year : ";
    cin >> year;
    return year;
}

int ReadMonth()
{
    int month;
    do
    {
        cout << "Enter Month : ";
        cin >> month;
    } while (month < 1 || month > 12);
    return month;
}

bool IsLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int GetMonthDays(int year, int month)
{
    int monthsDays[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? IsLeapYear(year) ? 29 : 28 : monthsDays[month];
}

int GetMonthHours(int year, int month)
{
    return GetMonthDays(year, month) * 24;
}

int GetMonthMinutes(int year, int month)
{
    return GetMonthHours(year, month) * 60;
}

int GetMonthSeconds(int year, int month)
{
    return GetMonthMinutes(year, month) * 60;
}

void PrintTimeOfYear(int month, int days, int hours, int minutes, int seconds)
{
    cout << "\nNumber of Days    in Month [" << month << "] is : " << days << endl;
    cout << "Number of Hours   in Month [" << month << "] is : " << hours << endl;
    cout << "Number of Minutes in Month [" << month << "] is : " << minutes << endl;
    cout << "Number of Seconds in Month [" << month << "] is : " << seconds << endl;;
}

int main() {

    int year = ReadYear();
    int month = ReadMonth();

    PrintTimeOfYear(month, GetMonthDays(year, month), GetMonthHours(year, month), GetMonthMinutes(year, month), GetMonthSeconds(year, month));

    return 0;
}