# Lab 3 Templated Lists

## Description:
Modify “list.h” and “uselist.cpp” as follows. Create a new templated class Collection that contains this list as a dynamically allocated member, i.e, the list contains a pointer to the first element. You are not allowed to use STL containers. The class has to implement the following methods: 
•	addItem(): takes an item as the argument and adds it to the collection, does not check for duplicates. 
•	removeItem(): takes an item as the argument and removes all instances of this item from the collection. 
•	lastItem(): returns the last item added to the collection. 
•	printCollection(): prints all items in the collection. The printout does not have to be in order. 

## Credits:
Work completed by Nicholas Miller using file provided by Wayne Cheng

## Usage:
- **make** compiles the program by executing 'clang++ -std=c++11 -o lab3 lab3.cpp'
- **make test** runs lab3 test suite
- **make run** executes ./lab3
- **make clean** removes 'lab3' and lab3Test executable files
