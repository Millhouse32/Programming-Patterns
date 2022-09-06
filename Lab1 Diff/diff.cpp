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
   
   
   std::ifstream file1;
   std::ifstream file2;

   // open file 1
   file1.open(filename1);
   
   if (file1.fail()){
      std::cerr << "Error opening file 1" << std::endl;
      exit(0);
   }

    // open file 2
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

        // For the case that one file is at EOF and other is a blank line
        if (line1.length() == 0 && line2.length() == 0){
            line1.assign(1, ' ');
            line2.assign(1, ' ');
        }

        // gets legth of shorter line
        int val;
        if (line1.length() < line2.length()) {
            val = line1.length();
        }
        else {
            val = line2.length();
        }

        for (int i = 0; i < val; i++){
            if (line1[i] != line2[i]) {
                difference = true;
                break;
            }
            else {
                spaceCount++;
            }
        }

        // outputs differences between lines with line number and position
        if (difference) {
            std::string output = "file2.txt: " + std::to_string(lineCount) + ": ";
            std::cout << output << line1 << std::endl;
            std::cout << output << line2 << std::endl;
            std::string spaces = "";
            spaces.assign(output.length() + spaceCount, ' ');
            std::cout << spaces << "^";
        }
    // reset variables and add new line for cleaner output
    std::cout << "\n";
    difference = false;
    lineCount++;
    spaceCount = 0;
   }
   // close files
   file1.close();
   file2.close();
   return 0;
}