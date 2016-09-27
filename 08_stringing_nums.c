/*******************************************************************************
Author: Nyasha Masamba

This C program takes n elements (where n is specified by the user) and 
strings them together to produce a number using those digits. The last number
to be entered is given the most emphasis. An array data structure is utilised
to store the numbers which would have been input via the console.

*******************************************************************************/



#include <stdio.h>

// C library to enable us to perform mathematical calculations
#include <math.h>


int main() 
{

	int i, j, number = 0, digit[10], numofdigits;
	
	printf(" \n Enter the number of digits you wish to string together: ");
	scanf("%d", &numofdigits);
	
	for(i=0; i<numofdigits; i++) {
		printf(" \n Enter the digit at position %d: ", i+1);
		scanf("%d", &digit[i]);
	}
	
	// give emphasis to the number entered last by multiplying by powers of 10
	// pow is a C library function in the math.h library 
	j=0;
	while(j < numofdigits) {
		number = number + digit[j] * pow(10, j);
		j++;
	}

	printf(" \n The number is %d \n ", number);
	return 0;

}
