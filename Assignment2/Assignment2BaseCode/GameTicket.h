#ifndef GAMETICKET_H_
#define GAMETICKET_H_

class GameTicket : public Ticket
{

private:
public:
    GameTicket(int gameNo, int fullprice) : Ticket(gameNo, fullprice){};

    void printTicket()
    {
        // day is the gameNo required, which is the index of the constant arrays
        cout << "Event ticket for " << nameMap[day] << " on day " << gameDayMap[day] << " at price $" << getTicketPrice() << endl;
    }
};

#endif