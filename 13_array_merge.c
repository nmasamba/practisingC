/**********************************************************************

Author: Nyasha Pride Masamba

This C program merges two user-specified sorted arrays together. It
does assume that input from the user is already sorted, and it 
compares one element of each array to another. It then prints out 
the resulting merged array to the user.

*********************************************************************/

#include <stdio.h>


int main() 
{
	
	// declare arrays and variables
	int arr1[10], arr2[10], arr3[20];
	int i, n1, n2, m, index=0;
	int index_first = 0, index_second = 0;
	
	// user creates arr1 and arr2, both sorted arrays of length <=10
	printf(" \n Enter the number of elements you want in arr1: ");
	scanf("%d", &n1);
	printf(" \n Enter the elements of arr1... \n ");
	for(i=0; i<n1; i++) {
		printf(" \n arr1[%d]: ", i);
		scanf("%d", &arr1[i]);
	}

	printf(" \n Enter the number of elements you want in arr2: ");
        scanf("%d", &n2);
        printf(" \n Enter the elements of arr2... \n ");
        for(i=0; i<n2; i++) {
                printf(" \n arr2[%d]: ", i);
                scanf("%d", &arr2[i]);
        }
	
	// establish number of elements in the merged array
	m = n1+n2;
	
	// compare elements between arr1 and arr2 and increment arr3 index when done
	while(index_first < n1 && index_second < n2) {
		if(arr1[index_first] < arr2[index_second]) {
			arr3[index] = arr1[index_first];
			index_first++;
		}
		else {
			arr3[index] = arr2[index_second];
			index_second++;
		}
		index++;
	}

	// append arr3 if arr1's elements are finished but arr2 still has elements 
	if(index_first == n1) {
		while(index_second < n2) {
			arr3[index] = arr2[index_second];
			index_second++;
			index++;
		}
	}

	// append arr3 if arr2's elements are finished but arr1 still has elements
	if(index_second == n2) {
		while(index_first < n1) {
			arr3[index] = arr1[index_first];
			index_first++;
			index++;
		}
	}
	
	// print out merged array
	printf(" \n The merged array is ");
	for(i=0; i<m; i++)
		printf(" \t %d \t ", arr3[i]);
		
	return 0;
}
