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

    if (argc <= 1) {
        std::cout << "useage: " << argv[0]
        << " list of courses, dropouts last" << std::endl;
        exit(1);
    }

    // vector of courses of students
    std::vector <std::list<Student>> courseStudents;

    for (int i = 1; i < argc-1; ++i) {
        std::list<Student> roster;
        readRoster(roster, argv[i]);
        std::cout << "\n\n" << argv[i] << "\n";
        printRoster(roster);
        courseStudents.push_back(move(roster));
    }

    // read dropouts
    std::list<Student> dropouts;
    readRoster(dropouts, argv[argc-1]);
    std::cout << "\n\n dropouts \n";
    printRoster(dropouts);

    // master list of students
    std::list<Student> masterList;

    std::cout << "\n\n Master list unsorted: \n";
    printRoster(masterList);

    // Sort master list
    masterList.sort();

    // print sorted
    std::cout << "\n\n Master list sorted: \n";
    printRoster(masterList);

    // get rid of repeats
    masterList.unique();
    std::cout << "\n\n Master list without repeats \n";
    printRoster(masterList);

    // remove droputs
    for (const auto& str : dropouts) {
        masterList.remove(str);
    }
    std::cout << "\n\n Master list without dropouts: \n";
    printRoster(masterList);

    return 0;
}

void readRoster(std::list<Student>& roster, std::string filename) {
    std::ifstream course(filename);
    int i = 0;
    std::string currentCourse;
    while (filename.at(i) != '.') {
        currentCourse += filename.at(i);
        ++i;
    }

    std::string first;
    std::string last;

    while (course >> first >> last) {
        roster.push_back(Student(first, last, currentCourse));
    }
    course.close();
}

// printing list
void printRoster(const std::list<Student>& roster) {
    for (const auto& student : roster)
        std::cout << student.print() << std::endl;
}