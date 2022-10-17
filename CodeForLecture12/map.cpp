
#include<string>
#include<iostream>
//#include<unordered_map>
#include<map>

using namespace std;

int main() {
	map<int, string> m;
	//unordered_map<int, string> m;

	m.insert(pair<int, string>(2227, "Bob"));
	m.insert(pair<int, string>(2223, "Sarah"));
	m.insert(pair<int, string>(2221, "Diana"));
	m.insert(pair<int, string>(2221, "Lisa"));

	m[2221] = "Lisa";
	cout << m[2221] << endl;


	cout << endl;

	cout << "This is the map: " << endl;
	map<int, string>::iterator pos;
	//unordered_map<int, string>::iterator pos;
	for (pos = m.begin(); pos != m.end(); pos++)
		cout << pos->first << "  " << pos->second << endl;
	cout << endl;

	//C++11
	for(pair<int, string> p: m)
		cout << p.first << " " << p.second << endl;

	pos = m.find(2223);

	if( pos != m.end() )
		cout << pos-> first << "  " << pos->second << endl;

	cout << m[2223] << endl;
	int key = 2223;

	cout << "There are " << m.count(key)
		 << " pairs with key " << key << endl;
	return 0;
}
