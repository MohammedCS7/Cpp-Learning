#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string message)
{
    float number;

    cout << message << endl;
    cin >> number;
    
    return number;
}

float GetPercentage(float totalSales)
{
    if (totalSales >= 1000000)
        return 0.01;
    else if (totalSales >= 500000)
        return 0.02;
    else if (totalSales >= 100000)
        return 0.03;
    else if (totalSales >= 50000)
        return 0.05;
    else
        return 0;
}

float CalcCommission(float totalSales)
{
    return totalSales * GetPercentage(totalSales);
}

void PrintResult(float totalSales)
{
    cout << "\nYour Commission Percentage is : " << GetPercentage(totalSales) * 100 << "%" << endl;
    cout << "\nAnd your total Commission is : " << CalcCommission(totalSales) << endl;
}

int main() {


    PrintResult(ReadNumber("Enter your total sales : "));

    return 0;
}