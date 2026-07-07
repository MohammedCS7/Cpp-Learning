#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

string ReplaceBuiltIn(string sen, string old, string update)
{
    short pos;
    while ((pos = sen.find(old)) != string::npos)
    {
        sen.replace(pos, old.length(), update);
        pos = sen.find(old);
    }
    return sen;
}

int main() {

    string sen = ReadString("Enter String : ");

    string old = ReadString("What do u Want to Replace : ");
    string update = ReadString("What do u Want to Replace it with : ");

    cout << "String after Replace : " << endl;
    cout << ReplaceBuiltIn(sen,old,update) << endl;


    return 0;
}