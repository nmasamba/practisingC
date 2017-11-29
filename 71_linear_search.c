
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a simple linear (or sequential) search algorithm. Linear search is a very 
simple method used for searching an array for a particular value. It works by comparing the value to 
be searched with every element of the array one by one in a sequence until a match is found. 
Linear search is mostly used to search an unordered list of elements (array in which data elements 
are not sorted). Linear search executes in O(n) time where n is the number of elements in the array.

Example I/O

Enter the number of elements in the array : 4

 Enter the elements: 1 3 5 7

 Enter the number that has to be searched : 3

 3 is found in the array at position= 2


********************************************************************************************************/




#include <stdio.h>
#include <stdlib.h>

#define size 20 // Added so the size of the array can be altered more easily

int main(int argc, char *argv[]) {
	int arr[size], num, i, n, found = 0, pos = -1;
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\n Enter the number that has to be searched : ");
	scanf("%d", &num);
	for(i=0;i<n;i++)
	{
		if(arr[i] == num)
		{
			found =1;
			pos=i;
			printf("\n %d is found in the array at position= %d", num,i+1);
			/* +1 added in line 23 so that it would display the number in
	 		the first place in the array as in position 1 instead of 0 */
			break;
	 	}
	}
	if (found == 0)
		printf("\n %d does not exist in the array", num);
	return 0;
}

