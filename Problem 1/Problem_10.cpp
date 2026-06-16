#include <iostream>
using namespace std;
enum PassFail {Pass=1 , Fail=0};
void ReadMarks(float& mark1, float& mark2, float& mark3)
{


    cout << "Enter your Mark 1 : " << endl;
    cin >> mark1;

    cout << "Enter your Mark 2 : " << endl;
    cin >> mark2;

    cout << "Enter your Mark 3 : " << endl;
    cin >> mark3;

     
}
float CalculateMarksAverage(float mark1,float mark2, float mark3)
{
    return (mark1 + mark2 + mark3) / 3;
}
PassFail CheckMark(float markAvg)
{
    if (markAvg >= 50)
        return PassFail::Pass;
    else
        return PassFail::Fail;
}
void PrintGradeResult(float mark)
{
    cout << "\nThe Average is : " << mark << endl;
    if (CheckMark(mark) == PassFail::Pass)
        cout << "\nPASS!" << endl;
    else
        cout << "\nFAIL!" << endl;
}
int main() {
    float mark1, mark2, mark3;
    ReadMarks(mark1, mark2, mark3);
    PrintGradeResult(CalculateMarksAverage(mark1, mark2, mark3));
    return 0;
}