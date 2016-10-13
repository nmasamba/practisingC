/**********************************************************

Author: Nyasha Masamba

This C program takes in a main string text from the user.
It then takes a suggestion of a string they want to replace
in their main text, then it also takes in a suggestion of
what they would like to replace it with. Finally, it
performs some pattern matching, finds the target string
and replaces it, printing out the result.

**********************************************************/

#include <stdio.h>

int main()
{
	char str[200], text[20], new_str[200], rep_pat[100];
	int i=0, j, k, n=0, copy_loop=0, rep_index=0;

	printf("\n Enter the main string : ");
	gets(str);
	printf("\n Enter the pattern to be replaced: ");
	gets(text);
	printf("\n Enter the replacing pattern: ");
	gets(rep_pat);

	while(str[i]!='\0') {	
		j=0,k=i;
		while(str[k]==text[j] && text[j]!='\0') {
 			k++;
			j++;
		}
		if(text[j]=='\0') {
			copy_loop=k;
			while(rep_pat[rep_index] !='\0') {
				new_str[n] = rep_pat[rep_index];
				rep_index++;
 				n++;
			}
		}
	
		new_str[n] = str[copy_loop];
 		i++;
		copy_loop++;
 		n++;
	}
	
	new_str[n]='\0';
	printf("\n The new string is : ");
	puts(new_str);

	return 0;

}
