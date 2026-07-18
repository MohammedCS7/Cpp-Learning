#include <iostream>
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

//Problem 20 Level4 :

void IncreaseDateByXDays(Date& date,int days)
{
    for (int i = 0; i < days; i++)
    {
        IncrementDateByOne(date);
    }
}

//Problem 21 Level4 :

void IncreaseDateByWeek(Date& date)
{
    IncreaseDateByXDays(date, 7);
}

//Problem 22 Level4 :

void IncreaseDateByXWeeks(Date& date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        IncreaseDateByWeek(date);
    }
}

//Problem 23 Level4 :

void IncreaseDateByMonth(Date& date)
{
    if (IsLastMonth(date))
    {
        date.month = 1;
        date.year++;
    }
    else if (date.day == 31 || (date.month == 1 && (date.day == 29 || date.day == 30)))
    {
        date.month++;
        date.day = GetMonthDays(date.year, date.month);
    }
    else
        date.month++;
}

void IncreaseDateByMonthUsingClamping(Date& date)
{
    if (IsLastMonth(date))
    {
        date.month = 1;
        date.year++;
    }
    else
        date.month++;

    int maxDays = GetMonthDays(date.year, date.month);
    if (date.day > maxDays)
    {
        date.day = maxDays;
    }

}

//Problem 24 Level4 :

void IncreaseDateByXMonths(Date& date, int months)
{
    for (int i = 0; i < months; i++)
    {
        IncreaseDateByMonth(date);
    }
}

//Problem 25 Level4 : 

void IncreaseDateByYear(Date& date)
{
        date.year++;

        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
}

//Problem 26 Level4 :

void IncreaseDateByXYears(Date& date, int years)
{
    for (int i = 0; i < years; i++)
    {
        IncreaseDateByYear(date);
    }
}

//Problem 27 Level4 :

void IncreaseDateByXYearsFaster(Date& date, int years)
{
        date.year += years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
}

//Problem 28 Level4 :

void IncreaseDateByDecade(Date& date)
{
    IncreaseDateByXYears(date, 10);
}


//Problem 29 Level4 :

void IncreaseDateByXDecades(Date& date, int decades)
{
    for (int i = 0; i < decades; i++)
    {
        IncreaseDateByDecade(date);
    }
}

//Problem 30 Level4 :

void IncreaseDateByXDecadesFaster(Date& date, int decades)
{
    int years = decades * 10;
        date.year += years;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
}

//Problem 31 Level4 :

void IncreaseDateByCentury(Date& date)
{
    IncreaseDateByXDecades(date,10);
}

//Problem 32 Level4 :

void IncreaseDateByMillenium(Date& date)
{
        date.year += 1000;
        int maxDays = GetMonthDays(date.year, date.month);
        if (date.day > maxDays)
        {
            date.day = maxDays;
        }
}

void PrintDate(Date date)
{
    printf("%d/%d/%d\n", date.day, date.month, date.year);
}


int main() {


    Date date = ReadDate();

    cout << "\n\nDate After : \n\n";

    IncrementDateByOne(date);

    cout << "Date after adding one day is : ";

    PrintDate(date);

    cout << "Date after adding 10 days is : ";

    IncreaseDateByXDays(date, 10);

    PrintDate(date);

    cout << "Date after adding one week is : ";

    IncreaseDateByWeek(date);

    PrintDate(date);

    cout << "Date after adding 10 weeks is : ";

    IncreaseDateByXWeeks(date, 10);

    PrintDate(date);

    cout << "Date after adding one month is : ";

    IncreaseDateByMonth(date);

    PrintDate(date);

    cout << "Date after adding 5 months is : ";

    IncreaseDateByXMonths(date, 5);

    PrintDate(date);

    cout << "Date after adding one year is : ";

    IncreaseDateByYear(date);

    PrintDate(date);

    cout << "Date after adding 10 years is : ";

    IncreaseDateByXYears(date, 10);

    PrintDate(date);

    cout << "Date after adding 10 years (faster) is : ";

    IncreaseDateByXYearsFaster(date, 10);

    PrintDate(date);

    cout << "Date after adding one decade is : ";

    IncreaseDateByDecade(date);

    PrintDate(date);

    cout << "Date after adding 10 decades is : ";

    IncreaseDateByXDecades(date, 10);

    PrintDate(date);

    cout << "Date after adding 10 decades (faster) is : ";

    IncreaseDateByXDecadesFaster(date, 10);

    PrintDate(date);

    cout << "Date after adding one century is : ";

    IncreaseDateByCentury(date);

    PrintDate(date);

    cout << "Date after adding one millenium is : ";

    IncreaseDateByMillenium(date);

    PrintDate(date);

    return 0;
}