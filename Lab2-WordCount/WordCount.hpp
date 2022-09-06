// Word Count Header file 
// Author: Nicholas Miller
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class WordOccurence {
    public:
    WordOccurence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurences
    string getWord() const;
    int getNum() const;

    private:
    string word ;
    int num ;
};

class WordList {
    public:
    // add copy constructor, destructor, and overload assignment
    void addWord(const string &);
    void printList();
    private:
    // a dynamically allocated array of WordOccurrences
    // may or may not be stored
    WordOccurence *wordArray ;

    int size ;
};