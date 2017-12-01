
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements interpolation search. Interpolation search, also known as extrapolation 
search, is a searching technique that finds a specified value in a sorted array. Interpolation search 
is similar to the binary search technique. However, the important difference
between the two techniques is that binary search always selects the middle value of the remaining
search space. It discards half of the values based on the comparison between the value found at the
estimated position and the value to be searched. But in interpolation search, interpolation is used to
find an item near the one being searched for, and then linear search is used to find the exact item.

Example I/O

$> Enter the number of elements in the array : 6

 Enter the elements : 1 4 90 255 4 12

 Enter the value to be searched : 4

 4 is found at position 1 

$> Enter the number of elements in the array : 6

 Enter the elements : 1 4 90 255 4 12

 Enter the value to be searched : 1

 1 is found at position 0

********************************************************************************************************/

#include <stdio.h>
#define MAX 20

int interpolation_search(int a[], int low, int high, int val)
{
	int mid;
	while(low <= high)
	{
		mid = low + (high - low)*((val - a[low]) / (a[high] - a[low]));
		if(val == a[mid])
			return mid;
		
		if(val < a[mid])
			high = mid - 1;
	 	else
			low = mid + 1;
	}
	return -1;
}

int main()
{
	int arr[MAX], i, n, val, pos;
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements : ");
	for(i = 0; i <n; i++)
		scanf("%d", &arr[i]);
	printf("\n Enter the value to be searched : ");
	scanf("%d", &val);
	pos = interpolation_search(arr, 0, n-1, val);
	if(pos == -1)
		printf("\n %d is not found in the array", val);
	else
		printf("\n %d is found at position %d", val, pos);

	return 0;
}






