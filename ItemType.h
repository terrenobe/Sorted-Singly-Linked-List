enum Comparison { GREATER, LESS, EQUAL};

using namespace std;

class ItemType{
 public:
  ItemType(); //default constructor
  Comparison compareTo(ItemType item); //compare items
  int getValue() const; //returns value
  void initialize(int num); //initializes value
 private:
  int value;
};
