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

void AddToArray(int arr[100], int& length, int number)
{
    length++;
    arr[length - 1] = number;
}

void PrintArray(int arr[100], int length)
{

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void FillArraySemiDynamic(int arr[100], int& length)
{
    bool addOrNo;
    int number;
    
    do
    {
        number = ReadPositiveNumber("Please enter a number : ");

        AddToArray(arr, length, number);
        

        cout << endl << "Do you want to add more numbers ? [0]No[1]Yes : ";
        cin >> addOrNo;

    } while (addOrNo);
    
}


int main()
{

    int arr[100];
    int length = 0;

    FillArraySemiDynamic(arr, length);

    cout << "Array Length : " << length << endl;
    cout << "Array elements : ";
    PrintArray(arr, length);

    
    return 0;
}