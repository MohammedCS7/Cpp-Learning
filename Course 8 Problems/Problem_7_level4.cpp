#include <iostream>

using namespace std;

enum enDays { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6 };

struct Date
{
    int year = 0;
    int month = 0;
    int day = 0;
};

int ReadPositiveNumber(string message)
{
    int num;
    do
    {
        cout << message;
        cin >> num;
    } while (num < 0);
    return num;
}

int ReadNumberInRange(string message,int from,int to)
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

Date ReadDate()
{
    Date date;
    date.year  = ReadPositiveNumber("Enter a Year : ");
    date.month = ReadNumberInRange("Enter a Month : ", 1, 12);
    date.day = ReadNumberInRange("Enter a Day : ", 1, GetMonthDays(date.year, date.month));
    return date;
}

int GetDayOrder(Date date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    
    int d = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

    return d;
}

enDays GetWeekDay(int dayOrder)
{
    return (enDays)dayOrder;
}

string GetWeekDay(enDays day)
{
    string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return days[day];
}

void PrintDateResult(Date date, int order, string day)
{
    cout << "\nDate      : " << date.day << "/" << date.month << "/" << date.year << endl;
    cout << "Day Order : " << order << endl;
    cout << "Day Name  :" << day << endl;
}

int main() {

    Date date = ReadDate();
    int order = GetDayOrder(date);

    PrintDateResult(date, order, GetWeekDay(GetWeekDay(order)));


    return 0;
}