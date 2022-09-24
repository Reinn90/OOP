#include <iostream>
#include <fstream>

using namespace std;

class Reader
{

public:
    void readAndWrite()
    {
        ifstream fileIn;  // create fIn object
        ofstream fileOut; // create fOut object

        fileIn.open("mathsheet.txt"); // open file

        // show error if there's wrong with file opening
        if (fileIn.fail())
        {
            cout << "Input file opening failed.\n";
            exit(1);
        }

        fileOut.open("mathsheetOutput.txt");
        if (fileOut.fail())
        {
            cout << "Output file opening failed.\n";
            exit(1);
        }

        // initialise variables
        double x, y, product = 0;
        char delim;

        // loop to read through the data until end of file
        while (!fileIn.eof())
        {
            // read in first int as x, then the character "x", then int y, then character delimiter
            fileIn >> x >> delim >> y >> delim;
            // multiply the integers
            product = x * y;

            // output the result in the new file
            fileOut << x << " x " << y << " = " << product << endl;
        }

        // close file
        fileIn.close();
        fileOut.close();
    }
};

int main()
{

    Reader r;
    r.readAndWrite();
    return 0;
}