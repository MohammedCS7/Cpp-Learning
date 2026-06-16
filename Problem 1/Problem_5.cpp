#include <iostream>
using namespace std;

struct Info
{
    short Age;
    bool hasLicence;
    bool hasRecommendation;
};

Info ReadInfo()
{
    Info myInfo;
    cout << "Enter Age : " << endl;
    cin >> myInfo.Age;
    cout << "Do you have license : ( 1 or 0 ) " << endl;
    cin >> myInfo.hasLicence;
    cout << "Do you have Recommendation : ( 1 or 0 ) " << endl;
    cin >> myInfo.hasRecommendation;
    return myInfo;
}

bool isAccepted(Info myInfo)
{

    if (myInfo.hasRecommendation)
        return true;
    else
        return (myInfo.Age >= 21 && myInfo.hasLicence);
}

void PrintResult(Info myInfo)
{
    if (isAccepted(myInfo))
        cout << "\nHired. \n";
    else
        cout << "\nRejected. \n";
}

int main() {
    PrintResult(ReadInfo());
    return 0;
}