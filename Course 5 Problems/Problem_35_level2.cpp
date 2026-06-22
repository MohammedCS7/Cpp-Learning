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

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}



int SearchForNumber(int arr[100], int length, int target)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

bool isFound(int arr[100], int length, int target)
{
    return (SearchForNumber(arr, length, target) != -1);
}

void PrintArray(int arr[100], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintResult(int arr[100],int length, int target)
{
    cout << "Number you are looking for is : " << target << endl;
    if (isFound(arr,length,target))
    {
        cout << "Yes, The number is  found :)" << endl;
    }
    else
    {
        cout << "No, The number is not found :(" << endl;
    }
}

int main() {

    srand((unsigned)time(NULL));

    int arrRand1[100];


    int arrLength = ReadPositiveNumber("Enter Array Size : ");

    FillArrayRand(arrRand1, arrLength);


    cout << "\nArray 1 Elements : \n";

    PrintArray(arrRand1, arrLength);

    int target = ReadPositiveNumber("Please enter a number to search for : ");


    PrintResult(arrRand1, arrLength, target);


    return 0;
}