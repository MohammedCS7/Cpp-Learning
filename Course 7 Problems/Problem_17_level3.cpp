#include <iostream>
#include <iomanip>
#include "Input.h"
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

bool IsNumberInMatrix(int arr[3][3], int num, short rows, short cols)
{
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == num)
                return true;
        }
    }
    return false;
}

string IsNumberThere(bool isThere)
{
    return (isThere) ? "Yes, its there." : "No, its NOT there";
}

void PrintIsNumberInMatrix(string thereOrNot)
{
    cout << thereOrNot << endl;
}

int main() {

    srand((unsigned)time(NULL));

    int arr1[3][3];

    FillMatrixRand(arr1, 3, 3);

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);
    
    int trgtNumber = Input::ReadInteger("Please enter the number to look for in matrix : ");
    
    PrintIsNumberInMatrix(IsNumberThere(IsNumberInMatrix(arr1, trgtNumber, 3, 3)));

    return 0;
}