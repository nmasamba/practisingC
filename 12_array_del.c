/*******************************************************************************

Author: Nyasha Pride Masamba

This C program accepts a specified number of elements from the user via the
console. The elements are stored in an array data structure. The program then
asks the user to select where to delete an element, then deletes the element at
at that array position. Conecpts such as array traversal and array manipulation,
as previously learnt, are utilised throughout.

********************************************************************************/

#include <stdio.h>


int main() 
	{

	int i, j, k, n, pos, arr[10];
	
	// user specifies array elements
	printf(" \n How many elements do you want in the array?: ");
	scanf("%d", &n);
	
	// creating array, getting elements via standard I/O
	for(i=0; i<n; i++) {
		printf(" \n Enter arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	
	// find out the array position to be disposed of
	printf(" \n You want to delete the element from position arr[?]: ");
	scanf("%d", &pos);
	
	// delete element by moving every element after it to the left
	for(j=pos; j<n-1; j++) { 
		arr[j] = arr[j+1];
	}
	
	// reduce number of array elements by 1
	n--;

	// print out the modified array to user for confirmation
	printf(" \n Your array after deletion is \n ");
	for(k=0; k<n; k++) {
		printf(" \n arr[%d] = %d \n ", k, arr[k]);
	}

	return 0;
}
