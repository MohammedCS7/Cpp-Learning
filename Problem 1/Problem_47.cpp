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

int CalcLoanMonths(float loanAmount, float monthlyPayment)
{
    return round(loanAmount / monthlyPayment);
}
int main() {
    float loanAmount = ReadPositiveNumber("Enter Loan Amount : ");
    float monthlyPayment = ReadPositiveNumber("Enter Monthly Payment");
    int months = CalcLoanMonths(loanAmount,monthlyPayment);
    cout << months << " Months" << endl;

    return 0;
}