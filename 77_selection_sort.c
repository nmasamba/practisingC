


/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements the selection sort algorithm. 

Consider an array ARR with N elements. 
Selection sort works as follows:
First find the smallest value in the array and place it in the first position. Then, find the second
smallest value in the array and place it in the second position. Repeat this procedure until the
entire array is sorted. 

Selection sort has quadratic complexity, i.e. O(n^2) but still offers performance advantages over other
more complex sorting algorithms. It is a sorting algorithm that is independent of the original order of 
elements in the array. Selection sort is generally used for sorting files with very large objects (records) 
and small keys. It is simple, easy to implement, useable on small datasets and is about 60% more 
efficient than bubble sort.

Example I/O

$> Enter the number of elements in the array: 5

 Enter the elements of the array: 23 44 8 71 1023

 The sorted array is: 
 8	 23	 44	 71	 1023

********************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

int smallest(int arr[], int k, int n);
void selection_sort(int arr[], int n);

void main(int argc, char *argv[]) {
	int arr[10], i, n;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
	 	scanf("%d", &arr[i]);
	}
	selection_sort(arr, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);
	}

int smallest(int arr[], int k, int n)
{
	int pos = k, small=arr[k], i;
	for(i=k+1;i<n;i++)
	{
	 	if(arr[i]< small)
	 	{
	 		small = arr[i];
	 		pos = i;
	 	}
	}
	return pos;
}

void selection_sort(int arr[],int n)
{
	int k, pos, temp;
	for(k=0;k<n;k++)
	{
 		pos = smallest(arr, k, n);
 		temp = arr[k];
 		arr[k] = arr[pos];
 		arr[pos] = temp;
	}
}





