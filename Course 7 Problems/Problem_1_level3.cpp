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

int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillThreeByThreeArrayWithRand(arr);
    cout << "The following is a 3x3 random matrix : " << endl;
    PrintRandArray(arr);

    return 0;
}