
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements the quick sort algorithm developed by C. A. R. Hoare that makes O(n log n)
comparisons in the average case to sort an array of n elements. The quick sort algorithm works as follows:
1. Select an element pivot from the array elements.
2. Rearrange the elements in the array in such a way that all elements that are less than the pivot
appear before the pivot and all elements greater than the pivot element come after it (equal
values can go either way). After such a partitioning, the pivot is placed in its final position.
This is called the partition operation.
3. Recursively sort the two sub-arrays thus obtained. (One with sub-list of values smaller than
that of the pivot element and the other having higher value elements.)
NB: the main task is to find the pivot element, which will partition the array into two halves. 


Example I/O

$> Enter the number of elements in the array: 6

 Enter the elements of the array: 0909 664 22656 32 2 1

 The sorted array is: 
 1	 2	 32	 664	 909	 22656

********************************************************************************************************/

#include <stdio.h>
#define size 100

int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);

void main()
{
	int arr[size], i, n;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
	 	scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n-1);
	printf("\n The sorted array is: \n");

	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);

}

int partition(int a[], int beg, int end)
{
	int left, right, temp, loc, flag;
	loc = left = beg;
	right = end;
	flag = 0;
	while(flag != 1)
	{
		while((a[loc] <= a[right]) && (loc!=right))
			right--;
		if(loc==right)
	 		flag =1;
	 	else if(a[loc]>a[right])
	 	{
	 		 temp = a[loc];
			 a[loc] = a[right];
			 a[right] = temp;
			 loc = right;
	 	}
		if(flag!=1)
		{
			while((a[loc] >= a[left]) && (loc!=left))
				left++;
	 		if(loc==left)
				flag =1;
	 		else if(a[loc] <a[left])
	 		{
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
	 		}
	 	}
	}
	return loc;
}

void quick_sort(int a[], int beg, int end)
{
	int loc;
	if(beg<end)
	{
	 	loc = partition(a, beg, end);
		quick_sort(a, beg, loc-1);
		quick_sort(a, loc+1, end);
	}
}


