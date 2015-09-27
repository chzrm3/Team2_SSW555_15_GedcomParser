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

	gedcomFile = "C:\\Users\\Chzrm\\Desktop\\My-Family-13-Sep-2015.ged";
	string outputFile = "C:\\Users\\Laura\\Documents\\Stevens\\SSW555\\Week 2\\PickensP02Output.txt";
	
	bool filePassed = false;
	int person_count = 0; 
	

	if (isGedcomFile(gedcomFile))
	{
		parseGedcomFile(gedcomFile, outputFile);
	}

	//Print out all information about individuals and families
	system("PAUSE");

	person_count = getPersonCounter(); 
	
	cout << "Number of People: " << person_count << endl; 

	printPeople(); 

	system("PAUSE"); 
	return 0;
}