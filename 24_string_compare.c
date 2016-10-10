/*********************************************************

Author: Nyasha Masamba

This C program compares two strings given by the user,
then prints out the result. It will also try to figure out
whether the given strings are equal in terms of length.

*********************************************************/



#include <stdio.h>
#include <string.h>

int main()
{
char str1[50], str2[50];
int i=0, len1=0, len2=0, same=0;

printf("\n Enter the first string for analysis: ");
gets(str1);
printf("\n Enter the second string for analysis: ");
gets(str2);

len1 = strlen(str1);
len2 = strlen(str2);

if(len1 == len2) {
	while(i<len1) {
		if(str1[i] == str2[i])
 			i++;
 		else break;
	}

	if(i==len1) {
		same=1;
		printf("\n Surprise! The two strings are equal. ");
	}
}

if(len1!=len2)
	printf("\n Surprise! The two strings are not even equal in size. ");

if(same == 0) {
	if(str1[i]>str2[i])
		printf("\n The first string is alphabetically greater than the second one. ");
	else if(str1[i]<str2[i])
		printf("\n The second string is alphabetically greater than the first one. ");
}

return 0;

}
