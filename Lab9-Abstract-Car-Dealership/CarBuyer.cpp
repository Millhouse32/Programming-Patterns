#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "CarFactory.h"
using namespace std;

class CarLot {
   public: 
      CarLot();
      Car *testDriveCar() { return car4Sale_; }
      bool lotFull();
      void startOver();
      Car *nextCar();

      Car *buyCar() {
         Car *bought = car4Sale_;
         car4Sale_ = factories_[rand() % factories_.size()]->requestCar();

         return bought;
      }
   private:
      vector<Car *> cars_;
      Car *car4Sale_;
      vector<CarFactory *> factories_;
};

Car* CarLot::nextCar() {
   if (car4Sale_ != nullptr) {
      cars_.push_back(car4Sale_);
   }

   car4Sale_ = factories_[rand() % factories_.size()]->requestCar();
   return car4Sale_;
}

void CarLot::startOver() {
   car4Sale_ = nullptr;
   cars_.clear();
}

bool CarLot::lotFull() {
   if (cars_.size() >= 10) {
      return true;
   }
   else {
      return false;
   }
}

CarLot::CarLot() {

   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());
   factories_.push_back(new FordFactory());
   factories_.push_back(new ToyotaFactory());

   car4Sale_ = factories_[rand() % factories_.size()]->requestCar();
}

CarLot *carLotPtr = nullptr;

Car* toyotaLover() {

   if (carLotPtr == nullptr)
      carLotPtr = new CarLot();
   
   Car *toBuy = carLotPtr->testDriveCar();

   cout << "\ntest driving "
        << toBuy->getMake() << " "
        << toBuy->getModel();
   if (toBuy->getMake() == "Toyota") {
      cout << " love it! buying it!" << endl;
      carLotPtr->buyCar();
   }
   else {
      cout << " did not like it!" << endl;
   }
   return toBuy;
}

Car* fordLover() {
   if (carLotPtr == nullptr) {
      carLotPtr = new CarLot();
   }

   Car *toBuy = carLotPtr->testDriveCar();

   cout << "\ntest driving "
        << toBuy->getMake() << " "
        << toBuy->getModel();
   if (toBuy->getMake() == "Ford") {
      cout << " love it! buying it!" << endl;
      carLotPtr->buyCar();
   }
   else {
      cout << " did not like it!" << endl;
   }
   return toBuy;
}

int main() {
   srand(time(nullptr));
   CarLot c1;
   Car *car;

   string make;
   string model;

   if ((int)(rand() % 2) == 0) {
      make = "Ford";
   }
   else {
      make = "Toyota";
   }
   int modelNum;
   if (make == "Ford") {
      modelNum = (int)(rand() % 4);
      if (modelNum == 0) {
         model = "Focus";
      }
      else if (modelNum == 1) {
         model = "Mustang";
      }
      else if (modelNum == 2) {
         model = "Expolorer";
      }
      else if (modelNum == 3) {
         model = "F-150";
      }
   }
   else if (make == "Toyota") {
      modelNum = (int)(rand() % 5);
      if (modelNum == 0) {
         model = "Corrola";
      }
      else if (modelNum == 1) {
         model = "Camery";
      }
      else if (modelNum == 2) {
         model = "Prius";
      }
      else if (modelNum == 3) {
         model = "4Runner";
      }
      else if (modelNum == 4) {
         model = "Yaris";
      }
   }

   c1.startOver();
   car = c1.nextCar();
   bool found = false;
   while (!c1.lotFull() && found == false) {
      if (car->getMake() == make && car->getModel() == model) {
         cout << "\nThe car on the lot is a " << car->getMake() << " " << car->getModel();
         cout << "\nI am buying a " << car->getMake() << " " << car->getModel();
         cout << "\n";
         found = true;
      }
      else {
         cout << "\nThe car on the lot is a "<< car->getMake() << " " << car->getModel();
         cout << "\nI am not buying a " << car->getMake() << " " << car->getModel();
         cout << "\nI want to buy a " << make << " " << model;
         cout << "\n";
      }
      car = c1.nextCar();
   }
   if (found == true) {
      car = c1.buyCar();
      cout << "I bought my dream car!\n";
   }
   else if (c1.lotFull()) {
      cout << "\nThe car lot is full. I am leaving\n";
   }

   cout << "\n\nTesting the least busiest factories\n";

   vector<CarFactory *> factories;
   srand(time(nullptr));

   factories.push_back(new FordFactory("Chicago, IL", rand() % 4));
   factories.push_back(new FordFactory("Dearborn, MI", rand() % 4));
   factories.push_back(new FordFactory("Louisville, KY", rand() % 4));
   factories.push_back(new ToyotaFactory("Lafayette, IN", rand() % 4));

   for (int i = 0; i < factories.size(); i++) {
      cout << "\n";
      cout << factories.at(i)->getLocation();
      cout << " has " << factories.at(i)->getNumCarsInProduction() << " cars in production";
   } cout << "\n\n";

   for (size_t i = 0; i < 10; ++i) {

      CarFactory *currentFactory = getLeastBusyFactory(factories);
      Car *newCar = currentFactory->requestCar();
      cout << "Ordering " << newCar->getMake() << " "
      << newCar->getModel()
      << " from " << currentFactory->getLocation() << endl;
   }
   return 0;

}