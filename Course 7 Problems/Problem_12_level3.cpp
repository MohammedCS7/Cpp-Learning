#include <iostream>
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

bool AreMatricesTypical(int arr1[3][3], int arr2[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr1[i][j] != arr2[i][j])
                return false;
        }

    }

    return true;
}


string AreTypicalResult(bool areTypical)
{
    return (areTypical) ? "Yes, matrices are typical." : "No, matrices are NOT typical";
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3], arr2[3][3];

    FillMatrixRand(arr1, 3, 3);
    FillMatrixRand(arr2, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    cout << "Matrix 2 : " << endl;
    PrintMatrix(arr2, 3, 3);

    cout << AreTypicalResult(AreMatricesTypical(arr1, arr2, 3, 3)) << endl;

    return 0;
}