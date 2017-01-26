/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a recursive factorial function using the logic behind stacks.
Recursion occurs when a function calls itself. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/

#include <stdio.h>

int Fact(int);

int main()
{
	int num, val;
	
	printf("\n Enter the number: ");
	scanf("%d", &num);
	
	val = Fact(num);
	
	printf("\n Factorial of %d = %d", num, val);
	
	return 0;

}

int Fact(int n)
{
	// Base case
	if(n==1)
 		return 1;
 	// Recursive case
	else
		return (n * Fact(n-1));
}