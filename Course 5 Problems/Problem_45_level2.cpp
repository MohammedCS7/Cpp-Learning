#include <iostream>
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

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(-100, 100);
    }
}

int CountNegativeInArray(int arr[100], int length)
{
    int negativeCounter = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0)
            negativeCounter++;
    }
    return negativeCounter;
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

    int length = ReadPositiveNumber("Enter array length : ");


    int arr[100];

    FillArrayRand(arr, length);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr, length);

    cout << "\nNegative numbers count is : " << CountNegativeInArray(arr, length) << endl;;


    return 0;
}