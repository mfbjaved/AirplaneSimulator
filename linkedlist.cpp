#include <iostream>
#include <fstream>
#include "linkedlist.h"

using namespace std;

void LinkedList::initialize(int numSeat)
{
  head = new ListNode(EMPTY, head); 
  ListNode *ptr = head;
    
    for( int i = 0; i < numSeat; i++)
    {
     ptr->next = new ListNode(EMPTY, ptr);
     ptr = ptr->next; 
    }//

  ptr->next = NULL;
} // initialize

LinkedList::~LinkedList()
{
  for(ListNode *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }//for
} //destroy

int LinkedList::operator[](int seatNum) const
{
  ListNode *ptr = head;
  for(int i = 0; ptr && i < seatNum; i++)
    ptr = ptr->next;

  return ptr->offset;
} // const []

int& LinkedList::operator[](int seatNum)
{
  ListNode *ptr = head;
  for(int i = 0; ptr && i < seatNum; i++)
    ptr = ptr->next;

  if(ptr)
    return ptr->offset;

  return ptr->offset;
} // []

ostream& operator << (ostream &os, const LinkedList &list)
{
  ListNode *ptr; 
  
  for(ptr = list.head; ptr->next; ptr = ptr->next)
  {
    
    if(ptr->offset != LinkedList::EMPTY)
      os << 'X';
    else//
      os << '-';
  }//
  
  return os;
}// <<
