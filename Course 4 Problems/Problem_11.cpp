#include <iostream>
using namespace std;
void ReadNumbers(int& num1 , int& num2)
{
    cout << "Enter Number 1 : " << endl;
    cin >> num1;

    cout << "Enter Number 2 : " << endl;
    cin >> num2;
}
int GetMaxNumber(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}
void PrintMaxNumber(int max)
{
    cout << "\nThe Max Number is : " << max << endl;
}
int main() {
    int num1, num2;
    ReadNumbers(num1, num2);
    PrintMaxNumber(GetMaxNumber(num1, num2));
    return 0;
}