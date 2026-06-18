#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
    int number = 0;
    do
    {
        cout << "Enter Positive Number : " << endl;
        cin >> number;
    } while (number <= 0);
    
    return number;
}

bool isPrime(int number)
{
    if (number == 2)
        return true;
    if (number % 2 == 0 || number == 1)
        return false;
    int half = number / 2;
    for (int i = 3; i <= half; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void PrintResutl(int number)
{
    if (isPrime(number))
        cout << number << " is Prime Number!" << endl;
    else
        cout << number << " is Not Prime Number!" << endl;
}
int main() {

    PrintResutl(ReadPositiveNumber());


    return 0;
}