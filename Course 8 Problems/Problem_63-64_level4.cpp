#include <iostream>
#include <string>
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

bool IsLastDay(Date date)
{
    return (date.day == GetMonthDays(date.year, date.month));
}

bool IsLastMonth(Date date)
{
    return date.month == 12;
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

string ReadStringDate()
{
    string dateLine;
    cout << "Enter a Date (dd/mm/yyyy) : ";
    getline(cin >> ws, dateLine);
    return dateLine;
}

bool IsValidDate(Date date)
{
    return (date.year > 0 && date.month <= 12 && date.month > 0 && date.day <= GetMonthDays(date.year, date.month) && date.day > 0);
}

//Problem 63 Level 4 :

Date StringToDate(string dateLine)
{
    Date date;

    string dates[3];

    int datesIndex = 0;

    int pos = 0;

    while ((pos = dateLine.find("/")) != string::npos)
    {
        dates[datesIndex++] = dateLine.substr(0, pos);
        dateLine.erase(0, pos+1);
    }

    dates[datesIndex] = dateLine;

    date.day = stoi(dates[0]);
    date.month = stoi(dates[1]);
    date.year = stoi(dates[2]);

    return date;
}

//Problem 64 Level 4 :

string DateToString(Date date)
{
    return to_string(date.day) + '/' + to_string(date.month) + '/' + to_string(date.year);
}

void PrintDate(Date date)
{
    printf("\nDay:%d\nMonth:%d\nYear:%d\n", date.day, date.month, date.year);
}

int main() {

    string dateLine = ReadStringDate();

    Date date = StringToDate(dateLine);

    PrintDate(date);

    cout << "\nYou Entered : " << DateToString(date) << endl;
    

    return 0;
}