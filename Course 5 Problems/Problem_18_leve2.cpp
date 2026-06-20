#include <iostream>
#include <string>

using namespace std;

int ReadNumber(string message)
{
    int number;
    cout << message << endl;
    cin >> number;
    return number;
}

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
    
}

string Encrypt(string str,int encryptKey)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] + encryptKey;
    }
    return str;
}

string Decrypt(string str, int encryptKey)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] - encryptKey;
    }
    return str;
}

void PrintResult(string name,string encName,int encKey)
{
    cout << "Text Before Encryption : " << name << endl;
    cout << "Text After Encryption : " << encName << endl;
    cout << "Text After Decryption : " << Decrypt(encName,encKey) << endl;
}

int main() {
    string text = ReadString("Enter any Text : ");
    short encryptKey = ReadNumber("Enter the Key : ");
    PrintResult(text,Encrypt(text,encryptKey), encryptKey);

    return 0;
}