#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class LinkedList{
private:
    Node *head;
public:
    // constructor
    LinkedList(){
        head = NULL; // set head to NULL
    }

    void addValue(int val){
        Node *n = new Node();   // create new Node
        n->data = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }

    int popValue(){
        Node *n = head;
        int ret = n->data;

        head = head->next;
        delete n;
        return ret;
    }
};

int main() {
    LinkedList list;

    list.addValue(5);
    list.addValue(10);
    list.addValue(20);

    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    cout << list.popValue() << endl;
    return 0;
}
