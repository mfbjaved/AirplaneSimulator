// Author: Sean Davis

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"

using namespace std;

Flight& Flight::operator++ ( int )
{
  ++(*plane);
  return *this;
}  // ++ 


Flight::~Flight()
{
  ofstream outf("flights2.csv", ios::app);
  outf << flightNum << ',' << origin << ',' << destination << ',';
  plane->writePlane(outf);
  outf.close();
  delete plane;
}  // freeFlight()

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane(flightNum);
  plane->addFlight();
}  // addFlight()

int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()

ostream& operator << (ostream &out, const Flight& flight)
{
  cout << left << setw(flight.FLIGHT_NUM_SPACE) << flight.flightNum << ' ' 
    << setw(flight.MAX_CITY_LENGTH) << flight.origin << ' '  
    << flight.destination << endl;
  return out;
}  //<< 

ifstream& operator >> (ifstream &inf, Flight& flight)
{ 
  inf >> flight.flightNum;
  inf.ignore(flight.TEN, ',');
  inf.getline(flight.origin, flight.MAX_CITY_LENGTH, ',');
  inf.getline(flight.destination, flight.MAX_CITY_LENGTH, ',');
  flight.plane = new Plane(flight.flightNum);
  inf >> *flight.plane;

return inf;
}  //>> 


Flight& Flight::operator! () 
{
  !(*plane);
  return *this;
}  //! 


Flight& Flight::operator-- ( )
{
 (*plane)--;
 return *this; 
}  // -- 

bool Flight::findPassenger(const char *name) const
{
  return plane->findPassenger(name);
} // find passnegr
