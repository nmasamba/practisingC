/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a recursive function to solve the Towers of Hanoi
problem. The Towers of Hanoi is one of the main applications of recursion. 
It says, ‘if you can solve n–1 cases, then you can easily solve the nth case’.
In the simple 3-ring case, the problem is to move all these rings from 
pole A to pole C while maintaining the same order. The main issue is that 
the smaller disk must always come above the larger disk. 
Recursion occurs when a function calls itself. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/



#include <stdio.h>

void move(int, char, char, char);

int main()
{
	int n;
	printf("\n Enter the number of rings: ");
	scanf("%d", &n);
	move(n,'A', 'C', 'B');
	
	return 0;

}

void move(int n, char source, char dest, char spare)
{
	if (n==1)
	 	printf("\n Move from %c to %c",source,dest);
	else
	{
	 	move(n-1,source,spare,dest);
	 	move(1,source,dest,spare);
	 	move(n-1,spare,dest,source);
	}
}