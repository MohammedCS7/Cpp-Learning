#include <iostream>
using namespace std;

enum NumberType {Odd = 1 , Even = 2};

int ReadNumber()
{
    int num;
    cout << "Please enter a number : " << endl;
    cin >> num;
    return num;
}

NumberType CheckNumberType(int num)
{
    if (num % 2 == 0)
    {
        return NumberType::Even;
    }
    else
    {
        return NumberType::Odd;
    }
}

void PrintNumberType(NumberType numType)
{
    if (numType == NumberType::Odd)
        cout << "\nNumber is Odd. \n ";
    else
        cout << "\nNumber is Even. \n";
     
}


int main() {
    PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}