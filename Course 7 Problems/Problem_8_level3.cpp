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
            arr[i][j] = Random::RandomNumber(1,10);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("  %0*d  ",2,arr[i][j]);
        }
        cout << "\n";
    }
}

int MultiMatrix(int arr1[3][3], int arr2[3][3], short row, short col)
{
    return arr1[row][col] * arr2[row][col];
}

void MultiTheMatrix(int arr1[3][3], int arr2[3][3],int multi[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0;j < cols; j++)
        {
            multi[i][j] = MultiMatrix(arr1, arr2, i, j);
        }
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr1[3][3],arr2[3][3],multi[3][3];

    FillMatrixRand(arr1, 3, 3);
    FillMatrixRand(arr2, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    cout << "Matrix 2 : " << endl;
    PrintMatrix(arr2, 3, 3);

    MultiTheMatrix(arr1, arr2, multi, 3, 3);

    cout << "Results : " << endl;
    PrintMatrix(multi, 3, 3);

    return 0;
}