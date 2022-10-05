# Lab8: Singleton Logger

## Description
Write code for a program that implements logging into a file using Singleton design pattern. 
Specifically, you need to implement a class `Logger` whose object has a public function 
`report(const String&)`. When `report()` is first accessed, it opens a text file 
`log.txt`. When report() is invoked, the argument string is appended to the file. When the 
program terminates, the log file stream is flushed and closed. You may implement either Classic 
or Meyers Singleton. See “example.cpp” for an example of opening a file for appending.

Demonstrate the operation of your object by invoking the `report()` in at least two separate 
functions. 

## Credits
Work completed by Nicholas Miller

## Usage
- **make** builds the program with `clang++ -std=c++11 test_logger.cpp -o test_logger`
- **make run** runs the program with `./test_logger`
- **make clean** removes the executable `test_logger`