/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a recursive function to find a sequence of
x Fibonacci numbers as specified by the user, using the logic behind stacks.
Fibonacci numbers are a sequence of numbers where the current number is the 
sum of the previous 2 numbers that came before it.
Recursion occurs when a function calls itself. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/



#include <stdio.h>

int Fibonacci(int);

int main()
{
	int n, i = 0, res;
	printf("Enter the number of terms \n");
	scanf("%d",&n);
	printf("Fibonacci series \n");
	
	for(i = 0; i < n; i++ )
	{
	 	res = Fibonacci(i);
	 	printf("%d \t",res);
	}

	return 0;

}

int Fibonacci(int n)
{
	if ( n == 0 )
		return 0;
	else if ( n == 1 )
 		return 1;
	else
 		return ( Fibonacci(n-1) + Fibonacci(n-2) );

} 