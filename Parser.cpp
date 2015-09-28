#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Parser.h"
#include "Person.cpp" 
#include "Family.cpp"

using namespace std;

const int VALID_TAGS_SIZE = 17;

int person_counter = 0;
Person* list_of_people = new Person[5000]; 
int family_counter = 0;
int child_counter = 0;
Family* list_of_families = new Family[1000];

string valid_tags[VALID_TAGS_SIZE] =
{ "INDI", "NAME", "SEX", "BIRT", "DEAT", "FAMC", 
  "FAMS", "FAM", "MARR", "HUSB", "WIFE", "CHIL",
  "DIV", "DATE", "HEAD", "TRLR", "NOTE" };

bool isGedcomFile(string const & gedcomFile)
{
	if (gedcomFile.substr(gedcomFile.size() - 4, gedcomFile.size() - 1) == ".ged")
	{
		ifstream ifile(gedcomFile);
		return ifile.is_open();
	}

	return false;
}

string getLevel(string const & gedcomLine)
{
	string Level = "";

	size_t found = gedcomLine.find(" ");
	if (found != std::string::npos)
		Level = gedcomLine.substr(0, found);

	return Level;
}

string getTag(string const & gedcomLine)
{
	string Tag = "";

	size_t first = gedcomLine.find(" ");
	if (first != std::string::npos)
	{
		size_t second = gedcomLine.find(" ", first + 1);
		if (second != std::string::npos)
			Tag = gedcomLine.substr(first + 1, second - 2);
		if (Tag.find("@") != std::string::npos)
		{
			Tag = gedcomLine.substr(second + 1);
		}
	}

	bool isValid = false;
	for (int i = 0; i < VALID_TAGS_SIZE; i++)
	{
		if (Tag == valid_tags[i])
		{
			isValid = true;
		}
	}

	if (!isValid)
	{
		Tag = "Invalid Tag";
	}

	if (Tag == "NAME")
	{
		cout << "Got a name over here!" << endl; 
		person_counter++; 
		list_of_people[person_counter].Person_Name = gedcomLine; 
		list_of_people[person_counter].ID_Number = person_counter; 
		list_of_people[person_counter].testPerson(); 
	}

	if (Tag == "FAM")
	{
		cout << "Got a family over here!" << endl;
		list_of_families[family_counter].ID_Number = family_counter;
		list_of_families[family_counter].family_id = Tag;
		family_counter++;
	}
	if (Tag == "HUSB")
	{
		cout << "Got a husband" << endl;
		list_of_families[family_counter].husband = Tag;
	}
	if (Tag == "WIFE")
	{
		cout << "Got a wife" << endl;
		list_of_families[family_counter].wife = Tag;
	}
	if (Tag == "CHIL")
	{
		cout << "Got a child" << endl;
		list_of_families[family_counter].children[child_counter] = Tag;
		child_counter++;
	}

	return Tag;
}

void printAndWrite(string const & line, ofstream & outFile)
{
	cout << line << endl;
	outFile << line << endl;
}



void parseGedcomFile(string const & gedcomFile, string const & outputFile)
{
	ifstream ifile(gedcomFile);
	ofstream ofile(outputFile);

	string sLine = "";
	string level = "";
	string tag = "";

	while (!ifile.eof())
	{
		getline(ifile, sLine);
		if (sLine != "")
		{
			//Get level
			level = getLevel(sLine);
			//Get tag
			tag = getTag(sLine);
			//See if tag is valid
			printAndWrite("Line: " + sLine, ofile);
			printAndWrite("Level: " + level, ofile);
			printAndWrite("Tag: " + tag, ofile);
			printAndWrite("", ofile);
		}
	}

	ifile.close();
	ofile.close();

}

int getPersonCounter()
{
	return person_counter; 
}

int getFamilyCounter()
{
	return family_counter;
}


void printPeople()
{
	for (int x = 0; x < person_counter; x++)
	{
		list_of_people[x].printInformation(); 
	}
}

void printFamilies()
{
	for (int x = 0; x < family_counter; x++)
	{
		list_of_families[x].printInformation();
	}
}