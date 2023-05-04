#include <iostream>
#include<cmath>
#include <iomanip>

using namespace std;

#include"Date.h"

struct CreditAccount {
	double balance;//initial balance
	double interestRate;//yearly interest
	int term; //months until maturity
	Date dateofOpen; //date when the account is opened
};

struct LoanAccount {
	double balance;//initial balance
	double interestRate;//yearly interest
	int term; //number of months
	Date dateofOpen; //date when the account is opened
};

void getData(CreditAccount& theAccount) {
	cout << "Enter initial balance: $";
	cin >> theAccount.balance;
	cout << "Enter yearly interest rate: ";
	cin >> theAccount.interestRate;
	cout << "Enter the number of months until maturity: ";
	cin >> theAccount.term;
	cout << "Enter the date of opening (day, month and year):\n";
	int day, month, year;
	cin >> day >> month >> year;
	theAccount.dateofOpen.setDate(day, month, year);
}

void getData(LoanAccount& theAccount) {
	cout << "Enter the loan amount: $";
	cin >> theAccount.balance;
	cout << "Enter yearly interest rate: ";
	cin >> theAccount.interestRate;
	cout << "Enter the number of payments (monthly pay): ";
	cin >> theAccount.term;
	cout << "Enter the date of opening (day, month and year):\n";
	int day, month, year;
	cin >> day >> month >> year;
	theAccount.dateofOpen.setDate(day, month, year);
}

double getCurrentBalance(CreditAccount theAccount, int numberofmonths) {
	double rateFraction = theAccount.interestRate / (12 * 100.0);
	return theAccount.balance * pow(1 + rateFraction, numberofmonths);
}

double getMonthlyPayment(LoanAccount theAccount) {
	double rateFraction = theAccount.interestRate / (12 * 100.0);
	double payment = rateFraction * pow((1 + rateFraction), theAccount.term)
			/ (pow((1 + rateFraction), theAccount.term) - 1)
			* theAccount.balance;

	return payment;
}

void printAccountInformation(CreditAccount theAccount) {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Date of opening" << setw(20) << "Open Balance " << setw(20)<< "Interest Rate "
			<< setw(20)<< "Term of Credit " << setw(20)<< "Balance at Mature " << endl;
	cout  <<theAccount.dateofOpen <<setw(20) << setfill(' ') <<  theAccount.balance <<setw(20) <<  theAccount.interestRate
			<< setw(20) << theAccount.term
			<< setw(20) << getCurrentBalance(theAccount, theAccount.term) << endl;
}

void printAccountInformation(LoanAccount theAccount) {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Date of opening" << setw(20)<< "Open Balance" << setw(20)<< "Interest Rate"
			<< setw(20)<< "Length of loan" << setw(20)<< "Monthly payment" << endl;
	cout << setw(20) << theAccount.dateofOpen << setw(20) << setfill(' ')
			<< theAccount.balance << setw(20) << theAccount.interestRate
			<< setw(20) << theAccount.term << setw(20)
			<< getMonthlyPayment(theAccount) << endl;
}

int main() {
	CreditAccount cAccount;
	cout << "Enter account data on the day account was opened:\n";
	getData(cAccount);
	printAccountInformation(cAccount);

	LoanAccount lAccount;
	cout << "Enter account data on the day account was opened:\n";
	getData(lAccount);
	printAccountInformation(lAccount);
	return 0;
}