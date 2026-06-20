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

bool GetPassword(string password)
{
    string passGuess = "";
    int trial = 0;
    for (int i = 65; i <= 90; i++)
    {
        
        for (int j = 65; j <= 90; j++)
        {
            
            for (int k = 65; k <= 90; k++)
            {
                passGuess.append(1, char(i));
                passGuess.append(1, char(j));
                passGuess.append(1, char(k));
                cout << "Trial [" << trial+1 << "] : " << passGuess << endl;
                trial++;
                if (passGuess == password)
                {
                    cout << "Password is " << passGuess << endl << "Found after " << trial << " Trial(s)" << endl;
                    return true;
                }
                passGuess = "";
            }
       
         
        }
        
    }
    return false;
}

int main() {

    GetPassword(ReadString("Enter The Passowrd ( 3 Capital Letters ) : "));

    return 0;
}