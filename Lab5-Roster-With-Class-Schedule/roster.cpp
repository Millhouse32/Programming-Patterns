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

void readRoster(list<Student>& roster, string filename);

void printRoster(const list<Student>& roster);

int main(){
    int size = 4;
    string files[4];
    files[0] = "cs1.txt";
    files[1] = "cs2.txt";
    files[2] = "cs3.txt";
    files[3] = "cs4.txt";

    map<Student, list<string>> masterList; // master list of students

    for (int i = 0; i < 4; i++) {
        string currentCourse;
        string filename = files[i];
        int index = files[i].find('.');
        currentCourse = files[i].substr(0, index);

        list<string> classes;
        classes.push_back(currentCourse);

        list<Student> roster;
        readRoster(roster, filename);
        for (auto e : roster) {
            auto ret = masterList.insert(make_pair(e, classes));
            if (!ret.second) {
                ret.first->second.push_back(currentCourse);
            }
        }
    }

    for (auto e : masterList) {
        cout << e.first.print() + " :";
        for (auto str : e.second) {
            cout << " " + str + " ";
        }
        cout << endl;
    }
    return 0;
}

void readRoster(list<Student>& roster, string filename) {
    ifstream course(filename);

    string first, last;
    while (course >> first >> last) {
        roster.push_back(Student(first, last));
    }
    course.close();
}