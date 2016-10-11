/******************************************************

Author: Nyasha Masamba

This C program takes string input from the user via
standard I/O then prints out a reversed version of 
that string back to them.

*****************************************************/ 

#include <stdio.h>
#include <string.h>


int main() 
{
	char str[50], temp;
	int i=0, j=0;

	printf(" \n Enter something for reversal: ");
	gets(str);
	
	// determine length of the string and assign it to j
	j = strlen(str) - 1;

	/* start from end of string and swap the characters
	one by one using a temporary variable */ 
	while(i<j) {
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;	
		i++;
		j--;
	}

	printf(" \n The reversed string is: ");
	puts(str);

	return 0;
	
}
