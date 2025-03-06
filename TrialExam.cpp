#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#include "Date.h"

class Account
{
protected:
    double balance;      // initial balance
    double interestRate; // yearly interest
    int term;            // months until maturity
    Date dateofOpen;     // date when the account is opened
    

public:
    Account() {}
    ~Account() {}

    virtual void printAccountInformation() = 0;

    void outputData()
    {
        Date tempDate = dateofOpen; // copy 

        ofstream fout;
        fout.open("loanSummary.txt");

        if (fout.fail())
        {
            cout << "Output file opening failed.\n";
            exit(1);
        }

        for (int i = 0; i < term; i++)
        {
            // increase only by a month per loop, but get the new balance
            fout << tempDate.dateAfterMonths(1) << "     " << getCurrentBalance(i) << endl;
        }

        fout.close();
    }

    void getData()
    {
        cout << "Enter initial balance: $";
        cin >> balance;
        cout << "Enter yearly interest rate: ";
        cin >> interestRate;
        cout << "Enter the number of months until maturity: ";
        cin >> term;
        cout << "Enter the date of opening (day, month and year):\n";
        int day, month, year;
        cin >> day >> month >> year;
        dateofOpen.setDate(day, month, year);
    }

    double getCurrentBalance(int numberofmonths)
    {
        double rateFraction = interestRate / (12 * 100.0);
        return balance * pow(1 + rateFraction, numberofmonths);
    }

    double getMonthlyPayment()
    {
        double rateFraction = interestRate / (12 * 100.0);
        double payment = rateFraction * pow((1 + rateFraction), term) / (pow((1 + rateFraction), term) - 1) * balance;

        return payment;
    }
};

class CreditAccount : public Account
{

public:
    CreditAccount() {}
    ~CreditAccount() {}

    void printAccountInformation()
    {

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "Date of opening" << setw(20) << "Open Balance " << setw(20) << "Interest Rate "
             << setw(20) << "Term of Credit " << setw(25) << "Balance at Maturity " << setw(20) << "Date at Maturity " << endl;
        cout << dateofOpen << setw(20) << setfill(' ') << balance << setw(20) << interestRate
             << setw(20) << term
             << setw(20) << getCurrentBalance(term)
             << setw(15) << "" << dateofOpen.dateAfterMonths(term) << endl;
    }
};

class LoanAccount : public Account
{

public:
    LoanAccount() {}
    ~LoanAccount() {}

    void printAccountInformation()
    {
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << setfill(' ') << "Date of opening" << setw(20) << "Open Balance" << setw(20) << "Interest Rate"
             << setw(20) << "Length of loan" << setw(20) << "Monthly payment" << endl;
        cout << setw(20) << dateofOpen << setw(20) << setfill(' ')
             << balance << setw(20) << interestRate
             << setw(20) << term << setw(20)
             << getMonthlyPayment() << endl;
    }
};

int main()
{

    CreditAccount cAccount;
    cout << "Enter account data on the day account was opened:\n";
    cAccount.getData();
    cAccount.outputData();
    cAccount.printAccountInformation();

    LoanAccount lAccount;
    cout << "Enter account data on the day account was opened:\n";
    lAccount.getData();
    lAccount.printAccountInformation();

    // Account *account[2] = {new CreditAccount, new LoanAccount};

    // account[0]->getData();
    // account[0]->outputData();
    // account[0]->printAccountInformation();

    // account[1]->getData();
    // account[1]->printAccountInformation();

    return 0;
}