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

void CopyArray(int originArr[100], int copyArr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        copyArr[i] = originArr[i];
    }
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

    int arrRand[100];

    int arrLength = ReadPositiveNumber("Enter Array Size : ");

    FillArrayRand(arrRand, arrLength);

    cout << "\nArray 1 Elements : \n";

    PrintArray(arrRand, arrLength);

    int arrCopy[100];

    CopyArray(arrRand, arrCopy, arrLength);

    cout << "\nArray 2 Elements : \n";

    PrintArray(arrCopy, arrLength);

    return 0;
}