// Word Count Header file 
// Author: Nicholas Miller
#include <stdio.h>
#include <string>
#include <iostream>
#include "WordOccurrence.h"

using namespace std;

class WordList {
    public:
    // add copy constructor, destructor, and overload assignment
    void addWord(const string &);
    void printList();
    private:
    // a dynamically allocated array of WordOccurrences
    // may or may not be stored
    WordOccurrence *wordArray ;

    int size ;
};