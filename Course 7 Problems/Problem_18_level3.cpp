#include <iostream>
#include <iomanip>
#include "Random.h"

using namespace std;

void FillMatrixRand(int arr[3][3], short rows, short cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = Random::RandomNumber(0, 100);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "    ";
        }
        cout << "\n";
    }
}

bool IsNumberInMatrix(int arr[3][3], int num, short rows, short cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                return true;
        }
    }
    return false;
}

void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (IsNumberInMatrix(arr2, arr1[i][j], rows, cols))
                cout << setw(5) << arr1[i][j] << "    ";
        }
    }
}


int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3],arr2[3][3];

    FillMatrixRand(arr1, 3, 3);
    FillMatrixRand(arr2, 3, 3);

    cout << "\nMatrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    cout << "\nMatrix 2 : " << endl;
    PrintMatrix(arr2, 3, 3);

    cout << "\nIntersected Numbers are : " << endl;
    PrintIntersectedNumbers(arr1, arr2, 3, 3);

    return 0;
}