#include<set>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

int main() {
	srand((unsigned) time(NULL));
	set<int> lotto;

	cout << "\nGenerate lotto numbers:" << endl;

	while(lotto.size() < 7) {
		int  num = rand()%45 + 1;
		lotto.insert(num);
		cout << num << " ";
	}

	cout << "\nThese are your lotto numbers:" << endl;

	set<int>::iterator pos;
	for(pos = lotto.begin();pos != lotto.end(); pos++)
		cout << *pos << " ";

//	for(int x: lotto)
//		cout << x << " ";
//	cout << endl << endl;


	return 0;
}

