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
    if (month < 1 || month > 12)
        return 0;
    if (month == 2)
        return IsLeapYear(year) ? 29 : 28;
    int bigMonths[7] = { 1,3,5,7,8,10,12 };
    for (int i = 0; i < 7; i++)
    {
        if (bigMonths[i] == month)
            return 31;
    }

}

int GetMonthHours(int year,int month)
{
    return GetMonthDays(year,month) * 24;
}

int GetMonthMinutes(int year,int month)
{
    return GetMonthHours(year,month) * 60;
}

int GetMonthSeconds(int year,int month)
{
    return GetMonthMinutes(year,month) * 60;
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

    PrintTimeOfYear(month, GetMonthDays(year,month), GetMonthHours(year,month), GetMonthMinutes(year,month), GetMonthSeconds(year,month));

    return 0;
}