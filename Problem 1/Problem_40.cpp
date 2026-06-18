#include <iostream>
using namespace std;

float ReadPositiveNumber(string message)
{
    float number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}

float CalcTotalBill(float billValue)
{
    float totalBill = billValue;
    float serviceFee = billValue * 0.10;
    totalBill += serviceFee;
    float salesTax = totalBill * 0.16;
    return totalBill + salesTax;
}

void PrintTotalBill(float totalBill)
{
    cout << "The Total Bill is : " << totalBill << endl;
}

int main() {

    PrintTotalBill(CalcTotalBill(ReadPositiveNumber("Enter Bill Value : ")));

    return 0;
}