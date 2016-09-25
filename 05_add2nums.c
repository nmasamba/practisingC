/*********************************************************************
Author: Nyasha Masamba

This C program accepts two integers from the user and adds them up.
However, rather than being a simple adding application, it is
representative of how good software should look like as it is divided
into seperate functions (abstraction), and each function carries out
a specific piece of the overall functionality. Furthermore, pointers
have been employed to achieve the functionality.
**********************************************************************/

#include <stdio.h>

int sum(int*, int*, int*);

int main() 
{

	int num1, num2, total;
	
	/* get user input */
	printf(" \n Enter the first integer: ");
	scanf("%d", &num1);
	printf(" \n Enter the second integer: ");
	scanf("%d", &num2);
	
	/* sum() function arguments are addresses in memory */
	sum(&num1, &num2, &total);
	
	/* print out the total */
	printf(" \n The total of the two numbers = %d \n ", total);

	return 0;

}

int sum(int *a, int *b, int *t) //function parameters are pointer variables 
{	
	// pointer variables hold memory addresses
	// dereferencing pointer variables enables pointer arithmetic to be performed
	*t = *a + *b;
	return *t;
}
