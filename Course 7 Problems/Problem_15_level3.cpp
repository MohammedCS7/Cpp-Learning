#include <iostream>
#include <iomanip>
#include "Random.h"
#include "Input.h"

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

void PrintNumberCountInMatrix(int num, int count)
{
    cout << "Number " << num << " Count in matrix is : " << count << endl;
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);


    int targetNum = Input::ReadInteger("\nEnter number you want to count : ");

    PrintNumberCountInMatrix(targetNum, GetNumCountInMatrix(arr1, targetNum, 3, 3));

    return 0;
}