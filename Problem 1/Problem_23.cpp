#include <iostream>
#include <cmath>
using namespace std;
void ReadTriangleData(float& side1 , float& side2, float& side3)
{
    cout << "Enter the Base : " << endl;
    cin >> side1;

    cout << "Enter the Side : " << endl;
    cin >> side2;

    cout << "Enter the Hypotenuse : " << endl;
    cin >> side3;

}
float CalcCircleArea(float side1,float side2,float side3)
{
    const double PI = 3.1415926535897932384626433832795;
    float p = (side2 + side1 + side3) / 2;
    float r = ((side2 * side1 * side3) / (4 * sqrt(p * (p - side2) * (p - side1) * (p - side3))));
    float area = PI * (r * r);
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float side1, side2, side3;
    ReadTriangleData(side1, side2, side3);
    PrintArea(CalcCircleArea(side1, side2, side3));
    return 0;
}