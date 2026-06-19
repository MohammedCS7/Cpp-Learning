#include <iostream>
using namespace std;

float ReadNumberInRange(float from , float to)
{
    float number=0;
    do
    {
        cout << "Enter number between " << from << " and " << to << " : " << endl;
        cin >> number;
    } while (number < from || number > to);
    return number;
}

char GetGrade(float mark)
{
    if (mark >= 90)
        return 'A';
    else if (mark >= 80)
        return 'B';
    else if (mark >= 70)
        return 'C';
    else if (mark >= 60)
        return 'D';
    else if (mark >= 50)
        return 'E';
    else
        return 'F';
}

void PrintGrade(char grade)
{
    cout << "\nThe Grade is : " << grade << endl;
}
int main() {

    PrintGrade(GetGrade(ReadNumberInRange(0, 100)));

    return 0;
}