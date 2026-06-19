#include <iostream>
using namespace std;

enum DaysOfTheWeek {Sun=1,Mon=2,Tue=3,Wed=4,Thu=5,Fri=6,Sat=7};



int ReadNumberInRange(string message,int from, int to)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < from || number > to);
    return number;
}

DaysOfTheWeek ReadDay()
{
    return (DaysOfTheWeek)ReadNumberInRange("Enter Day Number : (Sun=1,Mon=2,Tue=3,Wed=4,Thu=5,Fri=6,Sat=7) ",1,7);
}

string GetWeekDay(DaysOfTheWeek day)
{
    switch (day)
    {
    case DaysOfTheWeek::Sun:
        return "Sunday";
        
    case DaysOfTheWeek::Mon:
        return "Monday";
        
    case DaysOfTheWeek::Tue:
        return "Tuesday";

    case DaysOfTheWeek::Wed:
        return "Wednesday";
    
    case DaysOfTheWeek::Thu:
        return "Thursday";
    
    case DaysOfTheWeek::Fri:
        return "Friday";
    
    case DaysOfTheWeek::Sat:
        return "Saturday";
    
    default:
        return "Not a Week Day";
    }
}

int main() {

    cout << GetWeekDay(ReadDay()) << endl;

    return 0;
}