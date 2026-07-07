#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string CLIENTS_FILE = "Clients.txt";



struct Client
{
    string accountNumber;
    string pinCode;
    string fullName;
    string phone;
    double balance = 0;
    bool markForDelete = false;
};

void PrintClientCard(const Client& client);

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
    return num;
}

char ReadChar(string message)
{
    char ch;
    cout << message;
    cin >> ch;
    return ch;
}

Client ReadClient()
{
    Client client;
    
  client.accountNumber = ReadString("Enter Account Number : ");
        client.pinCode = ReadString("Enter PIN Code       : ");
       client.fullName = ReadString("Enter Full Name      : ");
          client.phone = ReadString("Enter Phone Number   : ");
        client.balance = ReadDouble("Enter Balance        : ");

    return client;
}

vector <string> SplitString(string str,string sep)
{
    vector <string> words;
    int pos;
    string word;
    while ((pos = str.find(sep)) != string::npos)
    {
        word = str.substr(0, pos);
        if (word != "")
        {
            words.push_back(word);
        }
        str.erase(0, pos + sep.length());
    }
    if (str != "")
        words.push_back(str);
    return words;
}

string JoinString(const vector <string>& words, string sep)
{
    if (words.empty() || sep.empty())
        return "";
    if (words.size() == 1)
        return words.at(0);
    string joined = words.at(0);
    for (const string& word : words)
    {
        joined += sep + word;
    }
    return joined;
}

Client ReadClient(string record, string sep = "#//#")
{
    vector <string> data = SplitString(record, sep);
    Client client;

    client.accountNumber = data[0];
    client.pinCode = data[1];
    client.fullName = data[2];
    client.phone = data[3];
    client.balance = stod(data[4]);

    return client;
}

Client ChangeClientRecord(string accountNumber)
{
    Client client;

    client.accountNumber = accountNumber;
     client.pinCode = ReadString("Enter PIN Code     : ");
    client.fullName = ReadString("Enter Full Name    : ");
       client.phone = ReadString("Enter Phone Number : ");
     client.balance = ReadDouble("Enter Balance      : ");

    return client;
}

string GetClientRecord(Client client, string sep = "#//#")
{
    string record = client.accountNumber + sep +
        client.pinCode + sep +
        client.fullName + sep +
        client.phone + sep +
        to_string(client.balance);
    return record;
}

void SaveClientsToFile(const vector<Client>& clients, string fileName)
{
    fstream File;

    File.open(fileName, ios::out);

    if (File.is_open())
    {
        for (const Client& client : clients)
        {
            if (client.markForDelete == false)
            {
                string dataLine = GetClientRecord(client);
                File << dataLine << endl;
            }
        }
        File.close();
    }
}

vector <Client> LoadClientsFromFile(string fileName)
{
    fstream File;
    Client client;
    
    vector <Client> clients;

    File.open(fileName, ios::in);

    if (File.is_open())
    {
        string dataLine;

        while (getline(File, dataLine))
        {
            client = ReadClient(dataLine);
            clients.push_back(client);
        }

        File.close();
    }
    return clients;
}

bool FindClient(vector <Client>& clients,Client& target, string accountNumber)
{
    for (Client& client : clients)
    {
        if (client.accountNumber == accountNumber)
        {
            target = client;
            return true;
        }
    }
    return false;
}

bool MarkClientForDelete(vector <Client>& clients, string accountNumber)
{
    for (Client& client : clients)
    {
        if (client.accountNumber == accountNumber)
        {
            client.markForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteClient(vector <Client>& clients, string accountNumber)
{
    Client target;
    char choice;
    if (FindClient(clients, target, accountNumber))
    {
        PrintClientCard(target);
        choice = ReadChar("Are you sure to delete this client ? : ");
        if (choice == 'y' || choice == 'Y')
        {
            if (MarkClientForDelete(clients,accountNumber))
            {
                SaveClientsToFile(clients, CLIENTS_FILE);
                clients = LoadClientsFromFile(CLIENTS_FILE);
                cout << "Client Deleted Successfully\n";
                return true;
            }
            else
            {
                cout << "Client Already Marked!\n";
                return false;
            }
        }
        
    }
    else
    {
        cout << "Client with Account Number (" << accountNumber << ") Not Found!" << endl;
        return false;
    }
    return false;
}



bool UpdateClient(vector <Client>& clients,string accountNumber)
{
    Client target,update;
    char choice;
    if (FindClient(clients, target, accountNumber))
    {
        PrintClientCard(target);
        choice = ReadChar("\nAre you sure to update client ? : ");
        if (choice == 'y' || choice == 'Y')
        {
            system("cls");
            for (Client& client : clients)
            {
                if (client.accountNumber == accountNumber)
                {
                    client = ChangeClientRecord(accountNumber);
                    break;
                }
            }
            SaveClientsToFile(clients, CLIENTS_FILE);
            clients = LoadClientsFromFile(CLIENTS_FILE);
            cout << "\nClients Updated Successfully!" << endl;
            return true;
        }
    }
    else
    {
        cout << "Client with Account Number (" << accountNumber << ") Not Found!" << endl;
        return false;
    }
    return false;
}

void PrintClientCard(const Client& client)
{
    cout << "\nThe following are the client details : \n";
    cout << "\nAccount Number     : " << client.accountNumber << endl;
    cout << "PIN Code           : " << client.pinCode << endl;
    cout << "Full Name          : " << client.fullName << endl;
    cout << "Phone Number       : " << client.phone << endl;
    cout << "Account Balance    : " << client.balance << endl;
}

void AddClient(vector <Client>& clients)
{
    Client client = ReadClient();
    clients.push_back(client);
}

void AddClients(vector <Client>& clients)
{
    
    char choice;

    do
    {
        system("cls");

        cout << "Fill Client Data : \n\n";

        AddClient(clients);

        choice = ReadChar("Do you want to add another client ? : ");

    } 
    while (choice == 'y' || choice == 'Y');
    SaveClientsToFile(clients, CLIENTS_FILE);
}



int main() {

    vector <Client> clients = LoadClientsFromFile(CLIENTS_FILE);

    string accNum = ReadString("Enter Account Number : ");

    UpdateClient(clients, accNum);

    return 0;
}