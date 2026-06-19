#include <iostream>
#include <cmath>
using namespace std;
float ReadSquareSide()
{
    float squareSide;
    cout << "Enter the Square Side : " << endl;
    cin >> squareSide;

    return squareSide;
}
float CalcCircleArea(float squareSide)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = (PI * squareSide * squareSide) / 4;
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadSquareSide()));
    return 0;
}