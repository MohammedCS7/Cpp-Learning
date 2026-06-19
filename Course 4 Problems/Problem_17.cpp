#include <iostream>
#include <cmath>
using namespace std;
void ReadBaseHeight(float& base , float& height)
{
    cout << "Enter the Base : " << endl;
    cin >> base;

    cout << "Enter the Height : " << endl;
    cin >> height;
}
float CalcTriangleArea(float base, float height)
{
    float area = base/2*height;
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float base, height;
    ReadBaseHeight(base, height);
    PrintArea(CalcTriangleArea(base, height));
    return 0;
}