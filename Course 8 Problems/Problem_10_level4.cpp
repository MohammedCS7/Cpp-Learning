#include <iostream>
using namespace std;

int ReadPositiveNumber(string message)
{
    int num;
    do
    {
        cout << message;
        cin >> num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << message;
            cin >> num;
        }
    } while (num < 0);
    return num;
}

int ReadNumberInRange(string message, int from, int to)
{
    int num;
    do
    {
        cout << message;
        cin >> num;
    } while (num < from || num > to);
    return num;
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

int ReadYear()
{
    return ReadPositiveNumber("Please enter a year : ");
}

int ReadMonth()
{
    return ReadNumberInRange("Please enter a month : ", 1, 12);
}

int ReadDay(int year,int month)
{
    return ReadNumberInRange("Please enter a day : ", 1, GetMonthDays(year,month));
}

int GetDayOrder(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

    return d;
}

int GetTotalDays(int year,int month,int days)
{
    int total = 0;
    for (int i = 1; i < month; i++)
    {
        total += GetMonthDays(year, i);
    }
    return total += days;
}


int main() {

    int year = ReadYear();
    cout << endl;
    int month = ReadMonth();
    cout << endl;
    int day = ReadDay(year,month);
    cout << endl;

    cout << "Number of Days From the begining of the year is : " << GetTotalDays(year, month, day) << endl;



    return 0;
}