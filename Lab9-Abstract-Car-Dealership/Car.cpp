// car class member functions
// Wayne Cheng
// 2/11/2018

#include <string>
#include <array>
#include <cstdlib>
#include "Car.h"
using namespace std;

Ford::Ford()
{
	//static const std::array<std::string, 4> 
	static const array<std::string, 4> 
    models = {"Focus", "Mustang", "Explorer", "F-150"};
	make_ = "Ford";
	model_ = models[rand() % models.size()];
}

Toyota::Toyota(){
	//static const std::array<std::string, 5>
	static const array<std::string, 5>
	models = {"Corolla", "Camry", "Prius", "4Runner", "Yaris"};
	make_ = "Toyota";
	model_ = models[rand() % models.size()];
}
