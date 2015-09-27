#include <iostream>
#include <string> 

using namespace std; 

class Person
{
public: 

	int ID_Number = 0; 
	string Person_UID; 
	string Person_Name; 
	string Person_Gender; 
	string Person_Birthday; 
	string Person_Family_Name; 


	Person()
	{

	}

	void testPerson()
	{
		cout << "Can you see me?" << endl; 
		cout << "My name is: " << Person_Name << endl; 
		cout << "My unique id is: " << Person_UID << endl; 
	}

	void printInformation()
	{
		cout << "NAME: " << Person_Name << endl; 
		cout << "ID: " << Person_UID << endl;
		cout << "Person Number: " << ID_Number << endl; 
	}
};