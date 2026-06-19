#include <iostream>
#include <cmath>
using namespace std;
float ReadCircumference()
{
    float circumference;
    cout << "Enter the Circumference : " << endl;
    cin >> circumference;

    return circumference;
}
float CalcCircleArea(float circumference)
{
    const double PI = 3.1415926535897932384626433832795;
    float area = circumference * circumference / (PI * 4);
    return area;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    PrintArea(CalcCircleArea(ReadCircumference()));
    return 0;
}