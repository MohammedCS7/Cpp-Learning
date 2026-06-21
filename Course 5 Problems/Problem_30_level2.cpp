#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool isPrime(int number)
{
    if (number == 2)
        return true;
    if (number <= 1 || number % 2 == 0)
        return false;
    int halfNumber = number / 2;
    for (int i = 3; i <= halfNumber; i += 2)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

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

void CopyArrayOnlyPrime(int originArr[100], int copyArr[100], int length, int& copyLength)
{
    int copyCounter = 0;
    for (int i = 0; i < length; i++)
    {
        if (isPrime(originArr[i]))
        {
            copyArr[copyCounter++] = originArr[i];
        }
    }
    copyLength = copyCounter;
}

void FillArrayRand(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void SumArrays(int arr1[100], int arr2[100],int sumArr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        sumArr[i] = arr1[i] + arr2[i];
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

    int arrRand1[100];
    int arrRand2[100];

    int arrLength = ReadPositiveNumber("Enter Array Size : ");

    FillArrayRand(arrRand1, arrLength);
    FillArrayRand(arrRand2, arrLength);

    cout << "\nArray 1 Elements : \n";

    PrintArray(arrRand1, arrLength);

    cout << "\nArray 2 Elements : \n";

    PrintArray(arrRand2, arrLength);

    int arrSum[100];
    
    SumArrays(arrRand1, arrRand2, arrSum, arrLength);
    

    cout << "\nSun of array 1 and array 2 elements : " << endl;

    PrintArray(arrSum, arrLength);

    return 0;
}