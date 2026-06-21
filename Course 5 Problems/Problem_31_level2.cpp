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

void FillArrayOrder(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = i+1;
    }
}

void CopyArray(int arr[100], int newArr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        newArr[i] = arr[i];
    }
}

void Swap(int& num1, int& num2)
{
    int temp;
    temp = num2;
    num2 = num1;
    num1 = temp;
}

void ShuffleArray(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        Swap(arr[i], arr[RandomNumber(0, length - 1)]);
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

    int arr1[100];
    int arrLength = ReadPositiveNumber("Enter Array Length : ");

    FillArrayOrder(arr1, arrLength);

    cout << "\nArray elements before shuffle : \n";

    PrintArray(arr1, arrLength);

    cout << "\nArray elements after shuffle : \n";

    ShuffleArray(arr1, arrLength);

    PrintArray(arr1, arrLength);

    return 0;
}