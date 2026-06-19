#include <iostream>



using namespace std;

void PrintTableHeader()
{
    cout << "\n\n\t\t\tMultiplication Table From 1 to 10" << "\n\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n-------------------------------------------------------------------------------------------\n";
}
string ColumnSeperator(int i)
{
    if (i < 10)
        return "  |";
    else
        return " |";
}
void PrintMultiplicationTable()
{
    
    PrintTableHeader();
    for (int i = 1; i <= 10; i++)
    {
        
        cout << " " << i << ColumnSeperator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout  << j * i << "\t";
        }
        cout << endl;
    }
}

int main()
{
    PrintMultiplicationTable();



    return 0;
}
