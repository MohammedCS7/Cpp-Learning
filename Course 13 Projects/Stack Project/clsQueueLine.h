#pragma once
#include "clsMyQueue.h"
#include "Date.h"
#include <iomanip>
class clsQueueLine
{
private:
	int _Number = 0;
	string _Prefix;
	int _Duration;
	struct _Ticket
	{
		string _Name;
		string _DateAndTime;
		int _WaitingTime;
		int _WaitingClients;
	};
	clsMyQueue <_Ticket> _Line;
	int _ServedClients = 0;
	int _WaitingClients = 0;
	static void _PrintTicket(_Ticket ticket)
	{
		cout << left << setw(40) << "" << "______________________________\n\n";
		cout << setw(50) << "" << "Ticket Info: \n";
		cout << left << setw(40) << "" << "______________________________\n\n";
		cout << setw(45) << "" << ticket._DateAndTime << endl;
		cout << setw(45) << "" << "Ticket Name    : " << ticket._Name << endl;
		cout << setw(45) << "" << "Waiting Clients: " << ticket._WaitingClients << endl;
		cout << setw(45) << "" << "Serve Time : " << ticket._WaitingTime << endl;
		cout << left << setw(40) << "" << "______________________________\n";
	}
public:
	clsQueueLine(string prefix, int duration)
	{
		_Prefix = prefix;
		_Duration = duration;
	}
	void IssueTicket()
	{
		_Number++;
		_WaitingClients++;
		_Ticket ticket;
		ticket._DateAndTime = Date::GetSystemDateTime();
		ticket._Name = _Prefix + to_string(_Number);
		ticket._WaitingClients = _Line.Size();
		ticket._WaitingTime = _Duration * _Line.Size();
		_Line.push(ticket);
	}
	void ServeClient()
	{
		if (_Number > 0)
		{
			_Line.pop();
			_ServedClients++;
			_WaitingClients--;
			for (int i = 0; i < _Line.Size(); i++)
			{
				

			}
		}
	}
	void PrintInfo()
	{
		cout << left << setw(40) << "" << "______________________________\n\n";
		cout << setw(50) << "" << "Queue Info: \n";
		cout << left << setw(40) << "" << "______________________________\n\n";
		cout << setw(45) << "" << "Prefix         : " << _Prefix << endl;
		cout << setw(45) << "" << "Total Tickets  : " << _Number << endl;
		cout << setw(45) << "" << "Served Clients : " << _ServedClients << endl;
		cout << setw(45) << "" << "Waiting Clients: " << _WaitingClients << endl;
		cout << left << setw(40) << "" << "______________________________\n";
	}
	void PrintTickets()
	{
		for (int i = 0; i < _Line.Size(); i++)
		{
			_PrintTicket(_Line.GetValue(i));
		}
	}
	void PrintTicketsLineRTL()
	{
		cout << endl;
		cout << left << setw(40) << "";
		for (int i = 0; i < _Line.Size(); i++)
		{
			cout << _Line.GetValue(i)._Name;
			if (i + 1 != _Line.Size())
				cout << " <--- ";
		}
		cout << endl;
	}
	void PrintTicketsLineLTR()
	{
		cout << endl;
		cout << left << setw(40) << "";
		for (int i = _Line.Size() - 1; i >= 0; i--)
		{
			cout << _Line.GetValue(i)._Name;
			if (i != 0)
				cout << " ---> ";
		}
		cout << endl;
	}
};

