// addressBookType.h

#ifndef H_addressBookType
#define H_addressBookType

#include <iostream>
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

void addressBookType::loadData()
{
	ifstream infile;

	char filename[50]; // string of 50 characters - i.e filename

	cout << "Enter file name: ";
	cin >> filename;
	cout << endl;

	infile.open(filename);
	// if the filename is NOT dataIn.txt, terminate program
	if (!infile)
	{
		cout << "Input file does not exists. "
			 << "Program terminates!!!"
			 << endl;
		return;
	}

	// initialise variables to capture data in txt file
	string first, last;								 // first and last name
	int day, month, year;							 // date
	string street, city, state, zip, phone, pStatus; // addresses, phone number and personal status

	while (infile >> first)
	{ // end of file check with read, returns false when no more first name
		// after reading the first name, read last name, day, month, year etc
		infile >> last >> day >> month >> year;

		// ignore upto 100 characters, or until a space is found
		infile.ignore(100, '\n');

		getline(infile, street); // street name has spaces so use getline(fin, variable) function
		infile >> city >> state >> zip >> phone >> pStatus;

		// pass variables into class and create a profile under 'temp'
		extPersonType temp(first, last, day, month, year, street, city, state, zip,
						   phone, pStatus);

		// add to vector
		list.push_back(temp);
	}

	// close the file
	infile.close();
}

void addressBookType::saveData()
{
	ofstream outFile;
	outFile.open("dataOut.txt");

	// check file opens correctly
	if (outFile.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	// initiate variables to store address data
	string street, city, state, zip;

	// for each element of the vector 'list'
	for (extPersonType i : list)
	{
		// write onto file, details of the extPersonType using methods from the abstract classes
		outFile << "Name: " << i.getFirstName() << " " << i.getLastName() << "\n"
				<< "Date of Birth: " << i.getDOB().getDay() << "/" << i.getDOB().getMonth() << "/" << i.getDOB().getYear() << "\n"
				<< "Phone Number: " << i.getPhoneNumber() << "\n"
				<< "Person Type: " << i.getStatus() << "\n";

		// get address details 
		i.getAddress().getDetails(street, city, state, zip);

		// since .getDetails() returns a reference, variables will contain the relevant data
		outFile << street << "  " << city << ", " << state<< ", "<< zip << endl << endl;
	}

	cout << "File construction complete.\n"
		 << endl;

	outFile.close();
}

#endif
