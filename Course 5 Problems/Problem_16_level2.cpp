#include <iostream>
using namespace std;

void PrintAAAToZZZ()
{
    for (int i = 65; i < 91; i++)
    {
        
        for (int j = 65; j < 91; j++)
        {
            for (int k = 65; k < 91; k++)
            {
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
        cout << "\n";
    }
}

int main() {
    PrintAAAToZZZ();
    return 0;
}