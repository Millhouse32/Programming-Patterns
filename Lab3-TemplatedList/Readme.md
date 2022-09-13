# Lab 3 Templated Lists

## Description:
Modify “list.h” and “uselist.cpp” as follows. Create a new templated class Collection that contains this list as a dynamically allocated member, i.e, the list contains a pointer to the first element. You are not allowed to use STL containers. The class has to implement the following methods: 
•	addItem(): takes an item as the argument and adds it to the collection, does not check for duplicates. 
•	removeItem(): takes an item as the argument and removes all instances of this item from the collection. 
•	lastItem(): returns the last item added to the collection. 
•	printCollection(): prints all items in the collection. The printout does not have to be in order. 
