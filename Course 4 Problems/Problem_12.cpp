#include <iostream>
using namespace std;
void ReadNumbers(int& num1, int& num2, int& num3)
{
    cout << "Enter Number 1 : " << endl;
    cin >> num1;

    cout << "Enter Number 2 : " << endl;
    cin >> num2;

    cout << "Enter Number 3 : " << endl;
    cin >> num3;
}   
int GetMaxNumber(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}
int GetMaxOfThreeNumbers(int num1, int num2, int num3)
{
    if (num1 > num2 && num1 > num3)
        return num1;
    else if (num2 > num3)
        return num2;
    else
        return num3;
}
int GetMaxNumber(int num1, int num2,int num3)
{
    return GetMaxNumber(GetMaxNumber(num1, num2), num3);
}
void PrintMaxNumber(int max)
{
    cout << "\nThe Max Number is : " << max << endl;
}
int main() {
    int num1, num2,num3;
    ReadNumbers(num1, num2,num3);
    PrintMaxNumber(GetMaxNumber(num1, num2,num3));
    return 0;
}