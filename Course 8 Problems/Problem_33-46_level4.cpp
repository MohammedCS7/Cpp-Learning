#include <iostream>
#include "Date.h"

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

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

int GetYearDays(int year)
{
    return IsLeapYear(year) ? 366 : 365;
}

int ReadYear()
{
    return ReadPositiveNumber("Please enter a year : ");
}

int ReadMonth()
{
    return ReadNumberInRange("Please enter a month : ", 1, 12);
}

int ReadDay(int year, int month)
{
    return ReadNumberInRange("Please enter a day : ", 1, GetMonthDays(year, month));
}

int GetTotalDays(Date date)
{
    int total = 0;
    for (int i = 1; i < date.month; i++)
    {
        total += GetMonthDays(date.year, i);
    }
    return total += date.day;
}

Date ReadDate()
{
    Date date;
    date.year = ReadYear();
    date.month = ReadMonth();
    date.day = ReadDay(date.year, date.month);
    cout << "\n\n";
    return date;
}

bool IsDateLower(Date date1, Date date2)
{
    return (date1.year != date2.year) ? date1.year < date2.year : GetTotalDays(date1) < GetTotalDays(date2);
}

bool IsDateEqual(Date date1, Date date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}


bool IsLastDay(Date date)
{
    return (date.day == GetMonthDays(date.year, date.month));
}

bool IsLastMonth(Date date)
{
    return date.month == 12;
}

//Problem 33 Level4 :

Date DecrementDateByOne(Date date)
{
    if (date.day == 1 && date.month == 1)
    {
        date.month = 12;
        date.year--;
        date.day = GetMonthDays(date.year, date.month);
    }
    else if (date.day == 1)
    {
        date.month--;
        date.day = GetMonthDays(date.year, date.month);
    }
    else
    {
        date.day--;
    }
    return date;
}

//Problem 34 Level4 :

Date DecreaseDateByXDays(Date date, int days)
{
    for (int i = 0; i < days; i++)
    {
        date = DecrementDateByOne(date);
    }
    return date;
}

//Problem 35 Level4 : 

Date DecreaseDateByWeek(Date date)
{
    return DecreaseDateByXDays(date, 7);
}

//Problem 36 Level4 :

Date DecreaseDateByXWeeks(Date date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        date = DecreaseDateByWeek(date);
    }
    return date;
}

//Problem 37 Level4 : 

Date DecreaseDateByMonth(Date date)
{
    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
        date.month--;

    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }
    return date;
}

//Problem 38 Level4 :

Date DecreaseDateByXMonths(Date date, int months)
{
    for (int i = 0; i < months; i++)
    {
        date = DecreaseDateByMonth(date);
    }
    return date;
}

//Problem 39 Level4 : 

Date DecreaseDateByYear(Date date)
{
    date.year--;

    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }

    return date;
}

//Problem 40 Level4 :

Date DecreaseDateByXYears(Date date, int years)
{
    for (int i = 0; i < years; i++)
    {
        date = DecreaseDateByYear(date);
    }
    return date;
}

//Problem 41 Level4 :

Date DecreaseDateByXYearsFaster(Date date, int years)
{
    date.year -= years;
    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }
    return date;
}

//Problem 42 Level4 :

Date DecreaseDateByDecade(Date date)
{
    return DecreaseDateByXYears(date, 10);
}


//Problem 43 Level4 :

Date DecreaseDateByXDecades(Date date, int decades)
{
    for (int i = 0; i < decades; i++)
    {
        date = DecreaseDateByDecade(date);
    }
    return date;
}

//Problem 44 Level4 :

Date DecreaseDateByXDecadesFaster(Date date, int decades)
{
    int years = decades * 10;
    date.year -= years;
    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }
    return date;
}

//Problem 45 Level4 :

Date DecreaseDateByCentury(Date date)
{
    return DecreaseDateByXDecades(date, 10);
}

//Problem 46 Level4 :

Date DecreaseDateByMillenium(Date date)
{
    date.year -= 1000;
    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }
    return date;
}


void PrintDate(Date date)
{
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}

int main() {


    Date date = ReadDate();

    cout << "\n\nDate After : \n\n";

    date = DecrementDateByOne(date);

    cout << "Date after substracting one day is : ";

    PrintDate(date);

    cout << "Date after substracting 10 days is : ";

    date = DecreaseDateByXDays(date, 10);

    PrintDate(date);

    cout << "Date after substracting one week is : ";

    date = DecreaseDateByWeek(date);

    PrintDate(date);

    cout << "Date after substracting 10 weeks is : ";

    date = DecreaseDateByXWeeks(date, 10);

    PrintDate(date);

    cout << "Date after substracting one month is : ";

    date = DecreaseDateByMonth(date);

    PrintDate(date);

    cout << "Date after substracting 5 months is : ";

    date = DecreaseDateByXMonths(date, 5);

    PrintDate(date);

    cout << "Date after substracting one year is : ";

    date = DecreaseDateByYear(date);

    PrintDate(date);

    cout << "Date after substracting 10 years is : ";

    date = DecreaseDateByXYears(date, 10);

    PrintDate(date);

    cout << "Date after substracting 10 years (faster) is : ";

    date = DecreaseDateByXYearsFaster(date, 10);

    PrintDate(date);

    cout << "Date after substracting one decade is : ";

    date = DecreaseDateByDecade(date);

    PrintDate(date);

    cout << "Date after substracting 10 decades is : ";

    date = DecreaseDateByXDecades(date, 10);

    PrintDate(date);

    cout << "Date after substracting 10 decades (faster) is : ";

    date = DecreaseDateByXDecadesFaster(date, 10);

    PrintDate(date);

    cout << "Date after substracting one century is : ";

    date = DecreaseDateByCentury(date);

    PrintDate(date);

    cout << "Date after substracting one millenium is : ";

    date = DecreaseDateByMillenium(date);

    PrintDate(date);

    return 0;
}