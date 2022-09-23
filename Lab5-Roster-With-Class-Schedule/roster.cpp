// Nicholas Miller
// Lab 5

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>
#include <utility>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::map;
using std::make_pair;

class Student {
    public:
        Student(string firstname, string lastname):
            firstname_(firstname), lastname_(lastname) {}
        
        Student(Student && org):
            firstname_(move(org.firstname_)),
            lastname_(move(org.lastname_))
            {}
        
        Student(const Student & org) = default;

        string print() const { return firstname_ + ' ' + lastname_; }

        // needed for unique and remove
        friend bool operator== (Student left, Student right) {
            return left.lastname_ == right.lastname_ && 
                   left.firstname_ == right.firstname_;
        }

        // needed for sort
        friend bool operator< (Student left, Student right) {
            return left.lastname_ < right.lastname_ ||
	            (left.lastname_ == right.lastname_ && 
	            left.firstname_ < left.firstname_);            
        }
    
    private:
        string firstname_;
        string lastname_;
};