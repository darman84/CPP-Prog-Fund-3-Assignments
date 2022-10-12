#include <iostream>
#include <string>
#include "hashT.h"
#include "presData.h"

using namespace std;

void presData::setPresInfo(string name, int yearOfBirth, string party, int yearsInOffice)
{
	presName = name;
	presYearOfBirth = yearOfBirth;
	presParty = party;
	presYearsInOffice = yearsInOffice;
}

void presData::getPresInfo(string& name, int& yearOfBirth, string& party, int& yearsInOffice)
{
	name = presName;
	yearOfBirth = presYearOfBirth;
	party = presParty;
	yearsInOffice = presYearsInOffice;
}

string presData::getPresName()
{
	return presName;
}

int presData::getYearOfBirth()
{
	return presYearOfBirth;
}


string presData::getParty()
{
	return presParty;
}

int presData::getYearsInOffice()
{
	return presYearsInOffice;
}

void presData::printInfo()
{
	cout << "President name: " << presName << endl;
	cout << "Born in: " << presYearOfBirth << endl;
	cout << "Party: " << presParty << endl;
	cout << "Years in office: " << presYearsInOffice << endl;
}

bool presData::operator==(const presData& right) const
{
	return (presName == right.presName);
}

bool presData::operator!=(const presData& right) const
{
	return (presName != right.presName);
}

ostream& operator<<(ostream& os, const presData& st)
{
	os  << "President name: " << st.presName << endl;
	os  << "Born in: " << st.presYearOfBirth << endl;
	os  << "Party: " << st.presParty << endl;
	os  << "Years in office: " << st.presYearsInOffice << endl;

	return os;
}

istream& operator>>(istream& is, presData& st)
{
	char ch;
	getline(is, st.presName);
	is >> st.presYearOfBirth;
	is.ignore(1);
	getline(is, st.presParty);
    is >> st.presYearsInOffice;
	is.get(ch);

	return is;
}
