/*******************************************************************

Author: Nyasha Masamba

This C program takes in string input from the user twice then appends
the last word entered with the first one. Hence, the first word to be
entered becomes the source string and the last word to be inputted 
becomes the destination string.

*******************************************************************/


#include <stdio.h>


int main() 
{
	char Dest_Str[100], Source_Str[100];
	int i=0, j=0;

	printf(" \n Enter the source string: ");
	gets(Source_Str);
	printf(" \n Great! Now enter the destination string: ");
	gets(Dest_Str);
	
	//count the number of characters in dest str first
	while(Dest_Str[i] != '\0')
		i++;

	// then whilst dest str exists we'll append source string to it
	while(Source_Str[j] != '\0') {
		Dest_Str[i] = Source_Str[j];
		i++;
		j++;
	}

	/* always add the null terminator to the end console input */
	Dest_Str[i] = '\0';
	
	printf(" \n After appending, the destination string is = ");
	puts(Dest_Str);

	return 0;


}
