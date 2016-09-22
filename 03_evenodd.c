/********************************************************
Author: Nyasha Masamba 

This C program takes input from the user via the console,
and determines whether that (integer) input is an odd or
an even number. Moreover, it uses functional decomposition
to achieve this functionality.

*********************************************************/

#include <stdio.h>


int evenodd(int); //function declaration

int main() {
	int num, flag;

	printf(" \n Enter the number to be analysed: ");
	scanf("%d", &num);
	
	/* Function Call - evenodd() is the called function
	and main() is the calling function. */
	flag = evenodd(num);

	/* Operations after the compiler is done with 
	the evenodd() function and returned a value */
	if (flag == 0)
		printf(" \n The number is EVEN \n");
	else
		printf(" \n The number is ODD \n");
	return 0;
}

int evenodd(int a) //function definition = header + body 
{
	/* Function Body */
	if (a%2 == 0) return 0;
	else return 1;
}
