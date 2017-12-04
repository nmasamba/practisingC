
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements jump search (or block search). When we have an already sorted list, 
then the other efficient algorithm to search for a value is jump search or block search.
For example, consider an array a[] = {1,2,3,4,5,6,7,8,9}. The length of the array is 9. 
If we have to find value 8 then following steps are performed using the jump search technique:
Step 1: First three elements are checked. Since 3 is smaller than 8, we will have to make a
jump ahead
Step 2: Next three elements are checked. Since 6 is smaller than 8, we will have to make a
jump ahead
Step 3: Next three elements are checked. Since 9 is greater than 8, the desired value lies
within the current boundary
Step 4: A linear search is now done to find the value in the array. 

Jump search works by jumping through the array with a step size (optimally chosen to be √n) to
find the interval of the value. Therefore, the complexity of the jump search algorithm can be given as O(√n).

Example I/O

$> Enter the number of elements in the array : 4

 Enter the elements : 2 1 30 344

 Enter the value to be searched : 12

 12 is not found in the array

********************************************************************************************************/

#include <stdio.h>
#include <math.h>

#define MAX 20
int jump_search(int a[], int low, int high, int val, int n)
{
	int step, i;
	step = sqrt(n);
	for(i=0;i<step;i++)
	{
		if(val < a[step])
			high = step - 1;
		else
			low = step + 1;
	}
	for(i=low;i<=high;i++)
	{
	    if(a[i]==val)
	 		return i;
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
	pos = jump_search(arr, 0, n-1, val, n);
	if(pos == -1)
		printf("\n %d is not found in the array", val);
	else
		printf("\n %d is found at position %d", val, pos);
	
	return 0;
}









