# Lab 2 Word Count 

## Overview:
Implement a program that reads in a text file, counts how many times each word occurs in the file and outputs the words 
(and counts) in the decreasing order of occurrence, i.e. the counts need to be output in sorted order. 
Word is any sequence of alphanumeric characters. Whitespace and punctuation marks are to be discarded. 
That is, the punctuation marks should not be counted either as a part of the word or as a separate word. 
You are free to make your program case sensitive (Hello and hello are counted as separate words) or case insensitive. 
File name is supplied on command line. You are to use the following classes. 

## Credits:
Work completed by Nicholas Miller

## Use:
I have submitted a Makefile for ease of use

## Commands:
'make' - compiles the program using the clang++ compiler and outputs the executable "WordCount"

'make run filename' will execute ./WordCount filename

'make clean' will remove the executable