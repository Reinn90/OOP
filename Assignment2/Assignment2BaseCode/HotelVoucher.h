#ifndef HOTELVOUCHER_H_
#define HOTELVOUCHER_H_

class HotelVoucher : public Ticket
{
private:
    int hotelType;

public:
    HotelVoucher(string ht, int d, double dc) : Ticket(d, dc)
    {
        
        // Loop to find the hotel price from the hotel type string
        for (int i  = 0; i< hotelIndexToTypeMap->size(); i++ ){
            if (hotelIndexToTypeMap[i] == ht)
            hotelType = i;
        }

        // update full price
        fullPrice = hotelPriceMap[hotelType];

        discount = dc;


    }


    int getVoucherPrice(){return fullPrice;};


    void printTicket()
    {
        cout << "Hotel room voucher for a " << hotelIndexToTypeMap[hotelType] 
        << " room on day " << day << " at price $" << getTicketPrice() << endl;
    }
};

#endif