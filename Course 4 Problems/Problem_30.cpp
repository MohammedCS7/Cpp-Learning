#include <iostream>
using namespace std;
int ReadPositveNumber(string message)
{
    int number=0;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);
    return number;
}
unsigned long long GetFactorial(int number)
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
    PrintFactorial(GetFactorial(ReadPositveNumber("Enter Number N : ")));
    return 0;
}