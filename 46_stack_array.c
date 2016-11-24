/*************************************************************************

Adapted from Data Structures in C, 2nd Ed (Reema Thareja)
Edited by Nyasha Masamba

This C program creates a simple stack and provides several ways of 
manipulating it, including adding and deleting elements (which, in a stack, 
is only possible from the topmost part of the stack). A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. A menu to pick what the user 
wishes to do with the stack is also handy.

**************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Altering this value changes size of stack created
int st[MAX], top=-1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(int argc, char *argv[]) {
	int val, option;

	do
	{
		printf("\n ************* MAIN MENU ************");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		
		switch(option) {
			case 1:
				printf("\n Enter the number to be pushed on stack: ");
				scanf("%d", &val);
				push(st, val);
				break;
			case 2:
				val = pop(st);
				if(val != -1)
				printf("\n The value deleted from stack is: %d", val);
				break;
			case 3:
				val = peek(st);
				if(val != -1)
				printf("\n The value stored at top of stack is: %d", val);
				break;
			case 4:
				display(st);
				break;
		 }
	} while(option != 5);
	
	return 0;
}

void push(int st[], int val)
{
	if(top == MAX-1) {
		printf("\n STACK OVERFLOW");
	}
	else {
		top++;
		st[top] = val;
	}
}

int pop(int st[])
{
	int val;

	if(top == -1) {
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else {
		val = st[top];
		top--;
		return val;
	}
}

void display(int st[])
{
	int i;
	
	if(top == -1)
		printf("\n STACK IS EMPTY");
	else {
		for(i=top;i>=0;i--)
			printf("\n %d",st[i]);
		printf("\n"); // Added for formatting purposes
	}
}

int peek(int st[])
{
	if(top == -1) {
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else
		return (st[top]);
}

