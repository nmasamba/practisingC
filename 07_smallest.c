/**************************************************************************************
Author: Nyasha Masamba

This C program accepts a user-defined number of array elements via the standard I/O
console. It then stores those numbers in array structure and analyses them to determine
 which of them is the smallest one. The resulting smallest number in the array element
is printed to the user, along with its index/subscript position in the array.

**************************************************************************************/


#include <stdio.h>


int main() 
{
	// declare program variables and the array
	int i, n, pos, smallest, arr[20];

	// find out how many numbers the user wishes to compare
	printf(" \n Enter the number of elements you wish to find the smallest of: ");
	scanf("%d", &n);
	
	// accept the elements one by one from the user for comparison
	for(i=0; i<n; i++) {
		printf(" \n Enter element %d: ", i+1);
		scanf("%d", &arr[i]); 
	}

	/* start at the first element in the array and compare the elements one by one,
	keeping the current smallest one in memory; if a smaller number comes up, store
	that number and its position instead */
	smallest = arr[0];
	pos = 0;
	for(i=0; i<n; i++) {
		if(arr[i] < smallest) {
			smallest = arr[i];
			pos = i;
		}
	}
	
	// print out the findings to the user
	printf(" \n The smallest element is %d \n ", smallest);
	printf(" \n The position of the smallest element in the array is %d \n ", pos);

	return 0;
}
