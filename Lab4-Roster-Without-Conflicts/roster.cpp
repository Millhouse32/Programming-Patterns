/* 
    Lab 4
    Nicholas Miller 
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

// read list form file
void readRoster(std::list<std::string>& roster, std::string filename);

// print list
void printRoster(const std::list<std::string>& roster);

int main(int argc, char* argv[]) {
    if (argc <= 1 ) {
        std::cout << "Usage: " << argv[0]
        << " list of courses, dropouts last" << std::endl;
        exit(1);
    }

    // vector of courses of students
    std::vector<std::list<std::string>> courseStudents;

    std::list<std::string> roster;
    for (int i = 1; i < argc; ++i) {
        readRoster(roster, argv[i]);
    }
    courseStudents.push_back(roster);

    // master list of students
    std::list<std::string> masterList = move(roster);

    // sort msater list
    masterList.sort();

    // eliminate duplicates
    masterList.unique();
    std::cout << "\nAll students\nlast name, first name: courses enrolled\n";
    printRoster(masterList);
}

void readRoster(std::list<std::string>& roster, std::string filename) {
    std::ifstream course (filename);
    int i = 0;
    std::string currentCourse;
    while(filename.at(i) != '.') {
        currentCourse += filename.at(i);
        ++i;
    }

    std::string first;
    std::string last;
    bool inList = false;
    while (course >> first >> last) {
        for (auto& e : roster) {
            if(e.find(last) != std::string::npos) {
                inList = true;
                e = e + ' ' + currentCourse;
                break;
            }
        }
        if (inList == false) {
            roster.push_back(last + ", " + first + ": " + currentCourse);
        }
    }
    course.close();
}

// printing list
void printRoster(const std::list<std::string>& roster) {
    for (const auto& str : roster) {
        std::cout << str << std::endl;
    }
}