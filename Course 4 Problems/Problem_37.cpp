#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string message)
{
    int number;

    cout << message << endl;
    cin >> number;

    return number;
}

int SumUntilMinus99()
{
    int sum = 0;
    int number = 0;
    int counter = 1;
    do
    {
        number = ReadNumber("Enter Number : "+to_string(counter));
        
        if (number != -99)
        {
            sum += number;
            counter++;
        }
        } while (number != -99);
    return sum;
}
void PrintSum(int sum)
{
    cout << "\nThe Sum is : " << sum << endl;
}
int main() {
    int sum = SumUntilMinus99();
    PrintSum(sum);
    return 0;
}