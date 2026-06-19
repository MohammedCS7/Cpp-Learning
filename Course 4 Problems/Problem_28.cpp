#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}
int SumOddFromOneToNumber(int number)
{
    int sum = 0;
    for (int i = 1; i <= number; i+=2)
    {
        sum += i;
    }
    return sum;
}
void PrintResult(int sum)
{
    cout << "The sum is : " << sum << endl;
}
int main() {
     
     PrintResult(SumOddFromOneToNumber(ReadNumber()));
    return 0;
}