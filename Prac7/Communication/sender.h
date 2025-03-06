#ifndef JONE_H_
#define JONE_H_

#include <vector>
#include <iostream>

#include "../Task7_1/Date.h"

class Sender
{
	string message;
	vector<Date> dates;

public:
	void setMessage();
	
	vector<Date> getDates() { return dates;}
};

void Sender::setMessage()
{

	// Generate 100 dates

	int dateCount = 100; // number of generated dates
	

	// loop to generate 100 random dates
	for (int i = 0; i < dateCount; i++)
	{

		// initialise constructor to start from 1/1/2000
		Date date(1, 1, 2000);

		int randDate = rand() % 1000; // randomize day in range 0-999

		for (int j = 0; j < randDate; j++)
		{
			date++; //  increment random amount of days to starting date
		}

		// add new 'date' to the vector
		dates.push_back(date);
	}


}
#endif /* JONE_H_ */
