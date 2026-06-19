#include <iostream>
using namespace std;
void ReadWidthLength(float& width , float& length)
{
    cout << "Enter the Width : " << endl;
    cin >> width;

    cout << "Enter the Length : " << endl;
    cin >> length;
}
float GetRectangleArea(float width , float length)
{
    return width * length;
}
void PrintArea(float area)
{
    cout << "\nThe Area is : " << area << endl;
}
int main() {
    float width, length;
    ReadWidthLength(width, length);
    PrintArea(GetRectangleArea(width, length));
    return 0;
}