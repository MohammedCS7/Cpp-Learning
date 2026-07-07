#include <iostream>
#include <string>


using namespace std;

struct ClientData
{
    string accNumber;
    string pinCode;
    string fullName;
    string phone;
    double balance;
};

string ReadString(string message)
{
    string str;
    cout << message << endl;
    getline(cin, str);
    return str;
}

double ReadDouble(string message)
{
    double num;
    cout << message << endl;
    cin >> num;
    return num;
}

ClientData ReadClientData()
{
    ClientData data;

    data.accNumber = ReadString("Enter Account Number : ");
    
    data.pinCode = ReadString("Enter PIN Code : ");
    
    data.fullName = ReadString("Enter Full Name : ");
    
    data.phone = ReadString("Enter Phone Number : ");
    
    data.balance = ReadDouble("Enter Account Balance : ");

    return data;
}

string Join(string arr[], int length, string delim)
{
    if (length <= 0)
        return "";
    string sen;
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            sen += arr[i] + delim;
        else
            sen += arr[i];
    }
    return sen;
}

string GetClientRecord(ClientData data,string separator)
{
    return data.accNumber + separator + data.pinCode + separator + data.fullName + separator + data.phone + separator + to_string(data.balance);
}

void PrintCLientData(string data)
{
    cout << "Client Record for saving is : " << endl;
    cout << data << endl;
}

int main() {

    cout << "Please Enter Client Data :\n\n";

    ClientData myData = ReadClientData();

    PrintCLientData(GetClientRecord(myData, "#//#"));

    return 0;
}