#include <iostream>
using namespace std;

struct Info
{
    string FirstName;
    string LastName;
};
Info ReadFullName()
{
    Info Name;

    cout << "Enter First Name : " << endl;
    cin >> Name.FirstName;

    cout << "Enter Last Name : " << endl;
    cin >> Name.LastName;

    return Name;
}
string getFullName(Info Name , bool Reversed)
{
    if (Reversed)
        return Name.LastName + " " + Name.FirstName;
    else
        return Name.FirstName + " " + Name.LastName;
}
void PrintFullName(string FullName)
{
    cout << "\nMy Name is : " << FullName << endl;
}
int main() {


    PrintFullName(getFullName(ReadFullName(),true));


    return 0;
}