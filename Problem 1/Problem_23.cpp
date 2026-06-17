#include <iostream>
#include <cmath>
using namespace std;
void ReadTriangleData(float& base , float& side, float& chord)
{
    cout << "Enter the Base : " << endl;
    cin >> base;

    cout << "Enter the Side : " << endl;
    cin >> side;

    cout << "Enter the Chord : " << endl;
    cin >> chord;

}
float CalcCircleArea(float base,float side,float chord)
{
    const double PI = 3.1415926535897932384626433832795;
    float p = (side + base + chord) / 2;
    float r = ((side * base * chord) / (4 * sqrt(p * (p - side) * (p - base) * (p - chord))));
    float area = PI * (r * r);
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float base, side,chord;
    ReadTriangleData(base, side,chord);
    PrintArea(CalcCircleArea(base,side,chord));
    return 0;
}