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

int SumOfMatrixRow(int arr[3][3],short rowNum)
{
    int sum = 0;
        for (short j = 0;j < 3; j++)
        {
            sum += arr[rowNum][j];
        }
    return sum;
}

void CalcRowsSum(int arr[3][3], int sum[3])
{
    for (int i = 0;i < 3; i++)
    {
        sum[i] = SumOfMatrixRow(arr, i);
    }
}

void PrintRowsSum(int sum[3])
{
    for (short i = 0; i < 3; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << sum[i] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3],sum[3];
    FillThreeByThreeArrayWithRand(arr);
    cout << "The following is a 3x3 random matrix : " << endl;
    PrintRandArray(arr);
    cout << "The following are the sum of each row in the matrix : " << endl;
    CalcRowsSum(arr,sum);
    PrintRowsSum(sum);
    return 0;
}