#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "Date.h"

using namespace std;

int main()
{
	// Test 1
	Date d1(1, 4, 2012), d2(3, 4, 2012);
	if (d1 < d2)
		cout << " yes" << endl;
	else
		cout << "no" << endl;

	// Test 2
	ifstream fin;
	ofstream fout;

	// Read a date from the file
	fin.open("date_in.txt");
	if (fin.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	fout.open("date_out.txt");
	if (fout.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	char deliminator;
	int day = 0;
	int month = 0;
	int year = 0;

	// fin >> day;
	// fin.get(deliminator);
	// fin >> month;
	// fin.get(deliminator);
	// fin >> year;
	// fin.get(deliminator);

	while (!fin.eof())
	{
		// Take in the values and place in variables, deliminators are stored but not used
		fin >> day >> deliminator >>
			month >> deliminator >> year;

		// initiate constructor
		Date d(day, month, year);
		cout << d << endl;
		// output the date to a file
		fout << d << endl;
	}

	// close the files
	fin.close();
	fout.close();
	return 0;
}
