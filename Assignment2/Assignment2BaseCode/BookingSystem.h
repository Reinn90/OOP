#ifndef BOOKINGSYSTEM_H_
#define BOOKINGSYSTEM_H_

class BookingSystem
{
protected:
    vector<CustomerRequirement> cxReqList;
    vector<Package> package;

    int flightTickets[2][NUMBEROFDAYS];
    int hotelVacancy[3][NUMBEROFDAYS - 1]; // 1 less day since no hotel booking final day
    int gameTickets[NUMBEROFGAMES];

    bool games[NUMBEROFGAMES];

public:
    BookingSystem()
    {
        // keep track of flight tickets
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < NUMBEROFDAYS; j++)
            {
                flightTickets[i][j] = 0;
            }
        }

        // keep track of hotel room bookings
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < NUMBEROFDAYS - 1; j++)
            {
                hotelVacancy[i][j] = 0;
            }
        }

        // keep track of game events

        for (int i = 0; i < NUMBEROFGAMES; i++)
        {
            gameTickets[i] = 0;
        }
    }

    void flightTicketSummary()
    {
        cout << "Total fly-in tickets (to New York) for each day booked: " << endl;
        for (int i = 0; i < NUMBEROFDAYS; i++)
        {
            cout << flightTickets[0][i] << setw(5);
        }
        cout << endl;
        cout << "Total fly-out tickets (to Sydney) for each day booked: " << endl;
        for (int i = 0; i < NUMBEROFDAYS; i++)
        {
            cout << flightTickets[1][i] << setw(5);
        }
        cout << endl
             << endl;
    }

    void hotelVoucherSummary()
    {
        cout << "Total hotel vouchers sold: \n";
        cout << "Regular Hotel Rooms\n";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << hotelVacancy[0][i] << setw(4);
        }
        cout << endl;

        cout << "Bronze Hotel Rooms\n";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << hotelVacancy[1][i] << setw(4);
        }
        cout << endl;

        cout << "Gold Hotel Rooms\n";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << hotelVacancy[2][i] << setw(4);
        }
        cout << endl
             << endl;
    }

    void gameTicketSummary()
    {
        cout << "Total event tickets for each day booked: " << endl;
        for (int i = 0; i < NUMBEROFGAMES; i++)
        {
            cout << gameTickets[i] << setw(4);
        }
        cout << endl
             << endl;
    }

    void readCustomerRequirements();
    void generatePackages();
    void printSuccessfulPackages();
};

