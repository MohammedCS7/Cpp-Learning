#include <iostream>
#include <cmath>
using namespace std;

float ReadPositiveNumber(string message)
{
    float number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);
    return number;
}

int CalcMonthlyPayment(float loanAmount, int months)
{
    return loanAmount / months;
}
int main() {
    float loanAmount = ReadPositiveNumber("Enter Loan Amount : ");
    int months = ReadPositiveNumber("Enter Months : ");
    float monthlyPayment = CalcMonthlyPayment(loanAmount, months);
    cout << monthlyPayment << endl;

    return 0;
}