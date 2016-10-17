/***************************************************

Author: Nyasha Masamba

This C program accepts two strings from the user
and concatenates them. Pointers are used to achieve
the functionality.

**************************************************/


#include <stdio.h>

int main()
{
	char str1[100], str2[100], copy_str[200];
	char *pstr1, *pstr2, *pcopy_str;

	pstr1 = str1;
	pstr2 = str2;
	pcopy_str = copy_str;

	printf("\n Enter the first string: ");
	gets(str1);
	printf("\n Enter the second string: ");
	gets(str2);

	while(*pstr1 != '\0') {
		*pcopy_str = *pstr1;
		pcopy_str++, pstr1++;
	}

	while(*pstr2 != '\0') {
		*pcopy_str = *pstr2;
		pcopy_str++, pstr2++;
	}

	*pcopy_str = '\0';

	printf("\n The concatenated text is: ");
	while(*pcopy_str != '\0') {
		printf("%c", *pcopy_str);
		puts(pcopy_str);
	}

	return 0;

}
