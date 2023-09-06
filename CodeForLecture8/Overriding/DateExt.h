/*
 * DateExt.h
 *
 *  Created on: 6 Sep. 2020
 *      Author: dongmo
 */

#ifndef DATEEXT_H_
#define DATEEXT_H_

class DateExt: public Date {
public:
	DateExt(int d, int m, int y) :
			Date(d, m, y) {
	}

	void display() {
		cout << "The date is ";
		cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/'
				<< setw(2) << year % 100 << endl;
	}
};

#endif /* DATEEXT_H_ */
