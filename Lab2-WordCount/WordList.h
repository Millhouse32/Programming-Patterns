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
    //WordList& operator = (const WordList& rhs); // overloaded assignment

    WordList();
    //WordList(const string &word);


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

WordList::WordList() {
    size_ = 0;

    wordArray_ = new WordOccurrence;
}

WordList::~WordList() {
    // executed when wordList object goes out of scope (program ends)
    delete[] wordArray_;
}

void WordList::printList() {
    int positions[size_];
    
    // sorting
    for (int i = 1; i < size_; i++) {
        WordOccurrence key = wordArray_[i];
        int j = i - 1;
        while (key.getNum() < wordArray_[i].getNum() && j >= 0) {
            wordArray_[j+i] = wordArray_[j];
            --j;
        }
        wordArray_[j+1] = key;
    }

    // printing
    cout << "Words and their Occurrences" << endl;
    for (int i = size_-1; i >=0; i--) {
        cout << wordArray_[i].getWord() << ": " << wordArray_[i].getNum() << endl;
    }
}

void WordList::addWord(const string& word){
    if (size_ == 0) {
        wordArray_[0] = WordOccurrence(word, 1);
        size_++;
    }
    
    else {
        for (int i = 0; i < size_; i++) {
            if (wordArray_[i].matchWord(word)) {
                wordArray_[i].increment();
                return;
            }
        }
        wordArray_[size_] = WordOccurrence(word, 1);
        size_++;
    }
}

