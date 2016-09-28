/***********************************************************************************************
Author: Nyasha Masamba

This C program searches for duplicates in an array. It traverses the user-defined array
elements, and alerts the user if it finds any duplicates. It will also let the user know
if it has not found any duplicates during the traversal process.

***********************************************************************************************/


#include <stdio.h>


int main() 
{
	int arr[20], i, n, j, flag = 0;

	printf(" \n Enter the size of the array: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		printf(" \n Enter array location [%d]: ", i);
		scanf("%d", &arr[i]);
	}
	
	// traverse the array comparing of the elements to each other
	// if elements are the same but in different positions, this means they are duplicates
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(arr[i] == arr[j] && i != j) {
				flag = 1;
				printf(" \n DUPLICATES FOUND AT LOCATIONS %d AND %d. \n ", i, j); 
			}
		}
	}
	
	// if flag has not been set to 1 during traversal, there are no duplicates in the array
	if(flag == 0) {
		printf(" \n No duplicates found. \n ");
	}

	return 0;

}
