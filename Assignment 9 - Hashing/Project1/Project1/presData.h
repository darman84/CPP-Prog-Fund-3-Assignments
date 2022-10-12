#include <iostream>
#include <string>
#include "hashT.h"

using namespace std;

class presData
{
	friend ostream& operator<<(ostream&, const presData&);
	friend istream& operator>>(istream&, presData&); 
public:
	void setPresInfo(string name, int yearOfBirth, string party, int yearsInOffice);

	void getPresInfo(string& name, int& yearOfBirth, string& party, int& yearsInOffice);

	string getPresName();
	int getYearOfBirth();
	string getParty();
	int getYearsInOffice();

	void printInfo();

	bool operator==(const presData& right) const;
	bool operator!=(const presData& right) const;

private:
	string presName;
	int presYearOfBirth;
	string presParty;
	int presYearsInOffice;
};  