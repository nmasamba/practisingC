
/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a recursive function to find the
greatest common divisor (GCD) of two numbers using the logic behind stacks.
Recursion occurs when a function calls itself. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/


#include <stdio.h>

int GCD(int, int);

int main()
{
	int num1, num2, res;
	
	printf("\n Enter the two numbers: ");
	scanf("%d %d", &num1, &num2);
	res = GCD(num1, num2);
	printf("\n GCD of %d and %d = %d", num1, num2, res);
	
	return 0;

}

int GCD(int x, int y)
{
	int rem;
	
	rem = x%y;

	if(rem==0)
 		return y;
	else
 		return (GCD(y, rem));

}