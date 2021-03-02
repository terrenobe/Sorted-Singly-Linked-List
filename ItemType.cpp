#include "ItemType.h"
#include <iostream>
#include <stdio.h>
using namespace std;

ItemType::ItemType(){}

Comparison ItemType::compareTo(ItemType item){
  if (getValue() > item.getValue()){
    //cout << "GREATER"<< endl;
    return GREATER;
  }
  else if (getValue() < item.getValue()){
    //cout << "LESS"<< endl;
    return LESS;
  }
  else{
    //cout << "EQUAL"<< endl;
    return EQUAL;
  }
} //compareTo

int ItemType::getValue() const{
  return value;
} //getValue

void ItemType::initialize(int num){
  value = num;
} //initialize
