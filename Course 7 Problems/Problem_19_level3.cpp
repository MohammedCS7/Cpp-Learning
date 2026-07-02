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

int GetMaxInMatrix(int arr[3][3], int rows, int cols)
{
    int max = arr[0][0];
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0; j < cols; j++)
        {
            max = (arr[i][j] > max) ? arr[i][j] : max;
        }
    }
    return max;
}

int GetMinInMatrix(int arr[3][3], int rows, int cols)
{
    int min = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            min = (arr[i][j] < min) ? arr[i][j] : min;
        }
    }
    return min;
}

void PrintMatrixMinAndMax(int min, int max)
{
    cout << "Minimum Number is : " << min << endl;
    cout << "Max Number is : " << max << endl;
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    PrintMatrixMinAndMax(GetMinInMatrix(arr1, 3, 3), GetMaxInMatrix(arr1, 3, 3));



    return 0;
}