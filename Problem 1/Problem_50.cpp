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
    int counter = 3;
    string pinCodeTry = "";
    do
    {
        pinCodeTry = ReadString("Enter the PIN Code : ");
        counter--;
        if (pinCodeTry == "1234")
            return true;
        else
        {
            system("color 4F");
            cout << "Error" << endl;

        }
    } while (pinCodeTry != "1234" && counter >= 1);
    return false;
}

int main() {

    if (login())
    {
        system("color 2F");
        cout << "Your balance is 7500" << endl;
    }
    else
    {
        system("color 7F");
        cout << "You are Blocked" << endl;
    }

    return 0;
}