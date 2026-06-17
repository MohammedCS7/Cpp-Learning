#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;

    cout << "Enter a Number : " << endl;
    cin >> number;

    return number;
}
long long GetFactorial(int number)
{
    long long factorial = 1;
    for (int i = 2; i <= number; i++)
    {
        factorial *= i;
    }
    return factorial;
}
void PrintFactorial(long long factorial)
{
    cout << "The Factorial is : " << factorial << endl;
}
int main() {
    PrintFactorial(GetFactorial(ReadNumber()));
    return 0;
}