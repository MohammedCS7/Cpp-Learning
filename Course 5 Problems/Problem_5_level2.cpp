#include <iostream>
#include <string>
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

void PrintReversed(int number)
{
    
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        cout << remainder << endl;
    }

}

int main() {


    PrintReversed(ReadPositiveNumber("Enter Your Digit : "));

    return 0;
}