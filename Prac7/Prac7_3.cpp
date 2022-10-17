#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm> // sort & reverse functions

#include "Task7_1/Date.h"

using namespace std;

int main()
{

    srand(time(0));
    int dateCount = 100; // number of generated dates
    // create vector of type Date class
    vector<Date> dates;

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

    // sort the generated dates - Ascending
    sort (dates.begin(), dates.end());

    // descending
    // reverse (dates.begin(), dates.end());

    // write onto output file
    ofstream fout;

    fout.open("random_date_out_SORTED.txt");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    // for each dates in the vector
    for(Date i: dates){
        // output onto the file
        fout << i << endl;
    }

    cout << "End of vector. File Complete."<< endl;
   

    fout.close();



    return 0;
}