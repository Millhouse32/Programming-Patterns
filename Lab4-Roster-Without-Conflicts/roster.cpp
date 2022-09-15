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
void printRoster(const std::list<std::string>& roster)