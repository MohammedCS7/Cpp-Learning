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
    return seconds % time;
}

int CalcDaysBySeconds(int seconds)
{
    return seconds / 86400;
}

int CalcSecFromDays(int days)
{
    return days * 86400;
}

int CalcHoursBySeconds(int seconds)
{
   return seconds / 3600;
     
}

int CalcSecFromHours(int hours)
{
    return hours*3600;
}

int CalcMinutesBySeconds(int seconds)
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
    int remainder;

    time.days = CalcDaysBySeconds(seconds);

    remainder = GetRemainder(seconds, 86400);
    time.hours = CalcHoursBySeconds(remainder);
    
    remainder = GetRemainder(remainder, 3600);

    time.minutes = CalcMinutesBySeconds(remainder);

    remainder = GetRemainder(remainder, 60);

    time.seconds = remainder;

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