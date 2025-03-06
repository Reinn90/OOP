#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

#include "Date.h"

class Ticket
{
	// Hint: Add your code as part of the solution to Task 2

protected:
	long ticketNumber;
	string ticketCode;
	string customerName;
	Date *boardingDate;
	float price;

public:
	Ticket() {}
	~Ticket() {}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void initialTrainTicket(string tc, string n, Date *d,
							float p)
	{
		ticketCode = tc;
		customerName = n;
		boardingDate = d;
		price = p;
	}

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void initialFlightTicket(long tn, string n, Date *d,
							 float p)
	{
		ticketNumber = tn;
		customerName = n;
		boardingDate = d;
		price = p;
	}

	virtual void printTicket(ostream &sout) = 0;
};

// Hint: Rebuild the class for Tasks 2&3 and better OOP style
class TrainTicket : public Ticket
{
public:
	TrainTicket() {}
	~TrainTicket() {}

	TrainTicket(string tc, string n, Date *d, float v)
	{
		ticketCode = tc;
		customerName = n;
		boardingDate = d;
		price = v;
	}

	string getTicketCode() { return ticketCode; }
	string getCustomerName() { return customerName; }
	Date getBoardingDate() { return *boardingDate; }
	float getPrice() { return price; }

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void printTicket(ostream &sout)
	{ // ostream is an object of output stream, such as cout
		sout << "\nTrian Ticket:" << endl;
		sout << "Ticket Code: " << setfill('0') << setw(8)
			 << ticketCode << endl;
		sout << "Customer Name: " << customerName << endl;
		sout << "Boarding Date: " << *boardingDate << "\tPrice: $"
			 << fixed << setprecision(2) << price << endl;
	}
};

// Hint: Rebuild the class for Tasks 2&3 and better OOP style
class FlightTicket : public Ticket
{
public:
	FlightTicket() {}
	~FlightTicket() {}

	FlightTicket(long tn, string n, Date *d,
				 float p)
	{
		ticketNumber = tn;
		customerName = n;
		boardingDate = d;
		price = p;
	}

	long getTicketNumber() { return ticketNumber; }
	string getCustomerName() { return customerName; }
	Date getBoardingDate() { return *boardingDate; }
	float getPrice() { return price; }

	// Hint: Rewrite/relocate the function for Tasks 2&3
	void printTicket(ostream &sout)
	{
		sout << "\nFlight Ticket:" << endl;
		sout << "Customer Name: " << customerName << endl;
		sout << "Ticket Number: " << ticketNumber << endl;
		sout << "Boarding Date: " << *boardingDate << "\tPrice: $"
			 << fixed << setprecision(2) << price << endl;
	}
};

// Hint: Rebuild the class for Tasks 4&5 and better OOP style
class ProcessTickets
{
private:
	vector<TrainTicket> tlist;
	vector<FlightTicket> flist;

public:
	void inputTickets()
	{

		ifstream fin;
		fin.open("ticketlist.txt"); // if you IDE cannot file the file, add the absolution path to the file name,
									//  say "/Users/dongmo/cloudstor/Teaching/OOP21/Lectures/DemoCode/exam/Voucher/voucherlist.txt"

		if (fin.fail())
		{
			cout << "Can't open input file!" << endl;
			return;
		}

		string ticketType;
		int ticketNumber;
		string ticketCode, customerName;
		int day, month, year;
		char c;

		cout << "\nTicket list: " << endl;
		while (!fin.eof())
		{
			fin >> ticketType;

			if (ticketType == "Train")
			{
				fin >> ticketCode;
				fin >> day >> c >> month >> c >> year;
				getline(fin, customerName, '\n'); // change to '\n' if '\r' does not work for your OS

				// Task 4.2 solution
				// random value between $50-$150 as float
				float value = 50 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (150 - 50)));

				cout << "Train " << ticketCode << " " << day << "/" << month
					 << "/" << year << customerName << endl;

				tlist.push_back(TrainTicket(ticketCode, customerName, new Date(day, month, year), value));
			}
			else
			{
				fin >> ticketNumber;
				fin >> day >> c >> month >> c >> year;
				getline(fin, customerName, '\n'); // change to '\n' if '\r' does not work for your OS

				// Task 4.2 solution
				// random value between $1000-$2000 as float
				float value = 1000 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (2000 - 1000)));

				cout << "Flight " << ticketNumber << " " << day << "/" << month
					 << "/" << year << customerName << endl;

				flist.push_back(FlightTicket(ticketNumber, customerName, new Date(day, month, year), value));
			}
		}

		fin.close();
	}

	void printTickets()
	{
		cout << "\nTicket printout:" << endl;
		// to be implemented for Task 5

		ofstream fout;

		fout.open("ticketoutput.txt");
		if (fout.fail())
		{
			cout << "Output file opening failed.\n";
			exit(1);
		}

		for (int i = 0; i < tlist.size(); i++)
		{
			fout << "Train Ticket:" << endl;
			fout << "Ticket Code:     " << tlist[i].getTicketCode() << endl;
			fout << "Customer Name:  " << tlist[i].getCustomerName() << endl;
			fout << "Date:  " << tlist[i].getBoardingDate() << "     Price:  $"
				 << fixed << setprecision(2) << tlist[i].getPrice() << endl;

			fout << endl;
		}

		for (int i = 0; i < flist.size(); i++)
		{
			fout << "Flight Ticket:" << endl;
			fout << "Ticket Number:  " << flist[i].getTicketNumber() << endl;
			fout << "Customer Name:  " << flist[i].getCustomerName() << endl;
			fout << "Date:  " << flist[i].getBoardingDate() << "     Price:  $"
				 << fixed << setprecision(2) << flist[i].getPrice() << endl;

			fout << endl;
		}

		fout.close();
	}
};

int main()
{
	srand(0);

	// Hint: Vary the following code to complete Task 1
	cout << "Test class TrainTicket class ..." << endl;

	TrainTicket tticket;
	string tCode = "AAAAAAAA";

	// Task 1 Solution
	for (int i = 0; i < 8; i++)
	{
		tCode[i] = tCode[i] + rand() % 26;
	}

	tticket.initialTrainTicket(tCode, "John Smith",
							   new Date(21, 10, 2021), 100.212);
	tticket.printTicket(cout);

	cout << endl;

	///////////////////////////////////////

	cout << "Test class FlightTicket class ..." << endl;
	FlightTicket fticket;

	// Task 1 Solution
	fticket.initialFlightTicket(20658133, "Kevin Reyes", new Date(30, 6, 2021),
								2500.3434);
	fticket.printTicket(cout);

	// Hint: For Tasks 4&5
	cout << "\nTest class ProcessTickets class ..." << endl;
	ProcessTickets process;
	process.inputTickets();
	process.printTickets();
	return 0;
}
