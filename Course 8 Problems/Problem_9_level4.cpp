#include <iostream>
#include <iomanip>

using namespace std;

void PrintLine(string str, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << str;
    }
}

enum enDays { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6 };
enum enMonths { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

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

int ReadYear()
{
    return ReadPositiveNumber("Please enter a year : ");
}

int GetDayOrder(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;

    int d = (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;

    return d;
}

enDays GetWeekDay(int dayOrder)
{
    return (enDays)dayOrder;
}

string GetWeekDayName(enDays day)
{
    static const string days[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return days[day];
}

enMonths GetYearMonth(int month)
{
    return (enMonths)month;
}

string GetMonthName(enMonths month)
{
    static const string months[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    return months[month];
}

void PrintMonthCalendar(int year, int month)
{
    int days = GetMonthDays(year, month);
    PrintLine("_", 17);
    cout << GetMonthName(GetYearMonth(month));
    PrintLine("_", 17);
    cout << endl << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << setw(5) << GetWeekDayName(GetWeekDay(i));
    }
    cout << endl;
    int firstDay = GetDayOrder(year,month, 1);
    int index = 0;
    int dayCounter = 1;
    while (index != firstDay)
    {
        cout << setw(5) << " ";
        index++;
    }
    do
    {
        if (index++ < 7)
        {
            cout << setw(5) << dayCounter++;
        }
        else
        {
            cout << endl;
            index = 0;
        }

    } while (dayCounter <= days);
    cout << endl;
    PrintLine("_", 37);
    cout << endl << endl;

}


void PrintYearCalender(int year)
{
    cout << "\n\n";
    PrintLine("_", 37);
    cout << "\n\n";
    cout << setw(20) << "Calendar : " << year << "\n";
    PrintLine("_", 37);
    cout << "\n\n";
    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalendar(year, i);
    }
}

int main() {

    

    PrintMonthCalendar(ReadYear());


    return 0;
}