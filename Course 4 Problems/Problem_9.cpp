#include <iostream>
#include <string>
using namespace std;

void ReadThreeNumbers(int& num1 , int& num2 , int& num3)
{


    cout << "Enter First Number : " << endl;
    cin >> num1;

    cout << "Enter Second Number : " << endl;
    cin >> num2;

    cout << "Enter Third Number : " << endl;
    cin >> num3;
    

}
int CalculateSumOfThree(int num1,int num2,int num3)
{
    return num1 + num2 + num3;
}
void PrintResult(int sum)
{
    cout << "\nThe Sum is : " << sum << endl;
}
int main() {
    int num1, num2, num3;
    ReadThreeNumbers(num1, num2, num3);
    PrintResult(CalculateSumOfThree(num1, num2, num3));
    return 0;
}