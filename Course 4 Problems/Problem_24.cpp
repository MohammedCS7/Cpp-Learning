#include <iostream>
using namespace std;
short ReadAge()
{
    short age;
    
    cout << "Enter your Age : " << endl;
    cin >> age;

    return age;
}
bool IsNumberValid(int number, int from, int to)
{
    return (number >= from && number <= to);
}
void PrintResutl(short age)
{
    if (IsNumberValid(age, 18, 45))
        cout << age << " is Valid!\n";
    else
        cout << age << " is Invalid!" << endl;
}
int main() {
    PrintResutl(ReadAge());
    return 0;
}