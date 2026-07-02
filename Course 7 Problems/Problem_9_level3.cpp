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
            arr[i][j] = Random::RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("  %0*d  ", 2, arr[i][j]);
        }
        cout << "\n";
    }
}

void PrintArray(int arr[3], short length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" %0*d ", 2, arr[i]);
    }
    cout << endl;
}

void GetMidRow(int arr[3][3], int mid[3], short rows, short cols)
{
    short middle = rows/2;
    
    for (int j = 0; j < cols; j++)
    {
        mid[j] = arr[middle][j];
    }

}

void GetMidCol(int arr[3][3], int mid[3], short rows, short cols)
{
    short middle = cols/2;


    for (int i = 0; i < rows; i++)
    {
        mid[i] = arr[i][middle];
    }
    
}

int main() {
    srand((unsigned)time(NULL));

    int arr1[3][3],midRow[3],midCol[3];

    FillMatrixRand(arr1, 3, 3);
    

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    GetMidRow(arr1, midRow, 3, 3);

    cout << "\nMiddle Row of Matrix 1 is : " << endl;
    PrintArray(midRow, 3);

    GetMidCol(arr1, midCol, 3, 3);

    cout << "\nMiddle Col of Matrix 1 is : " << endl;
    PrintArray(midCol, 3);

    return 0;
}