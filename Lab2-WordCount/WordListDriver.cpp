// testing the implementation of class WordList 
// Wayne Cheng
// 1/20/2018
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "WordList.h" // class definitions 
using namespace std; 

//void testfunc(WordList); // function to test pass-by-value for WordList class 

int main(int argc, char* argv[])
{ 
	// verifies the command line arguments... exits if incorrect
	if (argc != 2){
		cerr << "Program required 1 command line arugement!" << endl;
		exit(0);
	}

	// variable that holds filename
	string filename;

	filename = argv[1];

	ifstream file;

	// open file
	file.open(filename);

	if (file.fail()) {
		cerr << "Error opening file" << endl;
		exit(0);
	}

	// file conents
	string fileContents;
	ostringstream ss;
	ss << file.rdbuf();
	fileContents = ss.str();

	cout << "File Contents..." << endl;
	cout << fileContents << endl;

	//  WordList wl; 
	
	//  // testing regular member functions 
	//  wl.addWord("one"); 
	//  wl.addWord("one"); // adding duplicate 
	//  wl.addWord("two"); 
	//  wl.addWord("three"); 
	//  cout << "word list is:\n"; 
	//  wl.printList(); 
	
	//  WordList wl2, wl3; 
	
	 //wl3=wl2=wl; // testing overloaded assignment 
	 //wl3=wl3; // testing protection against self-assingment 
	 //testfunc(wl); // testing copy constructor 
	 //wl.printList(); // if destructor is implemented correctly 
		     // this should print properly after testfunc completes 
} // tests pass-by-value for object of class varArray 

 //void testfunc(WordList myList)
 //{ 
 	// copy constructor is invoked on "myList" 
 	//cout << "word list in testfunc: \n"; 
 	//myList.printList(); 
 //} // destructor is invoked when "myList" goes out of scope 