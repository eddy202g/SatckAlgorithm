#include "stdafx.h"
#include <iostream>
const int stackSize = 20; // Set constant integer for comparison
using namespace std;

// This is a struct, which enables us to create an instance of a struct
// as many times as we want. The struct contains an array decleration
// and thr integer "top" has been initialised as -1, which gives us
// the starting position of the array.
struct newStack
{
	int stack[stackSize];
	int top = -1;
};

// Function stubs
void push(struct newStack*, int);
int pop(struct newStack*);
bool isEmpty(struct newStack);
bool isFull(struct newStack);
void showStack(struct newStack);

// Main function. This function contains the scaffold which sets up the 
// functionality of the program. It initialises an integer to act as a counter, then
// shows the top value of the stack, which should be -1, as the stack should be empty.
// It then uses a for loop to push values into the stack, upto the maximum space
// of the stack, then shows the new result of the top of the stack.
// Then it goes on to pop the elements of the array back out, and shows us the new value
// of the top, which should be 0 as the stack is now empty.
int main()
{
	int i;

	struct newStack theStack;

	cout << "Testing Stack\n\n";

	showStack(theStack);

	cout << "\nTest Push\n\n";
	for (i = 0; i < stackSize; i++)
	{
		push(&theStack, i);
	}

	showStack(theStack);

	cout << "\nTest Pop\n\n";
	for (i = 0; i < stackSize - 1; i++)
	{
		cout << (pop(&theStack)) << "\n";
	}

	cout << "Value of Top: " << theStack.top;

	cin.ignore();
	cin.get();
	return 0;
}

// This function sets a pointer to the stack, and then increments the top
// element of the stack by one. It takes data from a for loop and pushes it onto
// the stack
void push(struct newStack * theStack, int data)
{
	theStack->top++;
	theStack->stack[theStack->top] = data;
	return;
}

// This function sets a pointer to the stack, then decrements the top element
// of the stack. 
int pop(struct newStack * theStack)
{
	theStack->top--;
	return theStack->stack[theStack->top];
}

// This function checks if the stack is empty, if its empty, it returns
// the boolean value true. If the stack has onr or more elements it returns false
bool isEmpty(struct newStack theStack)
{
	if (theStack.top <= 0)
		return true;
	else
		return false;
}

// This function checks if the stack is full, if its full, it returns
// the boolean value false. If the stack has one or more elements it returns true
bool isFull(struct newStack theStack)
{
	if (theStack.top < stackSize)
		return false;
	else
		return true;
}

// This function prints out the values held in the stack. It uses a for loop
// to iterate through the stack, printing out the positions and values of each item.
void showStack(struct newStack theStack)
{
	int i;
	cout << "Value of Top: " << theStack.top << "\n";
	for (i = 0; i < theStack.top + 1; i++)
	{
		printf("Position %3d Value %5d \n", i, theStack.stack[i]);
	}

}
