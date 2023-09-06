#include <iostream>
#include<string>
using namespace std;

class Invoice {
private:
	string partNumber;
	string partDescription;
	int quantity;
	int price;
public:
    Invoice();
    void setPartNumber(string); //mutator
	void setPartDescription(string); //mutator
	void setQuantity(int);//mutator
	void setPrice(int);//mutator
    string getPartNumber();//accessor
	string getPartDescription();//accessor
	int getQuantity();//accessor
	int getPrice();//accessor
	int getInvoiceAmount();//accessor
};

Invoice::Invoice() {
	partNumber = "";
	partDescription = "";
	quantity = 0;
	price = 0;
}

void Invoice::setPartNumber(string pn) {
	partNumber = pn;
}

void Invoice::setPartDescription(string pd) {
	partDescription = pd;
}

void Invoice::setQuantity(int q) {
	if (q < 0 ) q = 0;

	quantity = q;
}

void Invoice::setPrice(int p) {
	price= p;
}

string Invoice::getPartNumber() {
	return partNumber;
}

string Invoice::getPartDescription() {
	return partDescription;
}

int Invoice::getQuantity() {
	return quantity;
}

int Invoice::getPrice() {
	return price;
}

int Invoice::getInvoiceAmount() {
	return quantity*price;
}

int main() {
   Invoice invoice;

   invoice.setPartNumber("AN-930");
   invoice.setPartDescription("Ford Head Light");
   invoice.setQuantity(10);
   invoice.setPrice(150);
   cout << "Part Number: " << invoice.getPartNumber() << endl;
   cout << "Part Decription: " << invoice.getPartDescription() << endl;
   cout << "Quantity: " << invoice.getQuantity() << endl;
   cout << "Price: " << invoice.getPrice() << endl;
   cout << "Invoice Price: "<< invoice.getInvoiceAmount() << endl;
   return 0;
}
