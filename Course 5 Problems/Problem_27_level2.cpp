#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int ReadPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

int GetSumOfArray(int arr[100], int length)
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }

    return sum;
}

float GetAvgOfArray(int sum, int length)
{
    return float(sum) / length;
}

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    srand((unsigned)time(NULL));

    int arr[100];

    int arrLength = ReadPositiveNumber("Enter Array Size : ");

    FillArrayRand(arr, arrLength);

    cout << "\nArray Elements : ";

    PrintArray(arr, arrLength);

    cout << "\nThe Average of all numbers is  : " << GetAvgOfArray(GetSumOfArray(arr,arrLength), arrLength);

    return 0;
}