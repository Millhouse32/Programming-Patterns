# Lab 10 Bridge Painted Squares

## Overview:
Bridge Painted Square. Modify the “Bridge Figures” example studied in class so that 
the border and the inside of the figure can be painted with two different characters. 
Specifically, base class Fill should contain two characters: one for border paint, one for 
internal paint. The constructor for this class should now accept two characters to be 
assigned to the two member variables. The derived class Hollow should initialize the 
border paint to a character, and the internal paint character to a space. The derived class 
Filled should initialize both paints to the same character. 
Create another derived paint class EnhancedFilled that inherits from Filled but 
initializes both paint characters to two different values. Demonstrate the operation of all 
three paint classes by drawing three differently painted squares

## Credits:
Work completed by Nicholas Miller

## Use:
I have submitted a Makefile for ease of use

## Commands:
**make** - compiles the program using the clang++ compiler and outputs the executable "WordCount"

**make run** will execute ./bridgeFigures

**make clean** will remove the executable