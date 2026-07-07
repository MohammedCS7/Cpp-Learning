#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string CLIENTS_FILE = "Clients.txt";

struct ClientData
{
    string accNumber;
    string pinCode;
    string fullName;
    string phone;
    bool deleteMark = false;
    double balance = 0;
};

string ReadString(string message)
{
    string str;
    cout << message;
    getline(cin >> ws, str);
    return str;
}

double ReadDouble(string message)
{
    double num;
    cout << message;
    cin >> num;
    cin.ignore(100, '\n');
    return num;
}

char ReadChar(string message)
{
    char ch;
    cout << message << endl;
    cin >> ch;
    cin.ignore(100, '\n');
    return ch;
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

ClientData ReadClientData(string dataLine, string seperator = "#//#")
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
    data.pinCode = vData[1];
    data.fullName = vData[2];
    data.phone = vData[3];
    data.balance = stod(vData[4]);

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

string GetClientRecord(ClientData data, string separator = "#//#")
{
    return data.accNumber + separator + data.pinCode + separator + data.fullName + separator + data.phone + separator + to_string(data.balance);
}

void SaveDataToFile(string fileName, const vector <ClientData>& clients)
{
    fstream File;
    File.open(fileName, ios::out);
    string dataLine;
    if (File.is_open())
    {
        for (const ClientData& client : clients)
        {
            
            if (client.deleteMark == false)
            {
                dataLine = GetClientRecord(client);
                File << dataLine << endl;
            }
        }
        File.close();
    }
}

void SaveDataToFile(string fileName, string dataLine)
{
    fstream File;
    File.open(fileName, ios::out | ios::app);
    
    if (File.is_open())
    {
                     
          File << dataLine << endl;
        
        File.close();
    }
}

void AddClient()
{
    ClientData data = ReadClientData();
    string dataLine = GetClientRecord(data);
    SaveDataToFile("Clients.txt", dataLine);
    cout << "Client Added Successfully, ";
}

void AddClients()
{
    char choice = ' ';
    do
    {

        system("cls");

        AddClient();

        choice = ReadChar("\nDo you want to add more clients ? : ");


    } while (choice == 'y' || choice == 'Y');
}

vector <ClientData> LoadClientsData(string fileName)
{
    fstream File;
    ClientData data;
    vector <ClientData> clients;

    File.open(fileName, ios::in);

    if (File.is_open())
    {
        string dataLine;
        while (getline(File, dataLine))
        {
            
                data = ReadClientData(dataLine);
                if (data.deleteMark == false)
                clients.push_back(data);
        }
        File.close();
    }
    return clients;
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

void PrintClientRecord(ClientData data)
{
    cout << left;
    cout << "| " << setw(15) << data.accNumber;
    cout << "| " << setw(15) << data.pinCode;
    cout << "| " << setw(40) << data.fullName;
    cout << "| " << setw(25) << data.phone;
    cout << "| " << setw(15) << data.balance;
    cout << endl;
}

void PrintAllClients(const vector <ClientData>& clients)
{
    cout << setw(60) << "Client List (" << clients.size() << ") Client(s)." << endl;
    cout << "\n------------------------------------------------------------------------------------------------------------------------\n\n";
    cout << left;
    cout << "| " << setw(15) << "Account Number";
    cout << "| " << setw(15) << "PIN Code";
    cout << "| " << setw(40) << "Client Name";
    cout << "| " << setw(25) << "Phone";
    cout << "| " << setw(15) << "Balance";
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
    for (const ClientData& data : clients)
    {
        PrintClientRecord(data);
    }
    cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
}

bool FindClient(vector <ClientData>& clients, ClientData& client, string accNum)
{

    for (const ClientData& data : clients)
    {
        if (data.accNumber == accNum)
        {
            client = data;
            return true;
        }
    }
    return false;
}

void PrintClientSearch(bool isFound, const ClientData& client, string accNum)
{
    if (isFound)
    {
        cout << "\nThe following are the client details : " << endl;
        PrintClientData(client);
    }
    else
    {
        cout << "\nClient with Account Number (" << accNum << ") Not found!" << endl;
    }
}

bool DeleteClient(vector <ClientData>& clients,ClientData& client)
{
    vector <ClientData>::iterator iter;
    for (iter = clients.begin(); iter != clients.end();iter++)
    {
        if (iter->accNumber == client.accNumber)
        {
            clients.erase(iter);
            return true;
        }
    }
    return false;
}

void PrintAndDeleteClient(vector <ClientData>& clients, string accNum)
{
    ClientData target;
    char choice;
    if (FindClient(clients, target, accNum))
    {
        PrintClientData(target);
        choice = ReadChar("Are you sure you want to delete this client ? : ");
        if (choice == 'y' || choice == 'Y')
        {
            DeleteClient(clients, target);
            SaveDataToFile(CLIENTS_FILE, clients);
            LoadClientsData(CLIENTS_FILE);
            cout << "\nClient Deleted Successfully!";
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accNum << ") Not found!" << endl;
    }
}

bool DeleteClientTeacherMethod(vector <ClientData>& clients, string accNum)
{
    if ( clients.empty() || accNum.empty() )
        return false;
    ClientData target;
    if (FindClient(clients, target, accNum))
    {
        target.deleteMark = true;
        return true;
    }
    return false;
}


void DeleteClientUsingTeacherMethod(vector <ClientData>& clients,string accNum)
{
    ClientData target;
    char choice;
    if (FindClient(clients, target, accNum))
    {
        PrintClientData(target);
        choice = ReadChar("Do you want delete client ? : ");
        if (choice == 'y' || choice == 'Y' && DeleteClientTeacherMethod(clients, accNum))
        {
            SaveDataToFile(CLIENTS_FILE, clients);
            LoadClientsData(CLIENTS_FILE);
            cout << "Client Deleted Successfully" << endl;
        }
        else
        {
            cout << "Error, Something Went Wrong!" << endl;
        }
    }
}

int main() {

    ClientData client;

    vector <ClientData> clients = LoadClientsData(CLIENTS_FILE);

    string accNum = ReadString("Please enter the Account Number : ");

    PrintAndDeleteClient(clients, accNum);

    PrintAllClients(clients);

    return 0;
}