#include <iostream>
using namespace std;

int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}

void PrintPowers(int number)
{
    cout << number * number << endl;
    cout << number * number * number << endl;
    cout << number * number * number * number << endl;
}

int main() {
    PrintPowers(ReadNumber());
    return 0;
}