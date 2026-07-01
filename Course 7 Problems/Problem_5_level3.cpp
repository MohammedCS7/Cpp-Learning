#include <iostream>
#include <iomanip>
#include "Random.h"

using namespace std;

void FillThreeByThreeArrayWithRand(int arr[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            arr[i][j] = Random::RandomNumber(1, 100);
        }
    }
}
void PrintRandArray(int arr[3][3])
{
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}

int SumOfMatrixCol(int arr[3][3], short colNum)
{
    int sum = 0;
    for (short i = 0;i < 3; i++)
    {
        sum += arr[i][colNum];
    }
    return sum;
}

void CalcColsSum(int arr[3][3], int sum[3])
{
    for (int j = 0;j < 3; j++)
    {
        sum[j] = SumOfMatrixCol(arr, j);
    }
}

void PrintColsSum(int sum[3])
{
    for (short i = 0; i < 3; i++)
    {
        cout << "Col " << i + 1 << " Sum = " << sum[i] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3], sum[3];
    FillThreeByThreeArrayWithRand(arr);
    cout << "The Following is a 3x3 random matrix : " << endl;
    PrintRandArray(arr);
    cout << "The Following are the sum of each col in the matrix : " << endl;
    CalcColsSum(arr, sum);
    PrintColsSum(sum);
    return 0;
}