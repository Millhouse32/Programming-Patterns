/*
    Lab 1
    Title: Diff
    Date: August 30, 2022
    Author: Nicholas Miller
*/
#include <iostream>

void compareFiles(FILE *file1, *file2) {
    
}

int main (int argc, char* argv[]){

    // verifies the command line arguments... exits if incorrect
    if (argc != 3) {
        std::cerr << "Program requires 2 command line arguments!" << std::endl;
        exit(1);
    }
   
   // variables that hold the file name
   const char* filename1;
   const char* filename2;

   filename1 = argv[1];
   filename2 = argv[2];
   
   // opens both files as read only
   FILE *file1 = fopen(filename1, "r");
   FILE *file2 = fopen(filename2, "r");

   return 0;
}