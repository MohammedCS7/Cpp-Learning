#include <iostream>
#include "Random.h"

using namespace std;

void FillMatrixRand(int arr[3][3], short rows, short cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = Random::RandomNumber(0, 1);
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            printf("  %d  ", arr[i][j]);
        }
        cout << "\n";
    }
}

int GetNumCountInMatrix(int arr[3][3], int num, short rows, short cols)
{
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                counter++;
        }
    }
    return counter;
}

bool IsMatrixSparse(int arr1[3][3], short rows, short cols)
{
    int matrixSize = rows * cols;
    return (GetNumCountInMatrix(arr1, 0, rows, cols) >= (matrixSize / 2) + matrixSize % 2);
}


string IsSparseResult(bool isSparce)
{
    return (isSparce) ? "YES: Matrix is sparse." : "NO: Matrix is NOT sparse.";
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    cout << IsSparseResult(IsMatrixSparse(arr1, 3, 3)) << endl;

    return 0;
}