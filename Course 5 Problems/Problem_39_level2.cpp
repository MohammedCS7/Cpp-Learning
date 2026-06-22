#include <iostream>
#include <cstdlib>

using namespace std;


enum enEvenOdd { Even = 1, Odd = 2 };


enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

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

enPrimeNotPrime CheckNumberPrimeNotPrime(int number)
{
    if (number == 2)
        return enPrimeNotPrime::Prime;
    if (number <= 1)
        return enPrimeNotPrime::NotPrime;
    if (CheckNumberOddEven(number) == enEvenOdd::Even)
        return enPrimeNotPrime::NotPrime;
    int halfNum = number / 2;
    for (int i = 3; i <= halfNum; i += 2)
    {
        if (number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}

int RandomNumber(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

void AddElement(int number, int arr[100], int& length)
{
    length++;
    arr[length - 1] = number;
}

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void CopyArrayOnlyOdd(int arr[100], int arr2[100], int length, int& copyLength)
{
    for (int i = 0;i < length; i++)
    {
        if (CheckNumberOddEven(arr[i]) == enEvenOdd::Odd)
            AddElement(arr[i], arr2, copyLength);
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

    int length = ReadPositiveNumber("Enter array length : ");
    int copyLength = 0;

    int arr[100], arrCopy[100];

    FillArrayRand(arr, length);

    cout << "\nArray 1 elements : \n";
    PrintArray(arr, length);

    CopyArrayOnlyOdd(arr, arrCopy, length, copyLength);

    cout << "\nArray 2 Odd numbers : \n";
    PrintArray(arrCopy, copyLength);

    return 0;
}