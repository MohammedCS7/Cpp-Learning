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

void PrintInvertedPattern(int number)
{
    cout << "\n";
    
    int type = int('a')-1;
    for (int i = type+number; i > type; i--)
    {
        for (int j = 0; j < i-type; j++)
        {
            cout << char(i);
        }
       
        cout << "\n";
    }
}

int main() {

    PrintInvertedPattern(ReadPositiveNumber("Enter Positive Number : "));

    return 0;
}