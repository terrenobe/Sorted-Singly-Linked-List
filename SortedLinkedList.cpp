#include "SortedLinkedList.h"
#include <stdio.h>
#include <iostream>
#include <cstddef>

using namespace std;

SortedLinkedList::SortedLinkedList(){
  length = 0;
  head = NULL;
  currentPos= NULL;
} //SortedLinkedList

int SortedLinkedList::getLength() const {
  return length;
} //getLength

void SortedLinkedList::insertItem(ItemType item){
  ListNode * loc = head; //travelling pointer
  ListNode * predLoc = NULL; //trailing pointer
  bool passed = false;
  ListNode * node = new ListNode; //new node to be inserted
  node->item = item;
  while (loc != NULL && !passed){
    if (loc->item.compareTo(item) == LESS){
      predLoc = loc;
      loc = loc->next;
    } //if
    else
      passed = true;
  } //while
  if (predLoc == NULL){ //if first
    node->next = head;
    head = node;
  } //if
  else{
    node->next = loc;
    predLoc->next = node;
  } //else
  length++;
} //insertItem

void SortedLinkedList::deleteItem(ItemType item){
  ListNode * temp;
  ListNode * loc = head;
  if (length < 1){
    //do nothing
  } //if
  else if (length == 1){ //if only 1 element
    temp = loc;
    head = NULL;
    delete temp;
    length--;
  }//if
  else if (loc->item.compareTo(item) == EQUAL){ //if first item
    temp = loc;
    head = head->next;
    delete temp;
    length--;
  } //if
  else{
    while (loc->next != NULL && (item.compareTo((loc->next)->item) != EQUAL)){ //error on this line
      loc = loc->next;
    } //while
    if (loc->next == NULL) //if not found
      cout << "Item not found" << endl;
    else{ //if found
      temp = loc->next;
      loc->next = (loc->next)->next;
      delete temp;
      length--;
    } //else
  } //else
} //deleteItem

int SortedLinkedList::searchItem(ItemType & item){
    ListNode * loc = head;
    while(loc->next != NULL && (item.compareTo((loc->next)->item) != EQUAL)) {
        loc = loc->next;
    }//while
    if (loc->next == NULL) { //if not found
        cout << "Item not found" << endl;
    }//if
    else { //if found
        return item;
    }//else
} //searchItem

ItemType SortedLinkedList::getNextItem(){
    currentPos++;
    return item[currentPos];
} //getNextItem

void SortedLinkedList::resetList(){
  currentPos = NULL;
} //resetList

void SortedLinkedList::reverse(){
  
} //reverse

void SortedLinkedList::print(){
  ListNode * temp = head;
  if (length > 0){
    while (temp != NULL){
      cout << temp->item.getValue() << " ";
      temp = temp->next;
    } //while
  } //if
  cout << endl;
} //print

SortedLinkedList::~SortedLinkedList(){
  ListNode * temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
  } //while
  length = 0;
} //~SortedLinkedList
