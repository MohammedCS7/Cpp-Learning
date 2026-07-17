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

void FillArrayWithMonthDays(int year,int monthsDays[12])
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

void GetDateFromTotalDays(int year, int totalDays)
{
    int day = totalDays;
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
    cout << "Date For [" << totalDays << "] is : " << day << "/" << i << "/" << year << endl;
}

Date GetDateFromTotalDays(int year,int yearDays[12],int totalDays)
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
    date.month = i+1;
    date.year = year;
    return date;
}


int main() {

    int year = ReadYear();
    cout << endl;
    int month = ReadMonth();
    cout << endl;
    int day = ReadDay(year, month);
    cout << endl;

    int totalDays = GetTotalDays(year, month, day);

    int monthsDays[12];
    FillArrayWithMonthDays(year, monthsDays);

    Date date;


    date = GetDateFromTotalDays(year, monthsDays, totalDays);

    printf("\nDate For [%d] is : %d/%d/%d \n", totalDays, date.day, date.month, date.year);


    return 0;
}