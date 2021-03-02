#include "ListNode.h"

class SortedLinkedList{
public:
  SortedLinkedList(); //constructor
  int getLength() const; // returns length
  void insertItem(ItemType item); //insert item
  void deleteItem(ItemType item); //delete item
  int searchItem(ItemType & item); // returns index of item
  ItemType getNextItem(); //returns next item
  void resetList(); //resets position in list
  void reverse(); //reverses the linked list
  void print(); //print out list
  ~SortedLinkedList(); //destructor
private:
  int length;
  ListNode * head;
  ListNode * currentPos;
}; //SortedLinkedList
