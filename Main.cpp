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

	gedcomFile = "C:\\Users\\Laura\\Documents\\Stevens\\SSW555\\Week 1\\PickensSSW555P01.ged";
	string outputFile = "C:\\Users\\Laura\\Documents\\Stevens\\SSW555\\Week 2\\PickensP02Output.txt";
	
	bool filePassed = false;

	if (isGedcomFile(gedcomFile))
	{
		parseGedcomFile(gedcomFile, outputFile);
	}

	//End program
	system("PAUSE");
	return 0;
}