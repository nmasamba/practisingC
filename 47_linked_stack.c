/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program creates a stack from linked lists and provides several ways of 
manipulating it, including adding and deleting elements (which, in a stack, 
is only possible from the topmost part of the stack). This can also be achieved
using arrays but the size of the stack would need to be known in advance. A
linked stack allocates memory dynamically as stack size changes. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. A menu to pick what the user 
wishes to do with the stack is also handy.
**************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top = NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);

int main(int argc, char *argv[]) {
	int val, option;

	do
	{
		 printf("\n *****MAIN MENU*****");
		 printf("\n 1. PUSH");
		 printf("\n 2. POP");
		 printf("\n 3. PEEK");
		 printf("\n 4. DISPLAY");
		 printf("\n 5. EXIT");
		 printf("\n Enter your option: ");
		 scanf("%d", &option);

		 switch(option)
		 {
			 case 1:
				 printf("\n Enter the number to be pushed on stack: ");
				 scanf("%d", &val);
				 top = push(top, val);
				 break;
			 case 2:
				 top = pop(top);
				 break;
			 case 3:
				 val = peek(top);
				 if (val != -1)
				 	printf("\n The value at the top of stack is: %d", val);
				 else
				 	printf("\n STACK IS EMPTY");
				 break;
			 case 4:
				 top = display(top);
				 break;
		 }

	}while(option != 5);

	return 0;

}

struct stack *push(struct stack *top, int val)
{
	struct stack *ptr;
	ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr -> data = val;

	if(top == NULL)
	{
	 	ptr -> next = NULL;
	 	top = ptr;
	}
	else
	{
	 	ptr -> next = top;
	 	top = ptr;
	}

	return top;

}

struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	
	if(top == NULL)
		printf("\n STACK IS EMPTY");
	else
	{
		while(ptr != NULL)
		 {
		 	printf("\n %d", ptr -> data);
		 	ptr = ptr -> next;
		 }
	}

	return top;

}

struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if(top == NULL)
		printf("\n STACK UNDERFLOW");
	else
	{
		 top = top -> next;
		 printf("\n The value being deleted is: %d", ptr -> data);
		 free(ptr);
	}

	return top;

}

int peek(struct stack *top)
{
	if(top==NULL)
		return -1;
	else
		return top ->data;
}

