//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999
  
#include <iostream>                                 //Line 1
#include "LinkedListADT.h"                    //Line 2
 
using namespace std;                                //Line 3

struct Bid {
	int key;
	char type;
};

int main()                                          //Line 4
{                                                   //Line 5
    List<Bid, int> list;          //Line 6
    cout << "Enter 5 bids" << endl;                    //Line 8                                   //Line 9

   for(int i=0;i<5;i++) {
	   Bid b;
    	cin >> b.key;
    	cin >> b.type;
    	//Line 11
        list.addNode(b);
    }                                               //Line 14


    for(int i=0; i< list.listCount(); i++) {
    	Bid b;
    	list.getNext(i, b);
    	cout << b.key <<  " " << b.type << endl;
    }

    Bid *br = new Bid();
    list.removeNode(3, br);
    cout << "Bid (" << br->key << ", " << br->type << ") was deleted!" << endl;

    cout << "\nAfter deleting " << endl;

    for(int i=0; i< list.listCount(); i++) {
    	Bid b;
    	list.getNext(i, b);
    	cout << b.key <<  " " << b.type << endl;
    }


    return 0;                                       //Line 38
}                                                   //Line 39

