#include <iostream>
#include <string>

using namespace std;

void PrintName(string name)
{
	cout << "My Name is : " << name << endl;
}

string ReadName()
{
	string name;
	cout << "Enter your Name : " << endl;
	getline(cin, name);
	return name;
}

int main()
{
	 ;
	PrintName(ReadName());

	return 0;
}