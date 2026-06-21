#include <iostream>
#include <string>

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

void FillArray(int arr[100], int length)
{
    cout << "\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
  }
    cout << endl;
}

int GetRepeatInArray(int arr[100], int length, int digit)
{
    int repCount = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == digit)
            repCount++;
    }
    return repCount;
}

void PrintArray(int arr[100], int length)
{
    cout << "\nOriginal array : ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintRepeatedNumber(int digit, int repeatCount)
{
    cout << digit << " is repeated " << repeatCount << " time(s)" << endl;
}

int main() {

    short arrLength = ReadPositiveNumber("Enter array length : ");

    int arr[100];
    
    FillArray(arr, arrLength);

    short digit = ReadPositiveNumber("Enter the number you want to check : ");

    PrintArray(arr, arrLength);

    PrintRepeatedNumber(digit, GetRepeatInArray(arr, arrLength, digit));

    return 0;
}