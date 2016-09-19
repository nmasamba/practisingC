/***********************************************************************
Author: Nyasha Masamba

The purpose of this C program is to decide whether an integer entered by 
the user was positive, negative or zero. It uses control flow branching
to determine which outcome to print to the console. If the number is 
neither positive nor negative, it is assumed to be zero. Note, however,
that this is not programed explicitly, but rather it is implicit due to
the mathematical fact that if an integer is neither greater than or less
than zero, then that number must be zero. The if-else-if statement in C
helps us achieve this three-part branching outcome.

***********************************************************************/


#include <stdio.h>

int main() {
	int userNum;
	
	/* Get user input through the console */
	printf(" \n Please enter an integer number: ");
	scanf("%d", &userNum);

	/* Control flow using the if-else-if construct determines whether 
	the integer input from the user is positive, negative or zero */
	if (userNum < 0) 
		printf(" \n The number you entered was negative. \n ");

	else if (userNum > 0)
		printf(" \n The number you entered was positive. \n ");

	else
		printf(" \n You must have entered 0. How lazy. \n ");

	return 0;

}
