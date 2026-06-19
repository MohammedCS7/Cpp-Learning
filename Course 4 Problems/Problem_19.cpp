#include <iostream>
#include <cmath>
using namespace std;
float ReadDiameter()
{
    float diameter;
    cout << "Enter the Diameter : " << endl;
    cin >> diameter;

    return diameter;
}
float CalcCircleArea(float diameter)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = (PI * diameter * diameter)/4;
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadDiameter()));
    return 0;
}