/*
    @ file lab3Test.cpp

    Test program for lab3.cpp
*/
#include "Collection.h"
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

int main() {

    // testing add list function
    Collection<int> test1;
    test1.addItem(1);
    std::string one;
    one += 1;
    assert(test1.printCollection() == one);
    std::cout << std::endl;
    std::cout << "Add function test passed!" << std::endl;

    // testing remove list function
    Collection<char> test2;
    test2.addItem('a');
    test2.addItem('b');
    test2.addItem('c');
    
    std::string output = test2.printCollection();
    std::cout << std::endl;
    test2.removeItem('b');
    std::string outputAfterRemove = test2.printCollection();
    std::cout << std::endl;
    std::cout << "Remove function test passed!" << std::endl;
    
    assert(output.find('b') != -1 && outputAfterRemove.find('b') == -1);

    // testing print collection
    Collection<char> test3;
    test3.addItem('a');
    test3.addItem('b');
    test3.addItem('c');
    std::string test3text = test3.printCollection();
    assert(test3text == "cba");
    std::cout << std::endl;
    std::cout << "Print collection test passed!" << std::endl;

    // testing last item
    Collection<char> test4;
    test4.addItem('a');
    test4.addItem('b');
    test4.addItem('c');

    assert(test4.lastItem() == 'c');
    std::cout << "Last item test passed!" << std::endl;

    std::cout << "\nAll tests passed!" << std::endl;
}