/*
 * ClientRequest.h
 *
 *      Author: dongmo
 */

#ifndef CLIENTREQUEST_H_
#define CLIENTREQUEST_H_

class CustomerRequirement
{
public:
	int cId;
	string hotelType;
	bool games[NUMBEROFGAMES];
	int budget;

	// default constructor
	CustomerRequirement()
	{
		cId = -1;
		hotelType = "";
		budget = -1;
		for (int i = 0; i < NUMBEROFGAMES; i++)
			games[i] = false;
	}

	// Main constructor using data from txtfile.
	CustomerRequirement(int c, int b, string ht, bool g[])
	{
		cId = c;
		budget = b;
		hotelType = ht;

		for (int i = 0; i < NUMBEROFGAMES; i++)
			games[i] = g[i];
	}

	int earliestGameDay()
	{
		int flyin = 9;
		for (int i = 0; i < NUMBEROFGAMES; i++)
		{
			if (games[i] && gameDayMap[i] < flyin)
				flyin = gameDayMap[i];
		}
		return flyin;
	}

	int latestGameDay()
	{
		int flyout = 0;
		for (int i = 0; i < NUMBEROFGAMES; i++)
		{
			if (games[i] && gameDayMap[i] > flyout)
				flyout = gameDayMap[i];
		}
		return flyout;
	}

	void print()
	{
		cout << "Customer " << cId << ":" << setw(8) << budget << setw(8) << hotelType;

		for (int i = 0; i < NUMBEROFGAMES; i++)
		{
			if (games[i])
				cout << setw(8) << i;
		}
		cout << endl;
	}
};

#endif /* CLIENTREQUEST_H_ */
