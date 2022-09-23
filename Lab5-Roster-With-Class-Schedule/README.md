# Lab 5: Roster with Class Schedule Associative

## Description
Recode roster example we studied in class such that it prints the list of classes each student is enrolled in. Here is an example printout:
```
All Students
last name, first name:  courses enrolled 
Kathleen Andreson: CS1   CS3  CS4
Gerald Edwards: CS1   CS2 CS3
Mary Price: CS1
...
```
The project should be done using associative containers. Specifically, you need to use a map keyed by the student name, the map value may be the list of courses the student is enrolled in. The map should be the ordered map. That is, the data structure to be used in as follows: 
```
map<string, list<string>> studentEntries;
```

## Credits
Work completed by Nicholas Miller

## Usage
- **make** builds the program with 'g++ -std=c++11 roster.cpp -o roster'
- **make run** executes with './roster'
- **make clean** removes executable 'roster'
