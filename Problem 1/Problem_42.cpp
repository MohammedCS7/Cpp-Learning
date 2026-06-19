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

Duration ReadDuration(int a, int b , int c , int d)
{
    Duration time;

    
    time.days = a;

    
    time.hours = b;

    
    time.minutes = c;

    
    time.seconds = d;

    return time;
}

int CalcDurationInSec(Duration time)
{
    int totalSec = time.days * 86400 + time.hours * 3600 + time.minutes * 60 + time.seconds;
    return totalSec;
}

void PrintDuration(int totalSec)
{
    cout << totalSec << " Seconds." << endl;
}

int main() {
    int a = ReadPositiveNumber("Enter Number of Days : ");
    int b = ReadPositiveNumber("Enter Number of Hours : ");
    int c = ReadPositiveNumber("Enter Number of Minutes : ");
    int d = ReadPositiveNumber("Enter Number of Seconds : ");

    PrintDuration(CalcDurationInSec(ReadDuration(a,b,c,d)));

    return 0;
}