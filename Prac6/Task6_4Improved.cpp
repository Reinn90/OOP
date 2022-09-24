// Program to demonstrate the CDAccount structure type.
#include <iostream>
#include <cmath>

using namespace std;

class Account
{
    double initialBalance;
    double interestRate;
    int term; // months until maturity

public:
    Account(){}
    ~Account() {}

    virtual void printResults() = 0; // pure virtual function

    void inputData()
    {
        cout << "\nEnter the amount of initial balance: $";
        cin >> initialBalance;
        cout << "Enter interest rate percent per annual: ";
        cin >> interestRate;
        cout << "Enter the number of months: ";
        cin >> term;
    }

    double getBalanceAtMaturity()
    {
        double rateFraction, interest;
        rateFraction = interestRate / 100.0;
        interest = initialBalance * (rateFraction * (term / 12.0)); // simple interest
        double balanceAtMaturity = initialBalance + interest;
        return balanceAtMaturity;
    }

    double getMonthlyPayment()
    {
        double rateFraction = interestRate / (12.0 * 100.0);
        double payment = initialBalance * (rateFraction + rateFraction / (pow(1 + rateFraction, term) - 1.0)); // simple interest
        return payment;
    }

    int getTerm() { return term; }
};

struct DepositAccount : public Account
{
    DepositAccount() {}
    ~DepositAccount() {}

    void printResults() // overrider
    {
        // test deposit account
        cout << "Test deposit account --- " << endl;

        cout.setf(ios::fixed);
        // cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The balance of deposit at maturity is $"
             << getBalanceAtMaturity() << " after " << getTerm() << " months." << endl;
    }
};

struct LoanAccount : public Account
{
    LoanAccount() {}
    ~LoanAccount() {}

    void printResults() //overrider
    {
        // test loan account
        cout << "\nTest loan account --- " << endl;

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << "The monthly payment of the loan is $"
             << getMonthlyPayment() << " for " << getTerm() << " months." << endl;
    }
};

int main()
{
    Account *d = new DepositAccount;
    Account *l = new LoanAccount;

    d->inputData();
    d->printResults();

    l->inputData();
    l->printResults();

    delete d, l;

    return 0;
}