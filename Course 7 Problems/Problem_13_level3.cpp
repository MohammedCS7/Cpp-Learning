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
            printf("  %d  ",arr[i][j]);
        }
        cout << "\n";
    }
}

bool IsMatrixIdentity(int arr1[3][3],short rows, short cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ((i == j && arr1[i][j] != 1) || (i != j && arr1[i][j] != 0))
                return false;
        }

    }

    return true;
}


string IsIdentityResult(bool isIdentity)
{
    return (isIdentity) ? "YES: Matrix is identity." : "NO: Matrix is NOT identity.";
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);


    cout << IsIdentityResult(IsMatrixIdentity(arr1, 3, 3)) << endl;

    return 0;
}