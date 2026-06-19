#include <iostream>
using namespace std;

enum MonthOfTheYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };



int ReadNumberInRange(string message, int from, int to)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < from || number > to);
    return number;
}

MonthOfTheYear ReadMonth()
{
    return (MonthOfTheYear)ReadNumberInRange("Enter Month Number : ( Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 ) ", 1, 12);
}

string GetMonth(MonthOfTheYear day)
{
    switch (day)
    {
    case MonthOfTheYear::Jan:
        return "January";

    case MonthOfTheYear::Feb:
        return "February";

    case MonthOfTheYear::Mar:
        return "March";

    case MonthOfTheYear::Apr:
        return "April";

    case MonthOfTheYear::May:
        return "May";

    case MonthOfTheYear::Jun:
        return "June";

    case MonthOfTheYear::Jul:
        return "July";

    case MonthOfTheYear::Aug:
        return "August";

    case MonthOfTheYear::Sep:
        return "September";

    case MonthOfTheYear::Oct:
        return "October";

    case MonthOfTheYear::Nov:
        return "November";

    case MonthOfTheYear::Dec:
        return "December";
    }
}

int main() {

    cout << GetMonth(ReadMonth()) << endl;

    return 0;
}