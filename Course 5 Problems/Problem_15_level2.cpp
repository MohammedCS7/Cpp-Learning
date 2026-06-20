#include <iostream>
using namespace std;

int ReadPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

void PrintRegularPattern(int number)
{
    cout << "\n";
    
    int type = int('A');
    for (int i = type; i <= type+number-1; i++)
    {
        for (int j = 0; j <= i-type; j++)
        {
            cout << char(i);
        }
       
        cout << "\n";
    }
}

void PrintRegularPatternTeacherWay(int number)
{
    cout << "\n";
    for (int i = 64; i <= 64 + number; i++)
    {
        for (int j = 0; j < number - (number + 64 - i); j++)
        {
            cout << char(i);
        }

        cout << "\n";
    }
}

int main() {

    PrintRegularPattern(ReadPositiveNumber("Enter Positive Number : "));

    return 0;
}