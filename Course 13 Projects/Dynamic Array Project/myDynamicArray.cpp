#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main() {

    clsDynamicArray<int> myArray(5);

    myArray.SetItem(0, 10);
    myArray.SetItem(1, 20);
    myArray.SetItem(2, 30);
    myArray.SetItem(3, 40);
    myArray.SetItem(4, 50);

    cout << "\nIs Empty?: " << myArray.IsEmpty();
    cout << "\nArray Size: " << myArray.Size();
    cout << "\nArray Items: \n";

    myArray.PrintList();

    cout << "\nItem at index 3 is: " << myArray.GetValue(3);


    cout << "\nThe Value 40, is in index: " << myArray.Find(40) << endl;

    cout << "\nThe Array after inserting 67 at index 3 is: " << endl;

    myArray.InsertAt(5, 67);

    myArray.PrintList();


    return 0;
}