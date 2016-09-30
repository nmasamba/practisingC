/****************************************************************************
Author: Nyasha Masamba

This C program takes in n elements from the user, in ascending order, and 
stores those elements in an array. It then gets input from the user who
inserts another element, and it looks through the array moving each current
array element to the right until it gets to an element which it is greater than.
At that point, it assigns the element to be inserted at the correct 
position and maintains the order in the array. NOTE: the program does
depend on the user to input their array elements in ascending order from the
start, otherwise it will not work as intended (i.e. the program does not
do the sorting).

******************************************************************************/

#include <stdio.h>


int main() 
{
	
	int i, n, j, val, arr[10];
	
	// get the elements from user in ascending order
	printf("Enter the number of elements in the sorted array: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf(" \n arr[%d] (enter elements from smallest to largest): ", i);
		scanf("%d", &arr[i]);
	}
	
	// ask the user for a number to insert in the array
	printf("Enter the number you want to insert into the array: ");
	scanf("%d", &val);

	/* loop through all array elements and move them to the right till
	you run into en element that is less than the one to be inserted */	
	for(i=0; i<n; i++) {
		if(arr[i] > val) {
			for(j=n-1; j>=i; j--) {
				arr[j+1] = arr[j];
			}
			arr[i] = val;
			break;
		}
	}
	n = n+1;
	
	// print out the new array (element by element) after insertion
	printf(" \n The sorted array after the insertion of %d is: ", val);
		for(i=0; i<n; i++)
			printf(" \n arr[%d] = %d \n ", i, arr[i]);
				
	return 0;
}
