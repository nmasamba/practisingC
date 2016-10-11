/**************************************************************************

Author: Nyasha Masamba

This C program takes in string input from the user and then asks them for
a position at which they want so start extracting the substring. After
that, the length of the required substring is determined, at which point
the required substring is extracted from the main string and printed out to
the user.

*************************************************************************/


#include <stdio.h>


int main() 
{
	char str[100], substr[100];
	int i=0, j=0, n, m;

	// obtain substring parameters
	printf(" \n Enter the main string: ");
	gets(str);
	printf(" \n At which position do you want to start the substring: ");
	scanf("%d", &m);
	printf(" \n Enter the length of the substring: ");
	scanf("%d", &n);

	i = m;

	// populate the substring using the given parameters
	while(str[i] != '\0' && n>0) {
		substr[j] = str[i];
		i++;
		j++;
		n--;
	}
	
	// append null terminator to end of substring array
	substr[j] = '\0';

	printf(" \n The substring is: ");
	puts(substr);

	return 0;

}
