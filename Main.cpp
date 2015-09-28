//SSW555
//Agile
//P02
//Laura Pickens

#include "Parser.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	cout << "Starting GEDCOM Parser..." << endl;

	//Get file to parse
	string gedcomFile = "";

	// How to get a string/sentence with spaces
	cout << "Enter the GEDCOM file to parse:\n>";
	getline(cin, gedcomFile);

	gedcomFile = "C:\\Users\\The Russo's\\Documents\\GitHub\\Team2_SSW555_15_GedcomParser\\PickensSSW555P01.ged";
	string outputFile = "C:\\Users\\The Russo's\\Documents\\GitHub\\Team2_SSW555_15_GedcomParser\\PickensP02Output.txt";
	
	bool filePassed = false;
	int person_count = 0; 
	int family_count = 0;
	

	if (isGedcomFile(gedcomFile))
	{
		parseGedcomFile(gedcomFile, outputFile);
	}

	//Print out all information about individuals and families
	system("PAUSE");

	person_count = getPersonCounter(); 
	family_count = getFamilyCounter();
	
	cout << "Number of People: " << person_count << endl; 

	printPeople(); 

	cout << "Number of Families: " << family_count << endl;

	printFamilies();

	system("PAUSE");
	return 0;
}