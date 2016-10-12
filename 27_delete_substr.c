/*********************************************************

Author: Nyasha Masamba

This C program accepts a main piece of text from the user,
then it also takes in a substring to be deleted from the 
main text. It then prints out the text with the 
substring deleted.

********************************************************/ 

#include <stdio.h>


int main() 
{
	char text[100], str[20], new_text[100];
	int i=0, j=0, k, n=0, copy_loop=0;

	printf(" \n Enter the main text: ");
	gets(text);
	printf(" Enter the substring to be deleted: ");
	gets(str);
	
	while(text[i] != '\0') {
		k=i;
		while(text[k]==str[j] && str[j]!='\0') {
			k++;
			j++;
		}

		if(str[j]=='\0') {
			copy_loop = k;
		}

		new_text[n]= text[copy_loop];
		i++;
		copy_loop++;
		n++;
	}

	new_text[n] = '\0';

	printf(" \n The new string is: ");
	puts(new_text);

	return 0;
	
}
