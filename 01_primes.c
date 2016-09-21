/***************************************************************
Author: Nyasha Masamba

This C program determines whether the number obtained from the
user (via the console) is a composite or prime number. In
mathematical terms, a composite number is a whole number that 
can be divided evenly by numbers other than 1 and itself. Whole
numbers above 1 are either composite or prime. An outcome will
be subsequently printed out to the console for the user based on
their input. Clever use of the for loop, a flag for odd numbers
and the break statement are used to come up with the functionality.

****************************************************************/ 


#include <stdio.h>


int main() {
	int flag = 0, i, num;
	
	/* Qualify the required input range and obtain input via standard I/O stream */
	printf(" \n Enter any natural number greater than 1: ");
	scanf("%d", &num);

	/* Composite numbers can only be greater than 1. Reject all other input  */
	if(num <= 1)
		printf(" \n The number you entered cannot be accepted for evaluation \n ");
	
	/* Use conditional looping to check whether the number is odd or even. All even numbers
	greater than 2 are composite numbers. Further checking needs to be done for odd numbers
	which leads to at least one more iteration through the loop  */
	for(i=2; i<=num/2; i++)
	{
		if(num%i == 0)
			{
				flag = 1;
				break;
			} 
	}
	if(flag == 1)
		printf(" \n %d is a composite number \n ", num);
	else
		printf(" \n %d is a prime number \n ", num);

	return 0;
			

}
