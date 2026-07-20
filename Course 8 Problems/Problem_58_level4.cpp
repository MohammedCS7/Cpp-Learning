#include <iostream>
using namespace std;

enum enDateState { Before = -1, Equal = 0, After = 1 };

struct Date
{
    int day;
    int month;
    int year;
};

struct Period
{
    Date StartDate;
    Date EndDate;
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

int GetAbsoluteDays(Date date)
{
    int total = GetTotalDays(date);
    for (int i = 1; i < date.year; i++)
    {
        total += GetYearDays(i);
    }
    return total;
}

bool IsDateLower(const Date& date1, const Date& date2)
{
    return (date1.year != date2.year) ? date1.year < date2.year : GetTotalDays(date1) < GetTotalDays(date2);
}

bool IsDateEqual(const Date& date1, const Date& date2)
{
    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool IsDateAfter(const Date& date1, const Date& date2)
{
    return !(IsDateLower(date1, date2) || IsDateEqual(date1, date2));
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

Period ReadPeriod()
{
    Period period;

    cout << "Enter Start Date :\n";
    period.StartDate = ReadDate();

    do
    {

        cout << "\nEnter End Date : \n";
        period.EndDate = ReadDate();

    } while (IsDateLower(period.EndDate, period.StartDate));

    return period;
}




short CompareDate(const Date& date1, const Date& date2)
{
    return (IsDateLower(date1, date2)) ? -1 : IsDateEqual(date1, date2) ? 0 : 1;
}

enDateState GetDateCompare(const Date& date1, const Date& date2)
{
    return (enDateState)CompareDate(date1, date2);
}

bool DoesPeriodOverlap(const Period& per1,const Period& per2)
{
    return !(GetDateCompare(per1.StartDate, per2.EndDate) == enDateState::After || GetDateCompare(per2.StartDate, per1.EndDate) == enDateState::After);
}

bool DoesPeriodOverlapAnotherMethod(Period per1, Period per2)
{

    int per1SDays = GetAbsoluteDays(per1.StartDate);
    int per1EDays = GetAbsoluteDays(per1.EndDate);
    int per2SDays = GetAbsoluteDays(per2.StartDate);
    int per2EDays = GetAbsoluteDays(per2.EndDate);

    return((per2SDays <= per1EDays && per2EDays >= per1EDays) || (per1SDays <= per2EDays && per1EDays >= per2EDays));
}

int main() {

    cout << "Enter Period1:" << endl;
    Period period1 = ReadPeriod();

    cout << "\nEnter Period2:" << endl;
    Period period2 = ReadPeriod();

    if (DoesPeriodOverlapAnotherMethod(period1, period2))
    {
        cout << "Yes, Periods Overlap.\n";
    }
    else
    {
        cout << "No, Periods Does NOT Overlap.\n";
    }


    return 0;
}