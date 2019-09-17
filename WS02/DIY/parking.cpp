/***********************************************************************
// OOP244 Workshop 2: SenePark application 
// File	parking.cpp
// Version 1.0
// Date	2019/09/15
// Author	Fardad Soleimanloo
// Description
// This is a parking application using the ParkingLot and
// ParkingSpot modules of DIY section of the workshop.
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
using namespace std;
#include "ParkingLot.h"
#include "utils.h"
using namespace sdds;
int menu();
int main(void) {
   ParkingLot SenePark;
   int noOfSpots=0;
   int spotNumber=0;
   int selection = -1;
   setEmpty(SenePark);
   cout << "SenePark Valet Parking" << endl << endl;
   while (selection) {
      switch (selection = menu())      {
      case 0: // close parking
         if (!isEmpty(SenePark)) {
            closeParking(SenePark);
            cout << "Parking is closed now! Goodbye..." << endl;
         }
         else {
            cout << "Parking is already closed!" << endl;
         }
         break;
      case 1: // open parking
         if (isEmpty(SenePark)) {
            cout << "Please enter the number of available spots.\n> ";
            read(noOfSpots, 1, 100, "Invalid Number of spots.\n> ");
            openParking(SenePark, noOfSpots);
         }
         else {
            cout << "The parking is already open!" << endl;
         }
         break;
      case 2: // park a car
         if (isEmpty(SenePark)) {
            cout << "Parking is closed!" << endl;
         }
         else {
            spotNumber = parkCar(SenePark);
            if (spotNumber < 0) {
               cout << "Sorry Parking is full!" << endl;
            }
            else {
               cout << "Your car is parked in spot number " << spotNumber + 1 << endl;
            }
         }
         
         break;
      case 3:  // return a car
         if (isEmpty(SenePark)) {
            cout << "Parking is closed!" << endl;
         }
         else {
            cout << "What is your spot number?\n> ";
            read(spotNumber, 1, noOfSpots, "Invalid Spot Number!\n> ");
            if (!returnCar(SenePark, spotNumber-1)) {
               cout << "There is no car parked at spot " << spotNumber  << endl;
            }
         }
         break;
      }
   }
}
int menu() {
   int option;
   cout << "1- Open Parking" << endl
      << "2- Park A Car" << endl
      << "3- Return A Car" << endl
      << "0- Close Parking" << endl
      << "> ";
   read(option, 0, 3, "Invalid Option.\n> ");
   return option;
}

/*
Sample Execution:
SenePark Valet Parking

1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 2
Parking is closed!
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 1
Please enter the number of available spots.
> 3
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 3
What is your spot number?
> 2
There is no car parked at spot 2
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 2
Make and Model: BMW 320
License Plate: ABC123
Your car is parked in spot number 1
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 2
Make and Model: Tesla Model 3
License Plate: GVXT123
Your car is parked in spot number 2
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 2
Make and Model: Honda Civic
License Plate: QWE123
Your car is parked in spot number 3
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 2
Sorry Parking is full!
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 3
What is your spot number?
> 2
Returning Tesla Model 3, plate number: GVXT123
1- Open Parking
2- Park A Car
3- Return A Car
0- Close Parking
> 0
Returning BMW 320, plate number: ABC123
Returning Honda Civic, plate number: QWE123
Parking is closed now! Goodbye...

*/