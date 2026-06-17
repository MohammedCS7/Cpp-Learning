#include <iostream>
#include <cmath>
using namespace std;
void ReadTriBaseSides(float& base , float& sides)
{
    cout << "Enter the Base : " << endl;
    cin >> base;

    cout << "Enter the Sides : " << endl;
    cin >> sides;
}
float CalcCircleArea(float base,float sides)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = PI*(base*base/4)*((2*sides-base)/(2*sides+base));
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float base, sides;
    ReadTriBaseSides(base, sides);
    PrintArea(CalcCircleArea(base,sides));
    return 0;
}