#include <iostream>
#include <string>
using namespace std;

void ReadNumbers(int nums[100] , int& length)
{

    cout << "Enter the Numbers you want to sum : " << endl;
    cin >> length;

    for (int i = 0; i < length; i++)
    {
        cout << "Enter Number " << i + 1 << " : \n";
        cin >> nums[i];
    }
}
int CalculateSumOfNumbers(int nums[100],int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += nums[i];
    }
    return sum;
}
void PrintResult(int sum)
{
    cout << "\nThe Sum is : " << sum << endl;
}
int main() {
    int nums[100];
    int length;
    ReadNumbers(nums[100],length);
    PrintResult(CalculateSumOfNumbers(nums[100], length));
    return 0;
}