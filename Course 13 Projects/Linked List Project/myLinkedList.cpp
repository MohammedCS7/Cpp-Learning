#include <iostream>
#include "clsDblLinkedList.h"
using namespace std;

int main() {

    clsDblLinkedList<int> myList;

    myList.InsertAtFirst(5);
    myList.InsertAtFirst(4);
    myList.InsertAtFirst(3);
    myList.InsertAtFirst(2);
    myList.InsertAtFirst(1);


    myList.InsertAfter(1, 500);
    
    myList.PrintList();

    

    //cout << "\nThe Number 1 in the list is: " << myList.GetValue(10) << endl;

    return 0;
}