#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum RandomThing {SmallLetter=1,CapitalLetter=2,SpecialChar=3,Digit=4};

int ReadNumberInRange(int From, int To)
{
    int number;
    do
    {
        cout << "Enter Number between " << From << " and " << To << endl;
        cin >> number;
    } while (number < From || number > To);

    return number;
}

RandomThing ReadThing()
{
    
    cout << "(SmallLetter=1,CapitalLetter=2,SpecialChar=3,Digit=4) : " << endl;
    
    return (RandomThing)ReadNumberInRange(1, 4);
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandomChar(RandomThing thing)
{
    switch (thing)
    {
    
    case RandomThing::CapitalLetter:
        
        return (char)RandomNumber(65, 90);
        
        
    
    case RandomThing::SmallLetter:
        return (char)RandomNumber(97, 122);
    
    case RandomThing::Digit:
        return (char)RandomNumber(48, 57);

    case RandomThing::SpecialChar:
        return (char)RandomNumber(33, 47);
    
    }
}

void PrintRandom(char rand)
{
    cout << "\n--------------------------------\n\n";
    cout << rand << endl;
    cout << "\n--------------------------------\n\n";
}

int main() {
    
    srand((unsigned)time(NULL));

    PrintRandom(GetRandomChar(ReadThing()));

    return 0;
}