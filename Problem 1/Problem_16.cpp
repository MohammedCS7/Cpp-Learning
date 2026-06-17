#include <iostream>
#include <cmath>
using namespace std;
void ReadDiagonalSide(float& diagonal , float& side)
{
    cout << "Enter the Diagonal : " << endl;
    cin >> diagonal;

    cout << "Enter the Side : " << endl;
    cin >> side;
}
float CalcRectangleArea(float diagonal, float side)
{
    float area = side * sqrt(diagonal * diagonal - side * side);
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float diagonal, side;
    ReadDiagonalSide(diagonal, side);
    PrintArea(CalcRectangleArea(diagonal, side));
    return 0;
}