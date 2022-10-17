#ifndef PACKAGE_H_
#define PACKAGE_H_

class Package
{
protected:

    // classes as vector
    vector<FlightTicket> flights;
    vector<HotelVoucher> hvoucher;
    vector<GameTicket> gameticket;

    // info from customer requirement list
    int clientId;
    int budget;
    string hotelType;
    bool games[NUMBEROFGAMES];

public:
    // cost and profit
    double profit;
    double totalCost;

    double flightCost;
    double hotelCost;
    double gameCost;


    // default constructor for test
    Package()
    {
        clientId = -1;
        budget = -1;
    }

    // Main constructor
    Package(int cId, int b, string ht, bool g[])
    {
        clientId = cId;
        budget = b;
        hotelType = ht;
        for (int i = 0; i < NUMBEROFGAMES; i++)
            games[i] = g[i];
    }

    // destructor
    ~Package(){};

    // Create the packages by constructing the relevant classes
    void addFlightTicket(int flightType, int day);
    void addHotelVoucher(string hotelType, int day, double discount);
    void addGameTicket(int gameDay);

    // Get costs
    double getFlightCost();
    double getHotelCost();
    double getGamesCost();

    // get the total cost of all three
    double getTotalCost();

    double getProfit(); // individual package profit

    bool validatePackage(); // check whether a package is successful
    void printPackage();
};

void Package::addFlightTicket(int ft, int d)
{
    flights.push_back(FlightTicket(ft, d));
}

void Package::addHotelVoucher(string ht, int d, double dc)
{
    hvoucher.push_back(HotelVoucher(ht, d, dc));
}

void Package::addGameTicket(int gameDay)
{
    gameticket.push_back(GameTicket(gameDay, gamePriceMap[gameDay]));
}

double Package::getFlightCost()
{
    flightCost = 0.0; // reset flight cost for every customer req
    // flights[0] = arrival, flights[1] = departure
    flightCost = flights[0].getTicketPrice() + flights[1].getTicketPrice();

    return flightCost;
}

double Package::getHotelCost()
{
    hotelCost = 0.0;
    // loop through how many days a customer is staying and add the hotel prices
    for (int i = 0; i < hvoucher.size(); i++)
    {
        hotelCost += hvoucher[i].getTicketPrice();
    }
    return hotelCost;
}

double Package::getGamesCost()
{
    gameCost = 0.0;
    // similar to hotel, add all the game costs
    for (int i = 0; i < gameticket.size(); i++)
    {
        gameCost += gameticket[i].getTicketPrice();
    }
    return gameCost;
}

double Package::getTotalCost()
{
    totalCost = 0.0;
    totalCost = getFlightCost() + getHotelCost() + getGamesCost();

    return totalCost;
}

double Package::getProfit()
{
    double comms = 0.05;     // air and hotel cost commision
    double gameComms = 0.15; // game ticket cost commission

    profit = 0.0;
    profit = ((getFlightCost() + getHotelCost()) * comms) + (getGamesCost() * gameComms);
    return profit;
}

bool Package::validatePackage()
{
    // if total cost of package is greater than budget, return false
    if (budget >= getTotalCost())
        return true;

    return false;
}

void Package::printPackage()
{
    cout << "Customer number: " << clientId << endl;
    for (int i = 0; i < flights.size(); i++)
        flights[i].printTicket();
    // cout << " Flight cost: $ " << getFlightCost() << "\n"
    //      << endl;

    for (int i = 0; i < hvoucher.size(); i++)
        hvoucher[i].printTicket();
    // cout << " Hotel cost: $ " << getHotelCost() << "\n"
    //      << endl;

    for (int i = 0; i < gameticket.size(); i++)
        gameticket[i].printTicket();
    // cout << " Game Ticket cost: $ " << getGamesCost() << "\n"
    //      << endl;

    cout << "Customer budget: $" << budget << endl;
    cout << "Total Package cost: $" << getTotalCost() << endl;
    cout << "Package profit: $" << getProfit() << endl;
}

#endif