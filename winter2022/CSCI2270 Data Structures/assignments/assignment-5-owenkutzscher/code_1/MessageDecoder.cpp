#include <iostream>
#include <cstdlib>
#include <iostream>
#include "MessageDecoder.hpp"
#include<array>

using namespace std;
# define SIZE 50

MessageDecoder::MessageDecoder()
{
	/*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
	head = NULL;
}

MessageDecoder::~MessageDecoder()
{
	// TODO
	// pop everythin off the stack and set head to nullptr
	head = nullptr;
}





bool MessageDecoder::isEmpty()
{
	/* finished. do not touch. */
    return (head == NULL);
}





// adds 1 item to the stack struct
void MessageDecoder::push(char chh)
{
	// TODO

	// appears to be logically correct...

	// first test is this one
	// making new MessageDecoder structs
	// adding them to a linked list
	// making the head point to the element we last added
	// making the first element set to nullptr
	
	
	
	Parser *current = new Parser();
	current -> ch = chh;
	current -> next = nullptr;



	if(head  == nullptr)	// case stack is empty
	{
		head = current;
	}
	else	// case stack has items
	{
		current -> next = head;
		head = current;
	}
}






// deletes 1 item from top of stack struct
void MessageDecoder::pop()
{   
	// TODO

	

	// if stack empty print "Stack empty, cannot pop an item." and return
	// else delete the top most item from the stack

	if(head == nullptr)		// case stack empty
	{
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	}
	else
	{
		Parser *current = head;
		Parser *next = current -> next;
		delete current;
		head = next;
	}
}




// returns a pointer to head of stack
Parser* MessageDecoder::peek()
{
	// TODO

	if(!head)	// if head == nullptr...
	{
		cout << "Stack empty. cannot peak" << endl;
		return NULL;
	}
	else
	{
		return head;
	}
}





void MessageDecoder::evaluate(char str[])
{
	// TODO

	// push all chars from str[] onto a stack
	// pop all elements from this stack storing chars between {} in an array
	// if {} has both brackets then print secret message
	// if not print "No secret message"

	
	
	
	
	
	
	bool brac1Exist = false;	// if '{' exists
	bool brac2Exist = false;	// if '}' exists
	int strSize = 0;
	//char chArray [70];
	char ch = ' ';

	// push all char int the stack
	while(str[strSize])	// checks if we are looking at an empty value in str[]
	{
		
		ch = str[strSize];
		if(ch == '{')
			brac1Exist = true;
		
		if(ch == '}')
			brac2Exist = true;

		push(ch);
		
		strSize++;

	}

		
	



	if(!(brac1Exist && brac2Exist))		// case both bracets not in the stack
	{
		cout << "No secret message" << endl;
		return;
	}


	Parser *current = head;
	bool beginDecoding = false;
	

	while(current)
	{	

		
		if(current -> ch == '{')
		{
			return;
		}



		if(beginDecoding == true)
		{
			cout << current -> ch;
		}

		

		if(current -> ch == '}')
		{
			beginDecoding = true;
		}

		
		
		

		current = current -> next;
	}
	
}
