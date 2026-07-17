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

void FillArrayWithMonthDays(int year, int monthsDays[12])
{
    for (int i = 1; i <= 12; i++)
    {
        monthsDays[i - 1] = GetMonthDays(year, i);
    }
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

Date ReadDate()
{
    Date date;
    date.year = ReadYear();
    date.month = ReadMonth();
    date.day = ReadDay(date.year, date.month);
    return date;
}

int GetDayOrder(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

    return d;
}

int GetTotalDays(int year, int month, int days)
{
    int total = 0;
    for (int i = 1; i < month; i++)
    {
        total += GetMonthDays(year, i);
    }
    return total += days;
}

void GetDateFromTotalDays(int year, int month, int totalDays)
{
    int day = totalDays;
    for (int i = 1; i < month; i++)
    {
        day -= GetMonthDays(year, i);
    }
    cout << "Date For [" << totalDays << "] is : " << day << "/" << month << "/" << year << endl;
}

Date GetDateFromTotalDays(int year, int totalDays)
{
    int day = totalDays;
    Date date;
    int i = 1;
    while (true)
    {
        int monthDays = GetMonthDays(year, i);
        if (day > monthDays)
        {
            day -= monthDays;
            i++;
        }
        else
            break;

    }
    date.year = year;
    date.month = i;
    date.day = day;
    return date;
}

Date GetDateFromTotalDays(int year, int yearDays[12], int totalDays)
{
    Date date;

    int i = 0;
    while (true)
    {
        int currentMonthDays = yearDays[i];
        if (totalDays > currentMonthDays)
        {
            totalDays -= currentMonthDays;
            i++;
        }
        else
            break;
    }
    date.day = totalDays;
    date.month = i + 1;
    date.year = year;
    return date;
}

Date GetDateAfterAdding(Date& date, int addedDays)
{
    int remDays = GetTotalDays(date.year, date.month, date.day) + addedDays;
    while (true)
    {
        int currentYearDays = GetYearDays(date.year);
        if (remDays >= currentYearDays)
        {
            remDays -= currentYearDays;
            date.year++;
        }
        else
            break;
    }
    return GetDateFromTotalDays(date.year, remDays);
}

Date GetDateAfterAddingTeacherWay(Date& date, int addedDays)
{
    int remDays = GetTotalDays(date.year, date.month, date.day) + addedDays;
    date.month = 1;
    while (true)
    {
        int currentMonth = GetMonthDays(date.year, date.month);
        int currentYear = GetYearDays(date.year);
        if (remDays > currentYear)
        {
            remDays -= currentYear;
            date.year++;
        }
        else if (remDays > currentMonth)
        {
            if (date.month > 12)
            {
                date.month = 1;
                date.year++;
                remDays -= 31;
            }
            else
            {
                remDays -= currentMonth;
                date.month++;
            }
        }
        else
            break;
    }
    date.day = remDays;
    return date;
}


int main() {

    Date oldDate = ReadDate();

    int addedDays = ReadPositiveNumber("How many days to add ? : ");

    Date date = GetDateAfterAddingTeacherWay(oldDate, addedDays);

    printf("\nDate after adding [%d] days is : %d/%d/%d \n", addedDays, date.day, date.month, date.year);


    return 0;
}