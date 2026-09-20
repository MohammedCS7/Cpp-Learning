#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;

int main() {


    clsMyQueueArr<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);

    cout << "\nQueue: \n";
    myQueue.Print();

    cout << "\nQueue Size: " << myQueue.Size() << endl;
    cout << "\nQueue Front: " << myQueue.front() << endl;
    cout << "\nQueue Back: " << myQueue.back() << endl;

    myQueue.pop();

    cout << "\nQueue After Pop: \n";
    myQueue.Print();

    return 0;
}