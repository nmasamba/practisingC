/*****************************************************************
Author: Nyasha Pride Masamba

This C program introduces a very basic employment of the array
data structure. It accepts n user-defined numbers from the user (up to 20)
and stores them in an array, then subsequently prints the numbers
back to the user. It is important to note that all the elements
in an array must be of the same data type; and traversing over
an array in C is not carried out by a prescribed function; rather
we have to loop through the array to traverse it. Traversal is the
accessing of array elements one by one.

*****************************************************************/ 


#include <stdio.h>

int main() 
{
	
	// declare program variables and an array to hold 20 ints
	int i, n, arr[20];

	// get the required number of array elements from the user
	printf(" \n Enter the number of elements in the array: ");
	scanf("%d", &n);
	
	/* loop over the array to store the elements one by one,
		this is called traversal */
	for(i=0; i<n; i++) {
		printf(" \n arr[%d] = \n ", i);
		scanf("%d", &arr[i]);
	}
	
	// loop over the array to print the elements one by one
	printf(" \n The elements are: \n ");;
	for(i=0; i<n; i++){
		printf(" \t %d", arr[i]);
	}
	printf(" \n ");
	
	return 0;

}
