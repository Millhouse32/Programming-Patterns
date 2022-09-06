// Word Occurrence header file
// Author: Nicholas Miller

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class WordOccurrence {

public:

    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const;
    int getNum() const;

private:

    string word_ ;
    int num_ ;
};

WordOccurrence::WordOccurrence(const string& word, int num) {
    string temp = word;
    string s = "";
    // temp is the same word but with all letters lower cased
    for (int i = 0; i < word.size(); i++) {
        temp[i] = tolower(word[i]);
    }

    for (int i = 0; i < temp.size(); i++) {
        if (isalpha(temp[i])) {
            // s only adds a character if it is an alpha character
            s += temp[i];
        }
    }

    // word is only alpha character and contains no spaces or puncuation
    word_ = s;
    num_ = num;
}

bool WordOccurrence::matchWord(const string &word){
    
}