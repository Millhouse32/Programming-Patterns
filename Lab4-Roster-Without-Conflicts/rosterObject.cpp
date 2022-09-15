// Nicholas Miller
// Lab 4

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <array>

class Student {
    public:
        Student(std::string firstName, std::string lastName, std::string course):
            firstName_(firstName), lastName_(lastName) { classes_.push_back(course); }
        
        Student(const Student & org) = default;

        std::string print() const { return lastName_ + ", " + firstName_; }
        
        void addCourse(const std::string course) { classes_.push_back(course); }
        
        std::string getCourse() { return classes_.back(); }

        const std::string getLast() const { return lastName_; }

        // for unique() and remove()
        friend bool operator== (Student left, Student right) {
            return left.lastName_ == right.lastName_ &&
                   left.firstName_ == right.firstName_;
        }

        // need for sort()
        friend bool operator< (Student left, Student right) {
            return left.lastName_ < right.lastName_ || 
                   (left.lastName_ == right.lastName_ &&
                    left.firstName_ < right.firstName_);
        }
    
    private:
        std::string firstName_;
        std::string lastName_;
        std::list<std::string> classes_;
};

// print student
std::string Student::print() const {
    std::string temp = firstName_ + ' ' + lastName_ + ' ';
    for(const auto& e : classes_) {
        temp += (e + ' ');
    }
    return temp;
}

// read list from file
void readRoster(std::list<Student>& roster, std::string filename);

// printing list
void printRoster(const std::list<Student> & roster);

int main(int argc, char* argv[]) {
    
    return 0;
}