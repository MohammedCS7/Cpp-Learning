#include <iostream>
using namespace std;

struct Duration
{
    int days, hours, minutes, seconds;
};

int ReadPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}

int GetRemainder(int seconds, int time)
{
    return seconds -= time;
}

int CalcDaysBySeconds(int seconds)
{
    return seconds / 86400;
}

int CalcSecFromDays(int days)
{
    return days * 86400;
}

int CalcRemainingHoursBySeconds(int seconds)
{
   return seconds / 3600;
     
}

int CalcSecFromHours(int hours)
{
    return hours*3600;
}

int CalcRemainingMinutesBySeconds(int seconds)
{
    return seconds / 60;
}

int CalcSecFromMinutes(int minutes)
{
    return minutes * 60;
}

Duration CalcDuration(int seconds)
{
    Duration time;


    time.days = CalcDaysBySeconds(seconds);


    time.hours = CalcRemainingHoursBySeconds(GetRemainder(seconds, CalcSecFromDays(time.days)));


    time.minutes = CalcRemainingMinutesBySeconds(GetRemainder(GetRemainder(seconds, CalcSecFromDays(time.days)),CalcSecFromHours(time.hours)));


    time.seconds = GetRemainder(GetRemainder(GetRemainder(seconds, CalcSecFromDays(time.days)), CalcSecFromHours(time.hours)),CalcSecFromMinutes(time.minutes));

    return time;
}

int CalcDurationInSec(Duration time)
{
    int totalSec = time.days * 86400 + time.hours * 3600 + time.minutes * 60 + time.seconds;
    return totalSec;
}

void PrintDuration(Duration time)
{
    cout << time.days << " Days." << endl;
    cout << time.hours << " Hours." << endl;
    cout << time.minutes << " Minutes." << endl;
    cout << time.seconds << " Seconds." << endl;
}

int main() {
    int seconds = ReadPositiveNumber("Enter Number of Seconds : ");
    
    PrintDuration(CalcDuration(seconds));

    return 0;
}