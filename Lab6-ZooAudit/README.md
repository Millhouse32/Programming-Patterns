# Lab 6: Zoo Audit

## Description
Examine this code of Zoo enclosure audit system. The code examines the map of enclosures and animals in each enclosure. It then removes, from every enclosure, an animal that is present in more than one enclosure. The code also removes from every enclosure the animals on a sick list. 
Modify this program so that it acts as follows: removes only the duplicate animals. That is, an animal is removed from an enclosure only if it is kept in another enclosure; otherwise the animal is kept. To put another way, there may be at most one animal of any species in the zoo. Sick animals still need to be removed completely. 
To carry out this modification you should modify getDuplicates function to returns a multiset of all the extraneous (to be removed) animals. Then, modify auditEnclosures function so that it removes an animal from the duplicates containers as it removes it from the enclosure. 

## Credits
Work completed by Nicholas Miller

## Usage
**make** builds the program using `clang++ -std=c++11 zoo.cpp -o zoo`
**make run** runs the program with `./zoo`
**make clean** removes the executable from the directory
