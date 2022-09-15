// testing the implementation of templated list collection 
// Wayne Cheng
// 1/25/2018

 
#include "Collection.h" // template definition 
#include <iostream>
using namespace std; 

int main()
{ 
	// manipulating integers 
	Collection<int> cone; 
	cout << "Integer collection: "; 
	cone.addItem(1); 
	cone.addItem(2); 
	cone.addItem(3); 
	cone.printCollection(); 
	cout << endl;
	cone.removeItem(2); 
	cone.printCollection(); 
	cout << endl;

	// manipulating strings string 
	string sa[] = {"yellow", "orange", "green", "blue"}; 
	Collection<string> ctwo; 
	for(auto s : sa) 
		ctwo.addItem(s); 
	cout << "String collection: "; 
	ctwo.printCollection(); 
	cout << endl;

	// manipulating character collections individal collections 
	Collection<char> a2g, h2n, o2u; 
	for(char c='a'; c <='g'; ++c) 
		a2g.addItem(c); 

	for(char c='h'; c <='n'; ++c) 
		h2n.addItem(c); 
	for(char c='o'; c <='u'; ++c) 
		o2u.addItem(c); 

	// collection of collections 
	Collection<Collection<char> > cpile; 

	// adding individual collections 
	cpile.addItem(a2g); 
	cpile.addItem(h2n);
	cpile.addItem(o2u); 

	// printing characters from last collection added 
	cout << "Last added character collection: "; 
	cpile.lastItem().printCollection();
	cout << endl;
} 