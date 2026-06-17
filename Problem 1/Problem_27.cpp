#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}
void LoopFromNumberToOneUsingFor(int number)
{
    cout << "****************************************\n";
    for (int i = number; i >= 1; i--)
    {
        cout << i << "\n";
    }
    cout << "****************************************\n" << endl;
}
void LoopFromNumberToOneUsingWhile(int number)
{
    cout << "****************************************\n";
    int i = number;
    while (i >= 1)
    {
        cout << i << "\n";
        i--;
    }
    cout << "****************************************\n" << endl;
}
void LoopFromNumberToOneUsingDoWhile(int number)
{
    cout << "****************************************\n";
    int i = number;
    do
    {
        cout << i << "\n";
        i--;
    } while (i >= 1);
    cout << "****************************************\n" << endl;
}
int main() {
    LoopFromNumberToOneUsingFor(ReadNumber());
    return 0;
}