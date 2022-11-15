// interface for abstract and concrete car factories
// Wayne Cheng
// 2/11/2018

#include <string>
#include "Car.h"
using namespace std;

// absract factory
class CarFactory 
{
	public:
		CarFactory(string location, int numCarsInProduction):
		location_(location), 
		numCarsInProduction_(numCarsInProduction){}

		Car* requestCar();
		int getNumCarsInProduction() const 
        {
			return numCarsInProduction_;
		}
		string getLocation() const {return location_;}
		virtual ~CarFactory(){}
		
	protected:
		virtual Car* makeCar() =0;

	private:
		int numCarsInProduction_;
		string location_;
};

CarFactory* getLeastBusyFactory(const vector<CarFactory*> &inFactories) {
	if (inFactories.size() == 0)
		return nullptr;
	auto bestSoFar = inFactories[0];

	for (size_t i = 1; i != inFactories.size(); ++i) {
		if(inFactories[i]->getNumCarsInProduction() < 
			bestSoFar->getNumCarsInProduction())
			bestSoFar = inFactories[i];
	}
	return bestSoFar;
}

// two concrete factories
class FordFactory : public CarFactory 
{
	public:
		FordFactory(string location="", int numCarsInProduction=0):
		CarFactory(location, numCarsInProduction){}
		
	protected:
        Car* requestCar();
		Car* makeCar();
};

class ToyotaFactory : public CarFactory 
{
	public:
		ToyotaFactory (string location="", int numCarsInProduction=0):
		CarFactory(location, numCarsInProduction){}
		
	protected:
        Car* requestCar();
		Car* makeCar();
};

Car* CarFactory::requestCar() {
	++numCarsInProduction_;

	return makeCar();
}

Car* FordFactory::makeCar() {
	return new Ford();
}

Car* ToyotaFactory::makeCar() {
	return new Toyota();
}