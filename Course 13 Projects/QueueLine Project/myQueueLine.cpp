#include <iostream>
#include "clsMyQueueLine.h"
using namespace std;

int main() {

    clsMyQueueLine PayBillsLine("A0", 10);

    PayBillsLine.IssueTicket();
    PayBillsLine.IssueTicket();
    PayBillsLine.IssueTicket();
    PayBillsLine.IssueTicket();
    PayBillsLine.IssueTicket();

    PayBillsLine.PrintInfo();

    PayBillsLine.PrintLineRTL();
    PayBillsLine.PrintLineLTR();

    cout << endl;

    PayBillsLine.PrintAllTickets();

    PayBillsLine.ServeNextClient();
    PayBillsLine.ServeNextClient();
    PayBillsLine.ServeNextClient();

    PayBillsLine.PrintLineRTL();

    PayBillsLine.PrintInfo();

    PayBillsLine.PrintAllTickets();

    return 0;
}