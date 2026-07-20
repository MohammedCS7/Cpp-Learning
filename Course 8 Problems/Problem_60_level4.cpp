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

bool IsLastDay(Date date)
{
    return (date.day == GetMonthDays(date.year, date.month));
}

bool IsLastMonth(Date date)
{
    return date.month == 12;
}

Date IncrementDateByOne(Date date)
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
    return date;
}

int GetDiffBetweenDatesTeacherWay(Date date1, Date date2, bool isIncluded = false)
{
    int diff = 0;
    if (IsDateLower(date2, date1))
    {
        while (IsDateLower(date2, date1))
        {
            diff--;
            date2 = IncrementDateByOne(date2);
        }
        return isIncluded ? --diff : diff;
    }
    else if (IsDateLower(date1, date2))
    {
        while (IsDateLower(date1, date2))
        {
            diff++;
            date1 = IncrementDateByOne(date1);
        }
        return isIncluded ? ++diff : diff;
    }
    else
        return isIncluded ? 1 : 0;

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


int GetPeriodLength(Period per, bool isIncluded = false)
{
    return GetDiffBetweenDatesTeacherWay(per.StartDate, per.EndDate, isIncluded);
}

int GetPeriodLengthAnotherSolve(Period per, bool isIncluded = false)
{
    int endDays = GetAbsoluteDays(per.EndDate);
    int startDays = GetAbsoluteDays(per.StartDate);
    int perDays = endDays - startDays;
    return isIncluded ? ++perDays : perDays;
}

short CompareDate(const Date& date1, const Date& date2)
{
    return (IsDateLower(date1, date2)) ? -1 : IsDateEqual(date1, date2) ? 0 : 1;
}

enDateState GetDateCompare(const Date& date1, const Date& date2)
{
    return (enDateState)CompareDate(date1, date2);
}

bool IsDateWithInPeriod(Period per, Date date)
{
    int perStart = GetAbsoluteDays(per.StartDate);
    int perEnd = GetAbsoluteDays(per.EndDate);
    int dateDays = GetAbsoluteDays(date);

    return (dateDays >= perStart && dateDays <= perEnd);
}

bool IsDateWithInPeriodAnotherSolve(Period per, Date date)
{
    return !(GetDateCompare(date, per.StartDate) == enDateState::Before || GetDateCompare(date, per.EndDate) == enDateState::After);
}

int main() {

    cout << "Enter Period1:" << endl;
    Period period1 = ReadPeriod();


    cout << "\nEnter Date to Check : " << endl;
    Date date = ReadDate();

    if (IsDateWithInPeriod(period1, date))
    {
        cout << "\nYes, Date is within period.\n";
    }
    else
        cout << "\nNo, Date is NOT within period.\n";


    return 0;
}