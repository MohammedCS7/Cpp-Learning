#include <iostream>
using namespace std;

float ReadNumber()
{
    float Number;
    
    cout << "Enter Number : " << endl;
    cin >> Number;

    return Number;
}
float GetNumberHalf(float Number)
{
    return Number / 2;
}
void PrintNumberHalf(float Number)
{
    cout << "The Half of " << Number << " is " << GetNumberHalf(Number) << endl;
}
int main() {
    PrintNumberHalf(ReadNumber());
    return 0;
}