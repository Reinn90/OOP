#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void addPlusPlus(ifstream &inStream, ofstream &outStream);

int main()
{
    ifstream fin;
    ofstream fout;

    cout << "Begin editing files.\n";

    fin.open("mathsheet.txt");
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    fout.open("mathsheet_answer.txt");
    if (fout.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    addPlusPlus(fin, fout);

    fin.close();
    fout.close();

    cout << "End of editing files.\n";
    return 0;
}

void addPlusPlus(ifstream &inStream, ofstream &outStream)
{
    int number1, number2;
    string next;

    while (!inStream.eof())
    {
        inStream >> number1;              // read 7
        outStream << number1 << " ";      // print "7 "
        inStream >> next;                 // read "x"
        outStream << next << " ";         // print "x "
        inStream >> number2;              // read 3
        outStream << number2 << " ";      //print "3 "
        inStream >> next;
        outStream << next << " ";
        if (next == "=")
            outStream << number1 * number2 << endl;
    }
}