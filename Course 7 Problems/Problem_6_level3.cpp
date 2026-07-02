#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixInOrder(int arr[3][3],short rows,short cols)
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

void PrintMatrix(int arr[3][3],short rows,short cols)
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

    int arr[3][3];

    FillMatrixInOrder(arr,3,3);

    cout << "The following is a 3x3 orderd matrix : " << endl;
    PrintMatrix(arr,3,3);


    return 0;
}