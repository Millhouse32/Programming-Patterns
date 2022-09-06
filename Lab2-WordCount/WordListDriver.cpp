// testing the implementation of class WordList 
// Wayne Cheng
// 1/20/2018
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "WordList.h" // class definitions 
using namespace std; 

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

	// file conents
	WordList wl;

	ifstream file(filename);
	string word;

	while (file >> word) {
		for (int i = 0; i < word.size(); ++i) {
			if (ispunct(word[i])) {
				word.erase(i--, 1);
			}
		}
		if (word != " " && word != "\n" && word != "")
			wl.addWord(word);
	}

	wl.printList();

	return 0;
} 