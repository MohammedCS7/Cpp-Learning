#include <iostream>
#include <iomanip>


using namespace std;


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

bool IsMatrixPalindrome(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols/2; j++)
        {
            if (arr[i][j] != arr[i][cols - j - 1])
                return false;
        }
    }
    return true;
}

string GetIsMatrixPalindrome(bool isPalindrome)
{
    return (isPalindrome) ? "Yes, Matrix is Palindrome." : "No, Matrix is NOT Palindrome.";
}

void PrintIsMatrixPalindrome(string getIsPalindrome)
{
    cout << getIsPalindrome << endl;
}

int main() {    

    int arr1[3][3] = { {1,2,1},{5,9,5},{7,3,7} };

    cout << "Matrix 1 : " << endl;
    PrintMatrix(arr1, 3, 3);

    PrintIsMatrixPalindrome(GetIsMatrixPalindrome(IsMatrixPalindrome(arr1, 3, 3)));



    return 0;
}