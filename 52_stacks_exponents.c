/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a recursive function to find the result of 
one number to the power of another (exp) using the logic behind stacks.
Recursion occurs when a function calls itself. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/


#include <stdio.h>

int exp_rec(int, int);

int main()
{
	int num1, num2, res;
	
	printf("\n Enter the two numbers: ");
	scanf("%d %d", &num1, &num2);
	res = exp_rec(num1, num2);
	printf ("\n RESULT = %d", res);
	
	return 0;

}

int exp_rec(int x, int y)
{

if(y==0)
 	return 1;
else
 	return (x * exp_rec(x, y-1));

}