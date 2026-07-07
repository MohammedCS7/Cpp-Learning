#include <iostream>
#include <string>
#include <vector>

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

ClientData ReadClientData(string dataLine,string seperator = "#//#")
{
    ClientData data;

    int sepLen = seperator.length();
    int pos = dataLine.find(seperator);

    data.accNumber = dataLine.substr(0, pos);

    dataLine.erase(0, pos + sepLen);
    pos = dataLine.find(seperator);

    data.pinCode = dataLine.substr(0, pos);

    dataLine.erase(0, pos + sepLen);
    pos = dataLine.find(seperator);

    data.fullName = dataLine.substr(0, pos);

    dataLine.erase(0, pos + sepLen);
    pos = dataLine.find(seperator);

    data.phone = dataLine.substr(0, pos);
    dataLine.erase(0, pos + sepLen);
    pos = dataLine.find(seperator);

    data.balance = stod(dataLine);

    return data;
}

ClientData ReadClientData(const vector <string>& vData, string seperator = "#//#")
{
    ClientData data;

    data.accNumber = vData[0];
    data.pinCode   = vData[1];  
    data.fullName  = vData[2];
    data.phone     = vData[3];
    data.balance   = stod(vData[4]);

    return data;
}

vector <string> Split(string sen, string delim)
{
    vector <string> words;
    if (sen.length() < delim.length() || sen.empty() || delim.empty())
        return words;
    sen.append(delim);
    int wordStart = 0;
    int deLen = delim.length();
    for (int i = 0; i < sen.length(); i++)
    {
        if (sen.compare(wordStart, deLen, delim) == 0)
        {
            wordStart += deLen;
            if (i < wordStart) i = wordStart;
        }
        else if (sen.compare(i, deLen, delim) == 0 && sen.compare(wordStart, deLen, delim) != 0)
        {
            words.push_back(sen.substr(wordStart, i - wordStart));
            wordStart = i + deLen;
            i = wordStart;

        }
    }
    return words;
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

string GetClientRecord(ClientData data, string separator)
{
    return data.accNumber + separator + data.pinCode + separator + data.fullName + separator + data.phone + separator + to_string(data.balance);
}

void PrintClientData(string data)
{
    cout << "Client Record for saving is : " << endl;
    cout << data << endl;
}

void PrintClientData(ClientData data)
{
    cout << "Account Number   : " << data.accNumber << endl;
    cout << "PIN Code         : " << data.pinCode << endl;
    cout << "Full Name        : " << data.fullName << endl;
    cout << "Phone Number     : " << data.phone << endl;
    cout << "Account Balance  : " << data.balance << endl;
}

int main() {

    cout << "Please Enter Client Data :\n\n";

    ClientData myData = ReadClientData();

    string dataRec = GetClientRecord(myData, "#//#");

    cout << "Line Record is : " << endl;
    cout << dataRec << endl;

    vector <string> vClientData = Split(dataRec,"#//#");

    myData = ReadClientData(vClientData);

    cout << "The following is the extracted client record : " << endl << endl;
    PrintClientData(myData);

    return 0;
}