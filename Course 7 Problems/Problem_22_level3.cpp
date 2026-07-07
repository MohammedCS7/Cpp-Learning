#include <iostream>


using namespace std;


void PrintFibonacciSeriesUsingRecursion(int num,int prev1,int prev2)
{
    if (num > 0)
    {
        cout << prev1 << "    ";
        PrintFibonacciSeriesUsingRecursion(num-1, prev1+prev2, prev1);
    }
}

int main() {


    PrintFibonacciSeriesUsingRecursion(10, 1, 0);


    return 0;
}