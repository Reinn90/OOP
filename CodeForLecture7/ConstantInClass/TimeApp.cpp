#include "Time.h"
int main() {
	Time wakeUp(6,45,0 ); // non-constant object
	const Time noon(12,0,0 ); // constant object

   // OBJECT      MEMBER FUNCTION
   wakeUp.setHour( 19 );  // non-const   non-const
   wakeUp.setHour( 12 );    // const       non-const
   wakeUp.getHour();      // non-const   const
   noon.getMinute();      // const       const
   wakeUp.printStandard();// non-const   non-const 
   noon.printStandard();  // const       non-const
   return 0;
} // end main
