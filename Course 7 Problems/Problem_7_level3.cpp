#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixInOrder(int arr[3][3], short rows, short cols)
{
    short counter = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = counter++;
        }
    }
}

void FillMatrixTrnasposed(int arr[3][3],int tranArr[3][3], short rows, short cols)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            tranArr[i][j] = arr[j][i];
        }
    }
}

void PrintMatrix(int arr[3][3], short rows, short cols)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << arr[i][j] << "  ";
        }
        cout << "\n";
    }
}
int main() {

    int arr[3][3],tranArr[3][3];

    FillMatrixInOrder(arr, 3, 3);

    cout << "The following is a 3x3 orderd matrix : " << endl;
    PrintMatrix(arr, 3, 3);

    FillMatrixTrnasposed(arr,tranArr, 3, 3);

    cout << "The following is a 3x3 transposed matrix : " << endl;
    PrintMatrix(tranArr, 3, 3);

    return 0;
}