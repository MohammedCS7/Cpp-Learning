#include <iostream>
using namespace std;

void ReadNumbers(int& num1, int& num2)
{
    cout << "Enter Number 1 : " << endl;
    cin >> num1;

    cout << "Enter Number 2 : " << endl;
    cin >> num2;
}

void SwapTwoNumbers(int& num1, int& num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
}

void PrintNumbers(int num1 , int num2)
{
    cout << "\nThe Numbers are : \n" << num1 << "\n" << num2 << endl;
}

int main() {
    int num1, num2;
    ReadNumbers(num1, num2);
    PrintNumbers(num1, num2);
    cout << "\nSwapping..." << endl;
    SwapTwoNumbers(num1, num2);
    PrintNumbers(num1, num2);
    return 0;
}