#ifndef PARSER_H
#define PARSER_H

#include<string>

bool isGedcomFile(std::string const & gedcomFile) ;
void parseGedcomFile(std::string const & gedcomFile, std::string const & outputFile);
std::string getLevel(std::string const & gedcomLine);
std::string getTag(std::string const & gedcomLine);
int getPersonCounter(); 
int getFamilyCounter();
void printPeople();
void printFamilies();

#endif