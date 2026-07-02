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
            arr[i][j] = Random::RandomNumber(0, 10);
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

bool IsMatrixScalar(int arr1[3][3], short rows, short cols)
{
    int num = arr1[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == j && arr1[i][j] != num) || (i != j && arr1[i][j] != 0))
                return false;
        }

    }

    return true;
}


string IsScalarResult(bool isScalar)
{
    return (isScalar) ? "YES: Matrix is scalar." : "NO: Matrix is NOT scalar.";
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);


    cout << IsScalarResult(IsMatrixScalar(arr1, 3, 3)) << endl;

    return 0;
}