#include <iostream>
#include <cstdlib>


using namespace std;


int ReadPostiiveNumber(string message)
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

void CopyArrayReversed(int arr[100], int newArr[100], int length)
{
    

    for (int i = 0; i < length; i++)
    {
        newArr[i] = arr[length-1-i];
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

    int arr[100];
    int revArr[100];

    int length = ReadPostiiveNumber("Enter Array Length : ");

    FillArrayRand(arr, length);

    cout << "Array 1 elements : " << endl;
    PrintArray(arr, length);

    CopyArrayReversed(arr, revArr, length);

    cout << "Array 2 elements after copying array 1 in reversed order : \n";
    PrintArray(revArr, length);

    return 0;
}