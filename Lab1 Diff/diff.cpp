/*
    Lab 1
    Title: Diff
    Date: August 30, 2022
    Author: Nicholas Miller
*/
#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char* argv[]){

    // verifies the command line arguments... exits if incorrect
    if (argc != 3) {
        std::cerr << "Program requires 2 command line arguments!" << std::endl;
        exit(1);
    }
   
   // variables that hold the file name
   std::string filename1;
   std::string filename2;

   filename1 = argv[1];
   filename2 = argv[2];
   
   // opens both files as read only
   std::ifstream file1;
   std::ifstream file2;

   // open file
   file1.open(filename1);
   
   if (file1.fail()){
      std::cerr << "Error opening file 1" << std::endl;
      exit(0);
   }

   file2.open(filename2);
   if (file2.fail()){
      std::cerr << "Error opening file 2" << std::endl;
      exit(0);
   }

   // line count spaceCount and difference
   int lineCount = 1;
   int spaceCount = 0;
   bool difference = false;
   
   std::string line1;
   std::string line2;

   while(!file1.eof() || !file2.eof()){

        if (file1.eof()){
            // if file 1 is shorter than file 2
            line1.assign(line2.length(), ' ');
        }
        else {
            // read one line from file 1
            getline(file1, line1);
            if (line1.length() == 0) {
                line1.assign(line2.length(), ' ');
            }
        }

        if (file2.eof()){
            // if file 2 is shorter than file 1
            line2.assign(line1.length(), ' ');
        }
        else {
            // read one line from file 2
            getline(file2, line2);
            if (line2.length() == 0) {
                line1.assign(line1.length(), ' ');
            }
        }

        std::string shorterLine;
        if (line1.length() < line2.length()) {

        }

   }

   return 0;
}