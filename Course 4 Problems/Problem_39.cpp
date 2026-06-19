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

float CalcRemainder(float total, float paid)
{
    return paid - total;
}

void PrintRemainder(float remainder)
{
    cout << "The Remainder is : " << remainder << endl;
}

int main() {
    float totalBill = ReadPositiveNumber("Enter the Total Bill : ");
    float totalPaid = ReadPositiveNumber("Enter the Cash Paid : ");
    PrintRemainder(CalcRemainder(totalBill,totalPaid));

    return 0;
}