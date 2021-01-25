// Author: Sean Davis
#include <cstring>
#include <fstream>
#include "passenger.h"
using namespace std;


Passenger::Passenger() 
{
} // Passenger()


Passenger::Passenger(short flightNu, short ro, char sea, const char nam[]) : 
  flightNum(flightNu), row(ro), seat(sea)
{
  strcpy(name, nam);
}  // Passenger()


void Passenger::copyPassengers()
{
  Passenger passenger;

  ifstream inf("passengers.dat", ios::binary);
  ofstream outf("passengers2.dat", ios::binary);

  while(inf.read( (char*) &passenger, sizeof(Passenger)))
    outf.write((char*) &passenger, sizeof(Passenger));

  outf.close();
  inf.close();
}  // copyPassengers()

const bool Passenger::operator== (int nFlights) const
{
  if(flightNum == nFlights)
    return true;

return false;
} // ==

const bool Passenger::operator== (const char *c)
{
  if(strcmp(name, c) == 0)
  {
    return true;
  }//if
 
  return false;
}// ==

const Passenger& Passenger::operator!()
{
  flightNum = CANCELLED;
  
  return *this;
}// !

ostream& operator << (ostream &o, const Passenger &passenger)
{
  o << passenger.name;
  
  return o;
}// <<
