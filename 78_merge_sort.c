
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements merge sort. Merge sort is a sorting algorithm that uses the divide, conquer, 
and combine algorithmic paradigm. Divide means partitioning the n-element array to be sorted into two 
sub-arrays of n/2 elements. If A is an array containing zero or one element, then it is already sorted. 
However, if there are more elements in the array, divide A into two sub-arrays, A1 and A2, each 
containing about half of the elements of A. Conquer means sorting the two sub-arrays recursively using 
merge sort. Combine means merging the two sorted sub-arrays of size n/2 to produce the sorted array of n
elements. The running time of merge sort in the average case and the worst case can be given as O(n log n). 
Although merge sort has an optimal time complexity, it needs an additional space of O(n)
for the temporary array TEMP.

Example I/O

$> Enter the number of elements in the array : 6

 Enter the elements of the array: -12 0 987 1 4 6

 The sorted array is: 
 -12	 0	 1	 4	 6	 987

********************************************************************************************************/


#include <stdio.h>
#define size 100

void merge(int a[], int, int, int);
void merge_sort(int a[],int, int);

void main()
{
	int arr[size], i, n;
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
	 	scanf("%d", &arr[i]);
	}
	merge_sort(arr, 0, n-1);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);
	
}

void merge(int arr[], int beg, int mid, int end)
{
	int i=beg, j=mid+1, index=beg, temp[size], k;
	
	while((i<=mid) && (j<=end))
	{
	 	if(arr[i] < arr[j])
	 	{
			temp[index] = arr[i];
			i++;
	 	}
	 	else
	 	{
			temp[index] = arr[j];
			j++;
	 	}
		index++;
	}

	if(i>mid)
	{
	 	while(j<=end)
	 	{
			temp[index] = arr[j];
			j++;
			index++;
	 	}
	}
	else
	{
	 	while(i<=mid)
	 	{
			temp[index] = arr[i];
			i++;
			index++;
	 	}
	}
	for(k=beg;k<index;k++)
		arr[k] = temp[k];
}

void merge_sort(int arr[], int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid = (beg+end)/2;
	 	merge_sort(arr, beg, mid);
		merge_sort(arr, mid+1, end);
	 	merge(arr, beg, mid, end);
	}
}



