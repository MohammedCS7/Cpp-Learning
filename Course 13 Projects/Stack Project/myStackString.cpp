#include <iostream>
#include "clsMyString.h"
using namespace std;

int main() {

    clsMyString S1;

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Mohammed1";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Mohammed2";

    cout << "\nS1 = " << S1.Value << endl;

    S1.Value = "Mohammed3";

    cout << "\n\n\t\tUNDO: \n";

    S1.Undo();

    cout << "S1 = " << S1.Value << endl;

    S1.Undo();

    cout << "S1 = " << S1.Value << endl;

    S1.Undo();

    cout << "S1 = " << S1.Value << endl;

    return 0;
}