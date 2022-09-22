// Lab 4
// Nicholas Miller

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string;
using std::getline;
using std::list;
using std::cout;
using std::vector;
using std::move;
using std::endl;

// read list from file
void readRoster(list<list<string>>& roster, string filename);

// print list
void printRoster(const list<list<string>> & roster);

int main () {
    int size = 4;
    string files[4];

    files[0] = "cs1.txt";
    files[1] = "cs2.txt";
    files[2] = "cs3.txt";
    files[3] = "cs4.txt";

    string file5 = "dropouts.txt";

    // vector of class students
    vector<list<string>> courseStudents;

    list<list<string>> roster;
    for (int i = 0 ; i < size; i++) {
      readRoster(roster, files[i]);
      cout << "\n\n" << files[i] << "\n";
      printRoster(roster);
    }

    // read dropouts
    list<list<string>> dropouts;
    readRoster(dropouts, file5);
    cout << "\n\nDropouts:\n";
    printRoster(dropouts);

    list<list<string>> masterList;
    masterList = roster;

    cout << "\nMaster list unsorted \n";
    printRoster(masterList);

    // sort master list
    masterList.sort();
    cout << "\n\nMaster List sorted \n";
    printRoster(masterList);

    // remove duplicates
    masterList.unique();
    cout << "\n\nMaster list with no duplicates\n";
    printRoster(masterList);

    bool flag = false;
    for (const auto& drop : dropouts) {
      list<string> temp;
      for(auto& str : masterList) {
         // check if name is of a dropout
         if (str.front() == drop.front()) {
            for (const auto& e : str) {
               temp.push_back(e);
            }
            flag = true;
         }
      }
      if (flag) {
         masterList.remove(temp);
         flag = false;
      }
    }

    cout << "\n\nMaster list with dropouts removed\n";
    printRoster(masterList);

    // remove students concurrently enrolled in cs4 and any other course
    cout << "Removing students concurrently enrolled in cs4 and any other course\n";
    bool remove = false;

    for (int i = masterList.size()-1; i >=0; i--) {
      list<string> temp;
      list<string> removal;

      for (auto& str : masterList) {
         temp.clear();
         removal.clear();
         for (const auto& e : str) {
            removal.push_back(e);
            temp.push_back(e);
         }
         temp.pop_front();

         if (temp.front() == "cs4.txt") {
            // do not remove
         }
         else if (temp.back() == "cs4.txt") {
            remove = true;
            break;
         }
         else {
            // do not remove
         }
      }
      if (remove) {
        remove = false;
        masterList.remove(removal);
      }
    }

    // print master list after removal
    cout << "\n\nMaster list after removal\n";
    printRoster(masterList);

    return 0;
}

void readRoster(list<list<string>>& roster, string filename) {

   ifstream course (filename);
   string first, last;
   bool flag = true;

   while (course >> first >> last) {
      for (auto& str: roster) {
         if (str.front() == first + ' ' + last) {
            str.push_back(filename);
            flag = false;
         }
      }
      if (flag) {
         list<string> temp;
         temp.push_back(first + ' ' + last);
         temp.push_back(filename);
         roster.push_back(temp);
      }
      flag = true;
   }
}

void printRoster(const list<list<string>>& roster) {
   for (const auto& str: roster) {
      for (const auto& i : str) {
         cout << i << " ";
      }
      cout << endl;
   }
}