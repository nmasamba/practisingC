/***************************************************

Author: Nyasha Masamba

This C program accepts string input from a user. It 
then converts the input to upper case and prints it
back to the user, taking advantage of the fact that 
string characters are stored as hexadecimals and 
lower case letters are assigned numbers that are 32
places larger than their upper case forms.

***************************************************/


#include <stdio.h>


int main() 
{
	char str[100], upper_str[100];
	int i = 0;
	
	printf(" \n Enter string : ");
	gets(str);

	// subtract 32 to obtain upper case hex equivalent
	while(str[i] != '\0') {
		if(str[i]>='a' && str[i]<='z') 
			upper_str[i] = str[i] - 32;
		else
			// if already upper case, just append to new string array
			upper_str[i] = str[i];
		i++;
	}

	// assign null terminator when characters stop 
	upper_str[i] = '\0';
	
	printf(" \n The converted string is: ");
	puts(upper_str);

	return 0;


}
