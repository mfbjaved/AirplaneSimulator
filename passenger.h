#ifndef PASSENGER_H
#define	PASSENGER_H

#include "plane.h"

class Passenger 
{
public:
  static const int CANCELLED = -1;
  static const int NAME_LENGTH = 30;
private:
  short flightNum;
  short row; 
  char seat;
  char name[NAME_LENGTH];
  friend ostream& operator << (ostream &o, const Passenger &passenger);
  friend ifstream& operator >> (ifstream &inf, Plane& plane);
public:
  Passenger();
  Passenger(short flightNu, short ro, char sea, const char nam[]);
  static void copyPassengers();
  const bool operator== (int nFlights) const; 
  const bool operator== (const char *c);
  const Passenger& operator!();
}; // class passengers 

#endif	// PASSENGERS_H
