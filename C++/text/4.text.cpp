#include <iostream>

class Car; // forward declaration

class Boat {
private:
  int weight;

public:
  Boat(int w) : weight(w) {}
  friend int getTotalWeight(Boat b, Car c);
};

class Car {
private:
  int weight;

public:
  Car(int w) : weight(w) {}
  friend int getTotalWeight(Boat b, Car c);
};

int getTotalWeight(Boat b, Car c) { return b.weight + c.weight; }

int main() {
  int boatWeight, carWeight;
  std::cin >> boatWeight >> carWeight;

  Boat myBoat(boatWeight);
  Car myCar(carWeight);

  std::cout << getTotalWeight(myBoat, myCar) << std::endl;

  return 0;
}
