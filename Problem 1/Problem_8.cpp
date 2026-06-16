#include <iostream>
using namespace std;
enum PassFail {Pass=1 , Fail=0};
float ReadMark()
{
    float Mark;

    cout << "Enter your Grade : " << endl;
    cin >> Mark;

    return Mark;
}
PassFail CheckMark(float Mark)
{
    if (Mark >= 50)
        return PassFail::Pass;
    else
        return PassFail::Fail;
}
void PrintGradeResult(float Mark)
{
    if (CheckMark(Mark) == PassFail::Pass)
        cout << "\nPASS!" << endl;
    else
        cout << "\nFAIL!" << endl;
}
int main() {
    PrintGradeResult(ReadMark());
    return 0;
}