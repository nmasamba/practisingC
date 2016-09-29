/**********************************************************************

Author: Nyasha Masamba

This C program inserts a new element into an existing array, at an
array position specified by the user. After saving the initial values
into an array, it asks the user for a new value to insert and the 
position at which they would like to insert it. It then iterates
through the array positions, moving each item to the right until it 
finds the required position and then it does insertion. We assume that
the array is already full so we need to increase the length of the
array by one more element in order to correctly reference the array
indices and print the final array out to the user.

***********************************************************************/

#include <stdio.h>


int main() 
{
	
	int i, n, val, pos, arr[10];

	printf(" \n Enter the number of elements in the array: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf(" \n element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	// get a number to insert and the position at which to insert that number into array
	printf(" \n Enter the number to be inserted: ");
	scanf("%d", &val);
	printf(" \n To be inserted at position: ");
	scanf("%d", &pos);
	
	// move each array element to the right until the required position has been found
	for(i=n-1; i>=pos; i--) {
		arr[i+1] = arr[i];
	}
	
	// assign the value to be inserted to its new position
	arr[pos] = val;

	// increment the array length by 1 as we have inserted one more element into array
	n = n+1;

	// reference each array by its subscript and print out the final elements to user
	printf(" \n The array after insertion of %d is: ", val);
		for(i=0; i<n; i++)
			printf(" \n arr[%d] = %d \n", i, arr[i]);

	return 0;
	

}
