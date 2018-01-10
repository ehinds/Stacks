/************************************************************************************************************************
Name: Eric Hinds                             Z#: Z23134823
Course: Data Structures (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  3/13/2017                    Due Time: 11:59 p.m.
Total Points: 25
Assignment 5: infix.cpp

Description:  Using a singly linked list stack, this program will receive an input in the form of a postfix and 
return an output in the form of an infix. Has several checks for errors to ensure proper output such as too many operators,
too many operands, not a proper input, empty strings, single strings, and allows for spaces.

The program is split into 3 files: A header file, a cpp file for the functions of call_class, and the test driver.
*************************************************************************************************************************/

#include <iostream>	  
#include <string> 
#include <vector>
#include "stack.h"

using namespace std;

int main()
{
	
	stack originalStack;
	string postfix, infix, operand1, operand2, exp, choice;

	do
	{
		cout << "Please enter a postfix expression: " << endl;	//request an input
		getline(cin, postfix);								//obtain input
		int error = 0, operands = 0, operators = 0;		//reset variables everytime new input is received
		if (postfix.empty())							//if empty, return empty string
		{
			infix = "";
		}
		else if (postfix.length() == 1 && postfix != " " && (postfix == "+" || postfix == "-" || postfix == "/" || postfix == "*"))
		{
			infix = "Too many operators, not enough operands.\n";	//if string only has one character and it is an operator, skip loop and write this
		}
		else if (postfix.length() == 1 && isalnum(postfix[0]))		//if the string has only one character and is an operand
		{
			infix = "(" + postfix + ")\n";		//add parenthesis and print the operand
		}
		else if (postfix.length() == 1 && !isalnum(postfix[0]) && postfix != " ")	//if string is not alphanumeric or operator
		{
			infix = "ERROR: Please only use +, -, /, *, alphabetic values, or numbers.\n";	//request proper input
		}
		else
		{
			for (unsigned int i = 0; i < postfix.length(); i++)	//loop through the length of the string
			{
				string c = postfix.substr(i, 1);
				if (c == "+" || c == "-" || c == "*" || c == "/")	//if operator is found
				{
					if (originalStack.getTop() != "\0")	//if top of stack is not null
					{
						operand2 = originalStack.pop();	//pop the first operand and retrieve it from the stack
						if (originalStack.getTop() != "\0")	//if top of stack is still not null
						{
							operand1 = originalStack.pop();	//pop the second operand and retrieve it from the stack
							exp = "(" + operand1 + " " + c + " " + operand2 + ")";	//add paranthesis arond both operands with the operator between them
							originalStack.push(exp);	//continue pushing the stack
							operators += 1;		//flag to indicate number of operators
						}
						else
						{
							infix = "Too many operators and not enough operands.\n";	//top of stack is null, return error
							error = 1;	//set error flag
							break;
						}
					}
					else
					{
						infix = "Too many operators and not enough operands.\n";	//top of stack is null, return error
						error = 1;	//set error flag
						break;
					}
				}
				else if (c == " ")
				{
					; //string character is blank space but not an empty string, skip the space
				}
				else if (!isalnum(c[0]) && c != " ")	//string is neither an operand (alphanumeric) nor a blank space, nor an operator
				{
					infix = "ERROR: Please only use +, -, /, *, alphabetic values, or numbers.\n";	//request proper input
					error = 1;		//flag as error to avoid printing null stack values
					break;
				}
				else
				{
					originalStack.push(c);	//all other conditions aside, this must be an operand, push the stack
					operands += 1;		//flag to indicate number of operands
				}
			}
			if ((operands != (operators + 1)) && error == 0)	//loop is done, if there is no error found check valid operands
			{
				infix = "Too many operands and not enough operators.\n";	//too many operands, error
				error = 1;		//flag as error
			}
			else if (error == 0)		//no recorded errors found, store stack results
			{
				infix = originalStack.pop();	//assign the final stack results into the infix string
			}			
		}
		cout << "\nThe infix expression is" << endl << infix << endl;	//print the results
		cout << "Would you like to convert another? (y/n): ";	//ask if they want to do another conversion
		cin >> choice;	
		cin.ignore();	//ignore answer to avoid interference with next input
		cout << endl;
	} while (choice == "y" || choice == "Y");	//if choice is not yes, end the loop

	return 0;
}