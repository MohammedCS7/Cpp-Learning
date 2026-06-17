#include <iostream>
#include <cmath>
using namespace std;
float ReadCircleCircumference()
{
    float circleCircumference;
    cout << "Enter the Circle Circumference : " << endl;
    cin >> circleCircumference;

    return circleCircumference;
}
float CalcCircleArea(float circleCircumference)
{
    const double PI = 3.1415926535897932384626433832795;
    float area =  circleCircumference * circleCircumference / (PI * 4);
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadCircleCircumference()));
    return 0;
}