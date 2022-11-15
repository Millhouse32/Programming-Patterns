// abstract and concrete product classes
// Wayne Cheng
// 2/11/2018
#include <string>
#include <vector>
#include <array>
using namespace std;
class Car
{
public:
//std::string getMake() {return make_;}
string getMake() {return make_;}
//std::string getModel() {return model_;}
string getModel() {return model_;}
protected:
//std::string model_; // this car's model
string model_; // this car's model
//std::string make_; // this car's make
string make_; // this car's make
};
class Ford : public Car {
public:
    Ford();
};
class Toyota : public Car {
public:
    Toyota();
};

Ford::Ford() {
    static const array<std::string, 4>
        models = { "Focus", "Mustang", "Explorer", "F-150" };
    make_ = "Ford";
    model_ = models[rand() % models.size()];
}

Toyota::Toyota() {
    static const array<std::string, 5>
        models = { "Corolla", "Camery", "Prius", "4Runner", "Yaris" };
    make_ = "Toyota";
    model_ = models[rand() % models.size()];
}