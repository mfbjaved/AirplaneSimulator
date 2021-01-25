#ifndef PLANE_H
#define	PLANE_H
#include <fstream>
#include "linkedlist.h"

using namespace std;

class Plane
{
  static const int FIRST_ROW = 1;
  static const int FIRST_SEAT = 'A';
  static const int TEN = 10;
  static const int ROW_SPACE = 2;
  int rows;
  int width;
  int reserved;
  LinkedList* passengers;
  int getRow() const;
  void showGrid() const;
  friend ostream& operator << (ostream &outf, Plane &plane);
  int flightNumber;
public:
  Plane(int flightNum);
  friend ifstream& operator >> (ifstream &inf, Plane &plane);
  ~Plane();
  const Plane& operator++ ();
  void addFlight();
  Plane& operator-- (int);
  Plane& operator! ();
  void writePlane(ofstream &outf) const;
  bool findPassenger(const char *name) const;
}; // class Plane

#endif	// PLANE_H
