#ifndef KATE_H_
#define KATE_H_

class Receiver
{
	string message;
	vector<Date> dates;

public:
	void receiveMessage(vector<Date> d) { dates = d; }
	void printMessage()
	{
		// for each dates in the vector
		for (Date i : dates)
		{
			// print output
			cout << i << endl;
		}

		cout << "End of vector." << endl;
	}
};
#endif /* KATE_H_ */
