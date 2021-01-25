#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>

using namespace std;

class LinkedList;
class ListNode
{
  int offset;
  ListNode *next;
  ListNode(int o, ListNode* n):offset(o), next(n){};
  friend class LinkedList;
  friend ostream& operator << (ostream &os, const LinkedList &list); 
}; // listnode clase

class LinkedList
{
public:
  static const int EMPTY = -1;
private:
  ListNode *head;
public:
  ~LinkedList();
  void initialize(int numSeat);
  int operator[](int seatNum) const;
  int& operator[](int seatNum);
  friend ostream& operator << (ostream &os, const LinkedList &list); 
}; //list class
#endif
