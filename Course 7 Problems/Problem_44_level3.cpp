#include <iostream>
#include <string>


using namespace std;

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

string RemovePunc(string sen)
{
    
    for (int i = 0; i < sen.length();)
    {
        if (ispunct(sen.at(i)))
            sen.replace(i, 1, "");
        else
            i++;
    }
    return sen;
}
string RemovePuncUsingWhile(string sen)
{
    int i = 0;
    while (i < sen.length())
    {
        if (ispunct(sen[i]))
            sen.erase(i, 1);
        else
            i++;
    }
    return sen;
}
string RemovePuncTeacherMethod(string sen)
{
    string str = "";
    for (int i = 0; i < sen.length(); i++)
    {
        if (!ispunct(sen.at(i)))
            str += sen.at(i);
    }
    return str;
}

int main() {

    string sen = ReadString("Enter String : ");

    cout << "Original String : " << endl;
    cout << sen << endl;

    cout << "Puncuations Removed : \n" << RemovePuncUsingWHile(sen) << endl;

    return 0;
}