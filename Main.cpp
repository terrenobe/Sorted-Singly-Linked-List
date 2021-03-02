#include "SortedLinkedList.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstddef>

using namespace std;

int main( int argc, char* argv[] ){
  SortedLinkedList list;
  ItemType item;
  int input;
  fstream fs;
  char command;
  fs.open(argv[1], fstream::in);
  if (fs.is_open()) {
    fs >> input;
    while (!fs.eof()) {
      item.initialize(input);
      list.insertItem(item);
      fs >> input;
    } //while
  } //if
  else {
    cout << "Failed to open the input file" << endl;
  } //else
  cout << "Commands:\n\t(i) - Insert value\n\t(d) - Delete value\n\t(s) - Search value\n\t(n) - Print next iterator value\n\t(r) - Reset Iterator\n\t(p) - Print list\n\t(l) - Print length\n\t(b) - Reverse\n\t(q) - Quit program";
  do {
    cout << "\nEnter a command: ";
    cin >> command;
    if (command == 'i'){
      list.print();
      cout << "Enter Number: ";
      cin >> input;
      item.initialize(input);
      list.insertItem(item);
      list.print();
    } //if
    else if (command == 'd'){
      list.print();
      cout << "Enter Number: ";
      cin >> input;
      item.initialize(input);
      list.deleteItem(item);
      list.print();
    } //if
    else if (command == 's'){
      cout << "Enter a value to search: ";
      cin >> input;
      item.initialize(input);
      if (list.searchItem(item) != -1)
	cout << "Index " << list.searchItem(item) << endl;
    } //if
    else if (command == 'n'){
      //if (list.getNextItem() != NULL)
	cout << list.getNextItem().getValue() << endl;
    } //if
    else if (command == 'r'){
      list.resetList();
      cout << "Iterator reset." << endl;
    } //if
    else if (command == 'p'){
      list.print();
    } //if
    else if (command == 'l'){
      cout << "List length is " << list.getLength() << endl;
    } //if
    else if (command == 'b'){
      cout << "Before" << endl;
      list.print();
      cout << "After" << endl;
      list.reverse();
      list.print();
    } //if
    else{}
      
  } while(command != 'q'); 
  cout << "Quitting program.." << endl;
  return 0;
} //amin
