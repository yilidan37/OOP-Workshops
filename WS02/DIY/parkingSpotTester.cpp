#include "ParkingSpot.h"
using namespace sdds;
int main() {
   ParkingSpot P;
   setEmpty(P);
   print(P);
   parkCar(P);
   print(P);
   freeSpot(P);
   return 0;
}