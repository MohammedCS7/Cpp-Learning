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



void CopyArrayReversed(int arrSrc[100], int arrNew[100], int length, int& copyLength)
{
    for (int i = length-1;i >= 0; i--)
    {
            AddElement(arrSrc[i], arrNew, copyLength);
    }
}

bool isArrayPalindrome(int arr[100], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] != arr[length-1-i])
            return false;
    }
    return true;
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


    int length = 6;
    int copyLength = 0;

    int arrSrc[100] = { 10,20,30,30,20,10 }, arrCopy[100];



    cout << "\nArray 1 elements : \n";
    PrintArray(arrSrc, length);

    CopyArrayReversed(arrSrc, arrCopy, length, copyLength);

    if (isArrayPalindrome(arrSrc,length))
        cout << "Yes array is Palindrome" << endl;

    return 0;
}