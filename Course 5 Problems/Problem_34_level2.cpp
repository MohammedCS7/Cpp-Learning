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

void PrintArray(int arr[100], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintResult(int index, int target)
{
    cout << "Number you are looking for is : " << target << endl;
    if (index >= 0)
    {
        cout << "The number found at position : " << index << endl;
        cout << "The number found in order : " << index + 1 << endl;
    }
    else
    {
        cout << "The number is not found :(" << endl;
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

  
    PrintResult(SearchForNumber(arrRand1, arrLength, target), target);


    return 0;
}