#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Parser.h"
#include "Person.cpp" 

using namespace std;

const int VALID_TAGS_SIZE = 17;

int person_counter = 0;
Person* list_of_people = new Person[5000]; 


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

string getUniqueID(string const & gedcomLine)
{
	string UniqueID = "";

	size_t first = gedcomLine.find(" ");
	if (first != std::string::npos)
	{
		size_t second = gedcomLine.find(" ", first + 1);
		if (second != std::string::npos)
		{
			UniqueID = gedcomLine.substr(first + 1, second - 2);
		}
		UniqueID = gedcomLine.substr(first, second);
	}

	return UniqueID;
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

	bool buildPerson = false;
	bool buildFamily = false;
	while (!ifile.eof())
	{
		getline(ifile, sLine);

		if (sLine != "")
		{
			//Get level
			level = getLevel(sLine);
			//Get tag
			tag = getTag(sLine);
			if (buildPerson)
			{
				if (tag == "NAME")
				{
					list_of_people[person_counter].Person_Name = sLine;
					list_of_people[person_counter].testPerson();
				}
				else
				{
					buildPerson = false;
				}
			}
			else if (buildFamily)
			{

			}
			else
			{
				if (tag == "INDI")
				{
					cout << "Got a person over here!" << endl;
					person_counter++;
					buildPerson = true;
					list_of_people[person_counter].Person_UID = getUniqueID(sLine);
				}
				else if (tag == "FAM")
				{

				}
			}
			//See if tag is valid
			//printAndWrite("Line: " + sLine, ofile);
			//printAndWrite("Level: " + level, ofile);
			//printAndWrite("Tag: " + tag, ofile);
			//printAndWrite("", ofile);
		}
	}

	ifile.close();
	ofile.close();
}

int getPersonCounter()
{
	return person_counter; 
}

void printPeople()
{
	for (int x = 0; x < person_counter; x++)
	{
		list_of_people[x].printInformation(); 
	}
}