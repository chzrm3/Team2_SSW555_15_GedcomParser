#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Family
{
public:

	int ID_Number = 0;
	string family_id;
	string husband;
	string wife;
	vector<string> children;
	
	Family()
	{

	}

	void printInformation()
	{
		cout << "FAMILY: " << family_id << endl;
		cout << "Husband: " << husband << endl;
		cout << "Wife: " << wife << endl;
		for (int i = 0; i < children.size() - 1; i++) cout << "Child" << i << ": " << children[i] << endl;
	}
};