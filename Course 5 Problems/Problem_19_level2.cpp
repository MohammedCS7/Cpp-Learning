#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void PrintThreeRandomNumbers()
{
    for (int i = 1; i <= 3; i++)
    {
        cout << RandomNumber(1, 10) << endl;
    }
}
int main() {
    srand((unsigned)time(NULL));

    PrintThreeRandomNumbers();

    return 0;
}