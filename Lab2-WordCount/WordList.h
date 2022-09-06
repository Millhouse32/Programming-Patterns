// Word Count Header file 
// Author: Nicholas Miller
#include <string>
#include <iostream>
#include "WordOccurrence.h"

using namespace std;

class WordList {
public:
    // add copy constructor, destructor, and overload assignment

    WordList(const WordList& org); // copy constructor
    ~WordList(); // destructor
    WordList& operator = (const WordList& rhs); // overloaded assignment

    WordList();
    WordList(const string &word);


    void addWord(const string &);
    void printList();
private:
    // a dynamically allocated array of WordOccurrences
    // may or may not be stored
    WordOccurrence *wordArray_ ;

    int size_ ;
};

WordList::WordList(const WordList& org){
    size_ = org.size_;

    wordArray_ = new WordOccurrence[org.size_];
    // copy each element of org.wordArray_ to this.wordArray_
    for (int i = 0; i < size_; i++) {
        wordArray_[i] = WordOccurrence(org.wordArray_[i].getWord(), org.wordArray_[i].getNum());
    }
}

WordList::~WordList() {
    // executed when wordList object goes out of scope (program ends)
    delete[] wordArray_;
}

void WordList::printList() {
    
}

