/*********************************************************************************
Author: Nyasha Masamba

The purpose of this C program is to perform typecasting from one data type (int)
to another (double). The input is obtained from the user through standard I/O and
operated on; subsequently the result of the computation is fed back to the user.
Although type conversion is done implicitly according to the C data type hierarchy
(e.g. an int can automatically b converted to a float), typecasting gives the 	
developer the ability to control and specify the explicit data type which should 
be used in computation.

********************************************************************************/

#include <stdio.h>

int main() {
	float f_num;
	int i_num;
	
	/* Obtain console integer input from the user */ 
	printf(" \n Enter any integer: ");
	scanf("%d", &i_num);
	
	/* Perform typecasting from int to double and print out result to user */
	f_num = (float) i_num;
	printf(" \n The floating point variant of %d is = %f \n ", i_num, f_num);
	
	return 0;

}
