#include <iostream>
using namespace std;

struct PiggyBank
{
    int penny=0;
    int nickel=0;
    int dime=0;
    int quarter=0;
    int dollar=0;
};

PiggyBank ReadPiggyBankData()
{
    PiggyBank bank;

    cout << "Enter the Pennies : " << endl;
    cin >> bank.penny;

    cout << "Enter the Nickels : " << endl;
    cin >> bank.nickel;

    cout << "Enter the Dimes : " << endl;
    cin >> bank.dime;

    cout << "Enter the Quarter : " << endl;
    cin >> bank.quarter;

    cout << "Enter the Dollars : " << endl;
    cin >> bank.dollar;

    return bank;
}

int CalcPennies(PiggyBank bank)
{
    int pennies;
    pennies = 
        bank.penny 
        + 
        bank.nickel * 5 
        + 
        bank.dime * 10 
        + 
        bank.quarter * 25 
        + 
        bank.dollar * 100;
    return pennies;
}



int main() {

    int totalPennies = CalcPennies(ReadPiggyBankData());

    cout << endl << totalPennies << " Pennies " << endl;
    cout << endl << (float)totalPennies / 100 << " Dollars " << endl;

    return 0;
}