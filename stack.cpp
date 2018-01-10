/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  3/13/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 5: stack.cpp

Description: Using a singly linked list stack, this program will receive an input in the form of a postfix and 
return an output in the form of an infix. Has several checks for errors to ensure proper output such as too many operators,
too many operands, not a proper input, empty strings, single strings, and allows for spaces.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include "stack.h"

using namespace std;

/***********************************************************************************************************************************/
//Name: stack
//Precondition: a stack has not been set with default values
//Postcondition: initializes a stack with default value of 0
//Decription: Default constructor
/**********************************************************************************************************************************/
stack::stack()
{
	top = 0;
}

/***********************************************************************************************************************************/
//Name: stack
//Precondition: the stack has not been removed from memory
//Postcondition: the stack has been removed from memory
//Decription: Destructor
/**********************************************************************************************************************************/
stack::~stack()
{
	while (top != 0)
	{
		node *p = top;
		top = top->next;
		delete p;
	}
}

/***********************************************************************************************************************************/
//Name: getTop
//Precondition: the top of the stack's value has not been returned
//Postcondition: returns the value stoed in the top of the stack
//Decription: Returns the value stored in the top of the stack
/**********************************************************************************************************************************/
string stack::getTop() const
{
	if (top != 0)
	{
		return (top->data);
	}
	return "\0";
}

/***********************************************************************************************************************************/
//Name: push
//Precondition: the stack has not been pushed
//Postcondition: the stack has been pushed
//Decription: Pushes the stack
/**********************************************************************************************************************************/
void stack::push(string data)
{
	struct node *p;

	p = new node();
	p->data = data;		//assign data in string to the data for node p
	/*if (top != 0)
	{
		p->next = top;
	}
	else
	{
		p->next = 0;
	}*/
	p->next = (top != 0) ? top : 0;	//set p->next to top if top of stack != 0
	top = p;			//set the top of the stack equal to p
}

/***********************************************************************************************************************************/
//Name: pop
//Precondition: the stack has not been popped
//Postcondition: the stack has been popped
//Decription: pops the stack
/**********************************************************************************************************************************/
string stack::pop()
{
	struct node *p;
	string value;

	if (top == 0)
	{
		return '\0';	//return null character
	}
	p = top;			//otherwise, set p to top
	value = p->data;	//assign the value in p to string value
	top = top->next;	//set the top to the next node

	return value;
}