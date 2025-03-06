//Created by Dongmo
#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>

#include "Date.h"

using namespace std;

int main() {
	srand(time(0));

	vector<Date> dates;

	Date d1(1,1,2021);

	for (int i = 1; i <= 10; i++) {
        int offset = rand()%365;

		Date d = d1 + offset;

		dates.push_back(d);
	}

	cout<<"Ten randomly generated dates in 2021:" << endl;
	for (int i = 0; i < dates.size(); i++) {
		cout << dates[i] << endl;
	}

	cout << endl;

    sort(dates.begin(), dates.end());

    cout<<"The sorted dates:" << endl;
	for (int i = 0; i < dates.size(); i++) {
		cout << dates[i] << endl;
	}

	return 0;
}
