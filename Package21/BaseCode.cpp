#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#include "Date.h"

class Voucher
{
	// Hint: Add your code as part of the solution to Task 2
protected:
	long voucherNumber;
	string voucherCode;
	string name;
	Date *expiryDate;
	int value;

	char voucherType;

public:
	// default
	Voucher() {}
	~Voucher() {}

	// vector constructor
	Voucher(char vT, long vN, string vC, string n, Date *d)
	{
		voucherType = vT;
		voucherNumber = vN;
		voucherCode = vC;
		name = n;
		expiryDate = d;
	}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void initialActiveVoucher(long vn, string n, Date *d,
							  int v)
	{
		voucherNumber = vn;
		name = n;
		expiryDate = new Date(21, 10, 2021);
		value = v;
	}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void initialDineVoucher(string vc, string n, Date *d,
							int v)
	{
		voucherCode = vc;
		name = n;
		expiryDate = d;
		value = v;
	}

	virtual void printVoucher(ostream &sout) = 0;
};

// Hint: Rebuild the class for Tasks 2&3 and better OOP style
class ActiveVoucher : public Voucher
{
public:
	ActiveVoucher() {}
	~ActiveVoucher() {}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void printVoucher(ostream &sout)
	{ // ostream is an object of output stream, such as cout
		sout << "\nActive Voucher:" << endl;
		sout << "Voucher number: " << setfill('0') << setw(8)
			 << voucherNumber << endl;
		sout << "Name: " << name << endl;
		sout << "Expiry Date: " << *expiryDate << "\tValue: $"
			 << value << endl;
	}
};

// Hint: Rebuild the class for Tasks 2&3 and better OOP style
class DineVoucher : public Voucher
{
public:
	DineVoucher() {}
	~DineVoucher() {}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void printVoucher(ostream &sout)
	{
		sout << "\nDine Voucher:" << endl;
		sout << "Name: " << name << endl;
		sout << "Voucher code: " << voucherCode << endl;
		sout << "Expiry Date: " << *expiryDate << "\tValue: $"
			 << value << endl;
	}
};

// Hint: Rebuild the class for Tasks 4&5 and better OOP style
class ProcessVouchers
{
protected:
	vector<Voucher> voucher;

public:
	ProcessVouchers() {}
	~ProcessVouchers() {}

	void inputVouchers()
	{
		ifstream fin;
		fin.open("voucherlist.txt"); // if you IDE cannot file the file, add the absolution path to the file name,
									 //  say "/Users/dongmo/cloudstor/Teaching/OOP21/Lectures/DemoCode/exam/Voucher/voucherlist.txt"

		if (fin.fail())
		{
			cout << "Cann't open file!" << endl;
			return;
		}

		string voucherType;
		int voucherNumber;
		string voucherCode, name;
		int day, month, year;
		char c;

		cout << "\nVoucher registration list: " << endl;
		while (!fin.eof())
		{
			fin >> voucherType;
			if (voucherType == "Active")
			{
				fin >> voucherNumber;
				fin >> day >> c >> month >> c >> year;
				getline(fin, name, '\r'); // change to '\n' if '\r' does not work for your OS
				cout << "Active " << voucherNumber << "" << day << "/" << month
					 << "/" << year << name << endl;

				// Voucher temp('A', voucherNumber, "AAAAAAAA", name,new Date(day,month,year));
				// voucher.push_back(temp);
			}
			else
			{
				fin >> voucherCode;
				fin >> day >> c >> month >> c >> year;
				getline(fin, name, '\r'); // change to '\n' if '\r' does not work for your OS

				cout << "Dine " << voucherCode << " " << day << "/" << month
					 << "/" << year << name << endl;
			}
		}

		fin.close();
	}

	void printVouchers()
	{
		cout << "\nVoucher printout:" << endl;
		// to be implemented for Task 5
	}
};

int main()
{
	// Hint: Vary the following code to complete Task 1
	cout << "Test class ActiveVoucher class ..." << endl;
	ActiveVoucher avoucher;
	avoucher.initialActiveVoucher(20658133, "Kevin Reyes",
								  new Date(21, 10, 2021), 100);
	avoucher.printVoucher(cout);

	cout << endl;

	cout << "Test class DineVoucher class ..." << endl;
	DineVoucher dvoucher;
	string vCode = "AAAAAAAA";

	for (int i = 0; i < 8; i++)
	{
		vCode[i] = vCode[i] + rand() % 26;
	}

	dvoucher.initialDineVoucher(vCode, "John Smith", new Date(30, 6, 2021),
								25);
	dvoucher.printVoucher(cout);

	// Hint: For Tasks 4&5
	cout << "\nTest class ProcessVouchers class ..." << endl;
	ProcessVouchers process;
	process.inputVouchers();
	process.printVouchers();

	return 0;
}

cout << "\nVoucher registration list: " << endl;
        while (!fin.eof()) {
            fin >> voucherType;
            if (voucherType == "Active") {
                fin >> voucherNumber;
                fin >> day >> c >> month >> c >> year;
                getline(fin, name, '\r'); //change to '\n' if '\r' does not work for your OS
                cout << "Active " << voucherNumber << " " << day << " " << month
                        << " " << year << name << endl;
                active.push_back(ActiveVoucher(voucherNumber, name, new Date(day, month, year)));
            } else {
                fin >> voucherCode;
                fin >> day >> c >> month >> c >> year;
                getline(fin, name, '\r'); //change to '\n' if '\r' does not work for your OS

                cout << "Dine " << voucherCode << " " << day << " " << month
                        << " " << year << name << endl;
                dine.push_back(DineVoucher(voucherCode, name, new Date(day, month, year)));
            }
        }
