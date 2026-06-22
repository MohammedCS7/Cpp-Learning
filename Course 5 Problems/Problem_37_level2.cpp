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

void AddElement(int number,int arr[100], int& length)
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

void CopyArray(int arr[100], int length,int& copyLength, int arr2[100])
{
    for (int i = 0;i < length; i++)
    {
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

    CopyArray(arr, length, copyLength, arrCopy);

    cout << "\nArray 2 elements after copy : \n";
    PrintArray(arrCopy, length);

    return 0;
}