//addressBookType.h 
 
#ifndef H_addressBookType
#define H_addressBookType
  
#include <string>
#include <fstream>
#include <vector>

using namespace std;
#include "extPersonType.h"


class addressBookType
{
public:
    void print() const;
    void loadData();
    void saveData();
private:
    vector<extPersonType> list;
};

void addressBookType::print() const
{
    for (int i = 0; i < list.size(); i++)
        list[i].printInfo();
}

void addressBookType::loadData() {
	ifstream infile;

	char filename[50];

	cout << "Enter file name: ";
	cin >> filename;
	cout << endl;

	infile.open(filename);
	if (!infile) {
		cout << "Input file does not exists. " << "Program terminates!!!"
				<< endl;
		return;
	}

	string first, last;
	int day,month,year;
    string street, city, state, zip, phone, pStatus;

	while (infile >> first) {
		infile >> last >> month >> day >> year;
		infile.ignore(100, '\n');
		getline(infile, street);
		infile >> city >> state >> zip >> phone >> pStatus;
		extPersonType temp(first, last, month, day, year, street, city, state, zip,
				phone, pStatus);

	    list.push_back(temp);
	}

	infile.close();
}

void addressBookType::saveData()
{
	ofstream outFile;
	outFile.open("dataOut.txt");

    string street, city, state, zip, phone, pStatus;

    for (int i = 0; i < list.size(); i++)
    {
    	//Add code here to store all address data in list into the file dataOut.txt
        
    outFile << "TBA" << endl;

    }
    outFile.close();
}

#endif