void BookingSystem::readCustomerRequirements()
{

    ifstream fin;

    // Initialise variables to store data
    char delim; // deliminator
    int budget, gameNo, clientId = 0;
    string hotelType;

    fin.open("requirementList.txt"); // open file

    // show error if there's wrong with file opening
    if (fin.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    // Go through the file and store the data sequentially into variables
    while (!fin.eof())
    {
        // reset game list boolean array
        for (int i = 0; i < NUMBEROFGAMES; i++)
            games[i] = false;

        // store Budget and hotel type data while ignoring the comma and opening bracket
        fin >> budget >> delim >> hotelType >> delim;

        // loop to go through gameNo requirement until closing square bracket
        do
        {

            fin >> gameNo;        // store game number
            games[gameNo] = true; // switch index to true
            fin >> delim;         // get the next character deliminator while...

        } while (delim != ']'); // that deliminator is still just a comma

        cxReqList.push_back(CustomerRequirement(clientId, budget, hotelType, games));
        ++clientId; // pre-fix increment
    }

    fin.close(); // close file
}

void BookingSystem::generatePackages()
{

    // Construct the package class for each cxReqList
    for (int i = 0; i < cxReqList.size() - 1; i++)
    {
        package.push_back(Package(cxReqList[i].cId, cxReqList[i].budget, cxReqList[i].hotelType, cxReqList[i].games));
    }

    // // Generate...
    for (int i = 0; i < package.size(); i++)
    {

        /*
         * FLIGHT TICKETS
         */
        // get earliest/latest flight day
        int flyIn = cxReqList[i].earliestGameDay();
        int flyOut = cxReqList[i].latestGameDay();

        // make sure fly out is later than fly-in day
        if (flyIn == flyOut)
        {
            if (flyIn - 1 >= 0)
            {
                flyIn--;
            }
            else
                flyOut++;
        }

        // ... flight packages
        package[i].addFlightTicket(0, flyIn);
        package[i].addFlightTicket(1, flyOut);

        /*
         * HOTEL VOUCHERS
         */

        double discount = 0.0;
        // generate hotel vouchers within the fly-in/out days
        for (int j = flyIn; j < flyOut; j++)
        {
            // Tally hotel bookings per day
            if (cxReqList[i].hotelType == hotelIndexToTypeMap[0] && hotelVacancy[0][j] < hotelQuota[0]) // Regular
            {
                hotelVacancy[0][j]++; // add to regular room tally
            }
            else if (cxReqList[i].hotelType == hotelIndexToTypeMap[1] && hotelVacancy[1][j] < hotelQuota[1]) // Bronze
            {
                // if vacancy on that day is > 50% -  the first 10 people gets a discount
                if (hotelVacancy[1][j] <= hotelQuota[1] * 0.5)
                {
                    discount = 0.2;
                }

                hotelVacancy[1][j]++; // add to bronze room tally
            }
            else if (cxReqList[i].hotelType == hotelIndexToTypeMap[2] && hotelVacancy[2][j] < hotelQuota[2]) // Gold
            {
                // if vacancy on that day is > 50% -  the first 20 people gets a discount
                if (hotelQuota[2] - hotelVacancy[2][j] > hotelQuota[2] * 0.5)
                {
                    discount = 0.4;
                }
                else if (hotelQuota[2] - hotelVacancy[2][j] > hotelQuota[2] * 0.2)
                {
                    discount = 0.2;
                }

                hotelVacancy[2][j]++; // add to gold room
            }

            package[i].addHotelVoucher(cxReqList[i].hotelType, j, discount); // change discount
        }

        /*
         * GAME DAY TICKETS
         */

        // generate game ticket vouchers for each game the customer wants to watch
        for (int j = 0; j < NUMBEROFGAMES; j++)
        {
            if (cxReqList[i].games[j] == true)
            {
                package[i].addGameTicket(j);
            }
        }
    }
}

void BookingSystem::printSuccessfulPackages()
{

    int packageCounter = 0;
    double totalProfit = 0;

    cout << "\nGenerating valid packages.. " << endl;

    for (int i = 0; i < package.size(); i++)
    {
        // Print successful packages
        if (package[i].validatePackage())
        {

            int flyIn = cxReqList[i].earliestGameDay();
            int flyOut = cxReqList[i].latestGameDay();

            // fix issue of sameday flyIn-flyOut
            if (flyIn == flyOut)
            {
                if (flyIn - 1 >= 0)
                {
                    flyIn--;
                }
                else
                    flyOut++;
            }

            flightTickets[0][flyIn]++; // fly in row
            flightTickets[1][flyOut]++; // fly out row

            // tally game tickets
            for (int k = 0; k < NUMBEROFGAMES; k++)
            {
                if (cxReqList[i].games[k] == true && gameTickets[k] < gameQuota[k])
                {
                    gameTickets[k]++;
                }
            }

            package[i].printPackage();
            cout << "Package is valid.\n"
                 << endl;

            packageCounter++;                      // how many successful package
            totalProfit += package[i].getProfit(); // total profit
        }
        else // print a brief report on unsuccesful packages
        {

            cout << "Customer " << cxReqList[i].cId
                 << " package invalid. "
                 << "Customer budget : $" << cxReqList[i].budget
                 << " Package cost: $" << package[i].getTotalCost() << endl
                 << endl;
        }
    }

    // Summary
    cout << "******** Summary of Packages ********" << endl
         << endl;
    cout << "Number of valid packages:  " << packageCounter << endl
         << endl;

    flightTicketSummary();
    hotelVoucherSummary();
    gameTicketSummary();

    cout << "Total Profit: $" << totalProfit << endl;
}
#endif