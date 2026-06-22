#include <iostream>
#include <cstdlib>

using namespace std;


enum enEvenOdd { Even = 1, Odd = 2 };

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

enEvenOdd CheckNumberOddEven(int number)
{
    if (number % 2 == 0)
        return enEvenOdd::Even;
    else
        return enEvenOdd::Odd;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

int CountOddInArray(int arr[100], int length)
{
    int oddCounter = 0;
    for (int i = 0; i < length; i++)
    {
        if (CheckNumberOddEven(arr[i]) == enEvenOdd::Odd)
            oddCounter++;
    }
    return oddCounter;
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

    cout << "\nOdd numbers count is : " << CountOddInArray(arr, length) << endl;;
    

    return 0;
}