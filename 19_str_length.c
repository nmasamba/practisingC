/*******************************************************************

Author: Nyasha Masamba

This C program takes a user-specified string and prints out the 
length of that string back to the user.

*******************************************************************/

#include <stdio.h>


int main() 
{

	char str[100];
	int i = 0, length;


	printf(" \n Please enter a string \n ");
	gets(str);

	while(str[i] != '\0') {
		i++;
	}

	length = i;

	printf(" \n The length of the string is: %d \n", length);

	return 0;



}
