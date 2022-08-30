/*
    Lab 1
    Title: Diff
    Date: August 30, 2022
    Author: Nicholas Miller
*/
#include <iostream>

// Function to compare both text files
void compareFiles(FILE *file1, FILE *file2) {
    
    // get character from two files and store then in ch1 and ch2
    char ch1 = getc(file1);
    char ch2 = getc(file2);

   // track position and line
   int pos = 0, line = 1;

   // iteratore loop until end of file is reached
   while(ch1 != EOF && ch2 != EOF) {
       pos++;

       if (ch1 == '\n' && ch2 == '\n'){
          line++;
          pos = 0;
       }  
   } 

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