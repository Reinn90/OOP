#include<iostream>
#include<iomanip>
using namespace std;

class Time {
private:
   int hour; 
   int minute; 
   int second; 
public:
   Time( int = 0, int = 0, int = 0 ); 
   void setTime( int, int, int ); 
   void setHour( int h) {hour = h;} //mutator
   void setMinute( int m) {minute = m;} //mutator
   void setSecond( int s) {second = s;}  //mutator

   int getHour() const {return hour;} //accessor
   int getMinute() const {return minute;} //accessor
   int getSecond() const {return second;} //accessor

   void printStandard() const; // print standard time (should be const)
}; // end class Time

Time::Time( int hour, int minute, int second ) 
{ 
   setTime( hour, minute, second ); 
} // end Time constructor

void Time::setTime( int hour, int minute, int second )
{
   setHour( hour );
   setMinute( minute );
   setSecond( second );
} // end function setTime

void Time::printStandard() const
{
   cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
      << ":" << setfill( '0' ) << setw( 2 ) << minute
      << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" ) << endl;
}