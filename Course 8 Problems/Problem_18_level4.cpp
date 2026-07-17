#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
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

Date GetSystemDate()
{
    Date sDate;

    time_t t = time(0);

    tm* now = localtime(&t);

    sDate.year = now->tm_year + 1900;
    sDate.month = now->tm_mon + 1;
    sDate.day = now->tm_mday;

    return sDate;
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


void IncrementDateByOne(Date& date)
{
    if (IsLastDay(date) && IsLastMonth(date))
    {
        date.day = 1;
        date.month = 1;
        date.year++;
    }
    else if (IsLastDay(date))
    {
        date.month++;
        date.day = 1;
    }
    else
        date.day++;
}

int GetDiffBetweenDates(Date date1, Date date2, bool isEndDayIncluded = false)
{
    int date1Days = GetTotalDays(date1);
    int date2Days = GetTotalDays(date2);
    if (IsDateLower(date1, date2))
    {
        if (date2.year > date1.year)
        {
            for (int i = date1.year; i < date2.year; i++)
            {
                date2Days += GetYearDays(i);
            }
        }
        return isEndDayIncluded ? (date2Days - date1Days + 1) : (date2Days - date1Days);
    }
    return -1;
}

int GetDiffBetweenDatesTeacherWay(Date date1, Date date2)
{
    int diff = 0;
    if (!IsDateLower(date1, date2)) return -1;
    while (IsDateLower(date1, date2))
    {
        diff++;
        IncrementDateByOne(date1);
    }
    return diff;
}

int GetAgeInDays(Date birthDate)
{
    Date today = GetSystemDate();
  
    return GetDiffBetweenDates(birthDate, today);
}

int main() {

    cout << "Please enter you date of birth : \n\n" << endl;

    Date birthDate = ReadDate();

    int ageInDays = GetAgeInDays(birthDate);

    cout << "\n\n";

    cout << "Your Age is : " << ageInDays << endl;


    return 0;
}