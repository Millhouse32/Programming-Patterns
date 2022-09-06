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

    void addWord(const string &);
    void printList();
private:
    // a dynamically allocated array of WordOccurrences
    // may or may not be stored
    WordOccurrence *wordArray_ ;

    int size_ ;
};

WordList::WordList() {
    size_ = 0;

    wordArray_ = new WordOccurrence[size_];
}

WordList::WordList(const WordList &wl){
  size_ = wl.size_;
  wordArray_ = new WordOccurrence[size_];
  for(int i = 0; i < size_; ++i){
    wordArray_[i] = wl.wordArray_[i];
  }
}

WordList::~WordList() {
    // executed when wordList object goes out of scope (program ends)
    delete[] wordArray_;
}

WordList& WordList::operator=(const WordList &rhs) {
    if (&rhs != this){
        delete[] wordArray_;
        size_ = rhs.size_;
        wordArray_ = new WordOccurrence[size_];
        for (int i = 0; i < size_; ++i){
            wordArray_[i] = rhs.wordArray_[i];
        }
    }
    return *this;
}

void WordList::printList() {
    // printing
    WordOccurrence obj;
    int j,k;
    for (int i = 1; i < size_; ++i) {
        obj = wordArray_[i];
        k = wordArray_[i].getNum();
        j = i - 1;
        while (j >= 0 && wordArray_[i].getNum() > k) {
            wordArray_[j+1] = wordArray_[j];
            j = j -1;
        }
        wordArray_[j+1] = obj;
    }

        string word;
        int num;

        cout << "Word List\n" << endl;
        cout << "Word:\tOccurrences:" << endl; 
        for (int i = 0; i < size_; ++i) {
            num = wordArray_[i].getNum();
            word = wordArray_[i].getWord();
            cout << setw(15) << left << word << setw(5) << right << num << endl;
        }
}

void WordList::addWord(const string& word){

    // check if word is already in list
    for (int i = 0; i < size_; ++i) {
        if (wordArray_[i].matchWord(word)){
            wordArray_[i].increment();
            return;
        }
    }

    // add word if not in list
    WordList temp(*this);
    ++size_;
    delete[] wordArray_;
    wordArray_ = new WordOccurrence[size_];
    for (int i = 0; i < size_-1; i++) {
        wordArray_[i] = temp.wordArray_[i];
    }
    wordArray_[size_ -1] = WordOccurrence(word, 1);
}

