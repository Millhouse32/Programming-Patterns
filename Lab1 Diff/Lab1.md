# CSIII: Programming Patterns 
## Lab 1 Assignment: Diff
The project is due in one week. Specifically, it is due by the beginning of the next lab. 
Implement the lab using procedural programming techniques only. That is, you are not allowed to define classes or objects. 
Diff. Implement a program that compares two text files character-by-character. The program should output the line numbers that contain different characters and the place where the two lines start to differ (the difference is denoted by ^ (caret) character. If both files are identical, the program should output nothing. If one file is shorter than the other, the shorter file is assumed to have empty lines, i.e. the extra lines of the longer file are considered different from the empty lines of the shorter file. 
The file names should be passed as arguments on the command line. Assume the two file names are the same length. Assume the files exist. If your program is invoked with different number of arguments, print help message and quit. The program operation should look like this: 
	prompt% diff file1.txt file2.txt

	file1.txt: 20: Hello
	file2.txt: 20: Hallo
                        ^
	file1.txt: 25: World????
	file2.txt: 25: World!
                            ^
where 20 and 25 are line numbers. 
You are allowed to use getline() and string comparison functions in the implementation of this project. 
Milestone. Code that inputs two lines from two different files and determines whether they are the same. 
Hint. The command line arguments are input as C-style strings arguments to main(). See follwong code for an example of handling them. 

```
#include  <iostream>
using namespace std; 
int main(int argc, char* argv[])
{ 
	for(int i=0; i < argc; ++i) 
		cout << argv[i] << endl; 
}
```

To configure command-line arguments for an MS Visual Studio project, right-click Solution Explorer, select "properties" from the drop-down menu, go to Configuration Properties Debugging and set "Command Arguments" in the properties list. 
To create a string of spaces of a particular length use this form of initialization: string spaceString(length, ' ');, or use assign operator: spaceString.assign(length, ' '); 
