/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  3/13/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 5: stack.h

Description:Using a singly linked list stack, this program will receive an input in the form of a postfix and 
return an output in the form of an infix. Has several checks for errors to ensure proper output such as too many operators,
too many operands, not a proper input, empty strings, single strings, and allows for spaces.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

struct node
{
	string data;
	struct node *next;
};

class stack
{
public:

	stack();	//default constructor sets the top to 0
	~stack();	//destructor
	string getTop() const;	//function determine the value of the top of the stack
	void push(string data);	//function to push the stack
	string pop();	//function to pop the stack
private:
	struct node *top;
};
#endif
