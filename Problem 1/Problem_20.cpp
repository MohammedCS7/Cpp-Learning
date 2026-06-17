#include <iostream>
#include <cmath>
using namespace std;
float ReadSquareArea()
{
    float squareArea;
    cout << "Enter the Square Area : " << endl;
    cin >> squareArea;

    return squareArea;
}
float CalcCircleArea(float squareArea)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = (PI * squareArea * squareArea) / 4;
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadSquareArea()));
    return 0;
}