#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;



int main() {

    Date date2("23/7/2025");

    cout << "It's : " << date2.ToString() << endl;
    cout << "And it can be : " << date2.Format("mm/dd/yyyy") << endl;
    cout << "What about : " << date2.Format("yyyy/mm/dd") << endl;
    cout << "The crazy one is : " << date2.Format("The days is dd, the month is mm, and the year is yyyy");


    return 0;
}