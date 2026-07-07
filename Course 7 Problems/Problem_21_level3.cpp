#include <iostream>
#include <vector>
#include "Input.h"

using namespace std;

void GetFibonacciSeriesOfNum(vector <int>& series, int num)
{
    series.push_back(1);
    series.push_back(1);
    int prev1 = series.at(0);
    int prev2 = series.at(1);
    for (int i = 2; i < num; i++)
    {
        series.push_back(prev1 + prev2);
        prev1 = prev2;
        prev2 = series.at(i);
    }
}

void PrintFibonacciSeries(vector <int>& series)
{
    for (const int& num : series)
    {
        cout << num << "  ";
    }
    cout << "\n";
}

void PrintFibonacciSeriesUsingLoops(int num)
{
    int prev1 = 1, prev2 = 0,fabNum=1;

    for (int i = 0; i < num; i++)
    {
        cout << fabNum << "    ";
        fabNum = prev2 + prev1;
        prev2 = prev1;
        prev1 = fabNum;
    }
}

int main() {

    vector <int> series;

    int num = Input::ReadIntegerInRange("Enter a number to get the fibonacci series : ", 1, 100);
    
    

    PrintFibonacciSeriesUsingLoops(num);


    return 0;
}