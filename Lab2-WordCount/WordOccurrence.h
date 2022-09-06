// Word Occurrence header file
// Author: Nicholas Miller

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class WordOccurrence {
    public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const;
    int getNum() const;

    private:
    string word ;
    int num ;
};