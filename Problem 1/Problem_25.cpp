#include <iostream>
using namespace std;

bool IsNumberValidInRange(int number, int from, int to)
{
    return (number >= from && number <= to);
}

int ReadAge()
{
    int age;
    cout << "Please enter age between 18 and 45 : " << endl;
    cin >> age;

    return age;
}

int ReadAgeUntilBetween(int from , int to)
{
    int age =0;
    do
    {
      age = ReadAge();
    } while (!IsNumberValidInRange(age, from, to));
   
    return age;
}

void PrintResutl(int age)
{
    cout << "\nYour age is : " << age << endl;
    
}
int main() {
    PrintResutl(ReadAgeUntilBetween(18,45));
    return 0;
}