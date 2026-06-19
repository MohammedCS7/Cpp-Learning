//#include <iostream>
//using namespace std;
//
//struct Info
//{
//    short Age;
//    bool hasLicence;
//};
//
//Info ReadInfo()
//{
//    Info myInfo;
//    cout << "Enter Age : " << endl;
//    cin >> myInfo.Age;
//    cout << "Do you have license : ( 1 or 0 ) " << endl;
//    cin >> myInfo.hasLicence;
//    return myInfo;
//}
//
//bool isAccepted(Info myInfo)
//{
//    return (myInfo.Age >= 21 && myInfo.hasLicence);
//}
//
//void PrintResult(Info myInfo)
//{
//    if (isAccepted(myInfo))
//        cout << "\nHired. \n";
//    else
//        cout << "\nRejected. \n";
//}
//
//int main() {
//    PrintResult(ReadInfo());
//    return 0;
//}