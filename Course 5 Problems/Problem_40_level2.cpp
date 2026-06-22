#include <iostream>


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


void AddElement(int number, int arr[100], int& length)
{
    length++;
    arr[length - 1] = number;
}



void CopyArrayOnlyDistinct(int arrSrc[100], int arrNew[100], int length, int& copyLength)
{
    for (int i = 0;i < length; i++)
    {
        if (!isFound(arrNew,copyLength,arrSrc[i]))
            AddElement(arrSrc[i], arrNew, copyLength);
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


    int length = 9;
    int copyLength = 0;

    int arrSrc[100] = {10,10,10,50,50,70,70,70,90}, arrCopy[100];

    

    cout << "\nArray 1 elements : \n";
    PrintArray(arrSrc, length);

    CopyArrayOnlyDistinct(arrSrc, arrCopy, length, copyLength);

    cout << "\nArray 2 Distinct numbers : \n";
    PrintArray(arrCopy, copyLength);

    return 0;
}