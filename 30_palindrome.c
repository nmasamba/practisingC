/***************************************************

Author: Nyasha Masamba

This C program takes in text as input and determines
if the text is a palindrome. A palindrome is a 
sequence of characters that reads the same whether 
backwards or forwards, such as kayak.

****************************************************/


#include <stdio.h>

int main()
{
	char str[100];
	int i = 0, j, length = 0;

	printf("\n Enter the string: ");
	gets(str);

	while(str[i] != '\0') {
 		length++;
		i++;
	}
	
	i=0;
	j = length - 1;

	while(i <= length/2) {
		if(str[i] == str[j]) {
 			i++;
			j--;
		}
 		else
 			break;
	}

	if(i>=j)
		printf("\n We have a PALINDROME here! ");
	else
		printf("\n This is NOT A PALINDROME ");

	return 0;
}
