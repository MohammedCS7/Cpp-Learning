#include <iostream>
#include "String.h"
using namespace std;

int main() {


    String string1;
    String string2("Mohammed");

    string1.Value = "Mohammed Abu-Hadhoud";

    cout << string1.CountVowels() << endl;

    

    return 0;
}