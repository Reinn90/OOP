#ifndef SMARTBOOKINGSYSTEM_H_
#define SMARTBOOKINGSYSTEM_H_

class SmartBookingSystem : public BookingSystem
{
    vector<Package> smartPackage; // copy package
public:
    void generatePackages();

    void vacancy()
    {

        cout << "\nRoom Vacancy: \n";
        cout << "Regular hotel rooms: ";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << setw(4) << hotelQuota[0] - hotelVacancy[0][i];
        }
        cout << "\nBronze hotel rooms:  ";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << setw(4) << hotelQuota[1] - hotelVacancy[1][i];
        }
        cout << "\nGold hotel rooms:    ";
        for (int i = 0; i < NUMBEROFDAYS - 1; i++)
        {
            cout << setw(4) << hotelQuota[2] - hotelVacancy[2][i];
        }

        cout << endl
             << "\nUnsold game tickets:\n";
        for (int i = 0; i < NUMBEROFGAMES; i++)
        {
            cout << gameQuota[i] - gameTickets[i] << setw(4);
        }

        cout << endl;
    }
};

void SmartBookingSystem::generatePackages()
{

    double flightCost, hotelCost, gamesCost, totalProfit;

    // create a normal package and a copy to compare it to
    for (int i = 0; i < cxReqList.size() - 1; i++)
    {
        package.push_back(Package(cxReqList[i].cId, cxReqList[i].budget, cxReqList[i].hotelType, cxReqList[i].games));
        smartPackage.push_back(Package(cxReqList[i].cId, cxReqList[i].budget, cxReqList[i].hotelType, cxReqList[i].games));
    }

    // add the vouchers to get the cost
    for (int i = 0; i < package.size(); i++)
    {

        int flyIn = cxReqList[i].earliestGameDay();
        int flyOut = cxReqList[i].latestGameDay();

        // make sure flights are not on the same day
        if (flyIn == flyOut)
        {
            if (flyIn - 1 >= 0)
            {
                flyIn--;
            }
            else
                flyOut++;
        }

        // add flight packages
        package[i].addFlightTicket(0, flyIn);
        package[i].addFlightTicket(1, flyOut);

        // get the cost
        flightCost = package[i].getFlightCost();

        // add hotel vouchers

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

        // get the Hotel Cost
        hotelCost = package[i].getHotelCost();

        /*
         * Game vouchers - games are only added if can be afforded by the
         * customer, else, they will see no games
         */

        for (int j = 0; j < NUMBEROFGAMES; j++)
        {
            // find the first game that's required
            if (cxReqList[i].games[j] == true)
            {
                // add it to the smart package
                smartPackage[i].addGameTicket(j);
                // get the cost
                gamesCost += smartPackage[i].getGamesCost();

                // if the cost is able to fit within the budget, add the game ticket
                if (cxReqList[i].budget - (flightCost + hotelCost) > gamesCost)
                {
                    package[i].addGameTicket(j);
                }
            }
        }

        // reset the totals
        flightCost = 0;
        hotelCost = 0;
        gamesCost = 0;
    }
}

#endif