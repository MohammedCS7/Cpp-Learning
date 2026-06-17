#include <iostream>
#include <cmath>
using namespace std;
float ReadRadius()
{
    float radius;
    cout << "Enter the Radius : " << endl;
    cin >> radius;

    return radius;
}
float CalcCircleArea(float radius)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = PI * radius * radius;
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadRadius()));
    return 0;
}