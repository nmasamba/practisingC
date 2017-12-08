

/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements insertion sort. The main idea behind insertion sort is that it inserts each 
item into its proper place in the final list. The array of values to be sorted is divided into two sets - 
one that stores sorted values and another that contains unsorted values. The sorting algorithm will 
proceed until there are elements in the unsorted set. Suppose there are n elements in the array. 
Initially, the element with index 0 (assuming LB =0) is in the sorted set. Rest of the elements are in 
the unsorted set. The first element of the unsorted partition has array index 1 (if LB = 0).
During each iteration of the algorithm, the first element in the unsorted set is picked up and
inserted into the correct position in the sorted set. For insertion sort, the best case occurs when 
the array is already sorted. In this case, the running time of the algorithm has a linear running time.
In both the average and the worst case, insertion sort has a quadratic running time.

Example I/O

$> Enter the number of elements in the array: 5

 Enter the elements of the array: 3 56 2 899 4

 The sorted array is: 
 2	 3	 4	 56	 899 

********************************************************************************************************/

#include <stdio.h>
#define size 5

void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for(i=1;i<n;i++)
	{
	 	temp = arr[i];
	 	j = i-1;
	 	while((temp < arr[j]) && (j>=0))
	 	{
	 		arr[j+1] = arr[j];
			j--;
	 	}
	 	arr[j+1] = temp;
	}
}

int main()
{
	int arr[size], i, n;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
	 	scanf("%d", &arr[i]);
	}
	insertion_sort(arr, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);

	return 0;

}