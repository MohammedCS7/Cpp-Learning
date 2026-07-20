#pragma warning(disable : 4996)
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

void IncrementDateByOneDay(Date& date)
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

//Problem 47 Level4:

int GetDayOrder(Date date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;

    int d = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

    return d;
}
//Problem 49 Level4 :

bool IsWeekEnd(int dayOrder)
{
    return (dayOrder == 5 || dayOrder == 6);
}

int GetDiffBetweenDates(Date date1, Date date2, bool isEndDayIncluded = false)
{
    int days = 0;
    while (IsDateLower(date1, date2))
    {
        days++;
        IncrementDateByOneDay(date1);
    }
    return isEndDayIncluded ? ++days : days;
}

int DaysUntilEndOfVacation(Date vacStart,Date vacEnd)
{
    int vacDays = 0;
    int dayOrder;
    while (IsDateLower(vacStart, vacEnd))
    {
        dayOrder = GetDayOrder(vacStart);
        if (!IsWeekEnd(dayOrder))
        {
            vacDays++;
        }
        IncrementDateByOneDay(vacStart);
    }
    return vacDays;
}

int DaysUntilEndOfVacationAnotherSolve(Date vacStart, Date vacEnd)
{
    int weekends = 0;
    int dayOrder = GetDayOrder(vacStart);
    int vacDays = GetDiffBetweenDates(vacStart, vacEnd);

    for (int i = 0; i < vacDays; i++)
    {
        if (IsWeekEnd(dayOrder++))
            weekends++;
        dayOrder %= 7;
    }

    return vacDays - weekends;
}

string GetWeekDayShortName(int dayOrder)
{
    string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return days[dayOrder];
}

void PrintDate(Date date)
{
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}

void PrintDateByWeekDay(string weekDay, Date date)
{
    cout << weekDay << " , ";
    PrintDate(date);
}


void PrintIsWeekEnd(bool isWeekEnd)
{
    if (isWeekEnd)
        cout << "Yes, it is a week end.\n";
    else
        cout << "No, it is NOT a week end.\n";
}

void PrintIsBusinessDay(bool isBusiness)
{
    if (isBusiness)
        cout << "Yes, it is a business day.\n";
    else
        cout << "No, it is NOT a business day.\n";
}

int main()
{
    cout << "Vacation Starts:\n";
    Date vacStart = ReadDate();
    int vacStartOrder = GetDayOrder(vacStart);

    cout << "\nVacation Ends:\n";
    Date vacEnd = ReadDate();
    int vacEndOrder = GetDayOrder(vacEnd);

    cout << "\nVacation From: ";
    PrintDateByWeekDay(GetWeekDayShortName(vacStartOrder), vacStart);

    cout << "Vacation To: ";
    PrintDateByWeekDay(GetWeekDayShortName(vacEndOrder), vacEnd);

    cout << "\n\nActual Vacation Days is : " << DaysUntilEndOfVacationAnotherSolve(vacStart, vacEnd);

    return 0;
}