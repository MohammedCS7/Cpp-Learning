#include <iostream>
using namespace std;
int ReadNumber()
{
    int number;

    cout << "Enter Number : " << endl;
    cin >> number;

    return number;
}
void LoopFromOneToNumberUsingFor(int number)
{
    cout << "****************************************\n";
    for (int i = 1; i <= number; i++)
    {
        cout << i << "\n";
    }
    cout << "****************************************\n" << endl;
}
void LoopFromOneToNumberUsingWhile(int number)
{
    cout << "****************************************\n";
    int i = 1;
    while (i <= number)
    {
        cout << i << "\n";
        i++;
    }
    cout << "****************************************\n" << endl;
}
void LoopFromOneToNumberUsingDoWhile(int number)
{
    cout << "****************************************\n";
    int i = 1;
    do
    {
        cout << i << "\n";
        i++;
    }while (i <= number);
    cout << "****************************************\n" << endl;
}
int main() {
    LoopFromOneToNumberUsingDoWhile(ReadNumber());
    return 0;
}