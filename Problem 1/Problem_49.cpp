#include <iostream>
#include <string>
using namespace std;

string ReadString(string message)
{
    string str;

    cout << message << endl;
    cin >> str;

    return str;
}

bool login()
{
    string pinCodeTry = "";
    do
    {
        pinCodeTry = ReadString("Enter the PIN Code : ");
        if (pinCodeTry == "1234")
            return true;
        else
        {
            system("color 4F");
            cout << "Error" << endl;
        }
    } while (pinCodeTry != "1234");
}

int main() {

    if (login())
    {
        system("color 2F");
        cout << "Your balance is 7500" << endl;
    }

    return 0;
}