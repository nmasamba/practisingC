
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a binary search algorithm. Binary search is a searching algorithm that 
works efficiently with a sorted list. The mechanism
of binary search can be better understood by an analogy of a telephone directory. When we are
searching for a particular name in a directory, we first open the directory from the middle and
then decide whether to look for the name in the first part of the directory or in the second part of
the directory. Again, we open some page in the middle and the whole process is repeated until
we finally find the right name. The complexity of the binary search algorithm can be expressed as f(n).
The complexity of the algorithm is calculated depending on the number of comparisons that are made. 
In the binary search algorithm, we see that with each comparison, the size of the segment where search 
has to be made is reduced to half. Thus, we can say that, in order to locate a particular value in the 
array, the total number of comparisons that will be made is given as 
2^f(n) > n or f(n) = log n

Example I/O

Enter the number of elements in the array: 5

Enter the elements: 23 45 12 40 3

The sorted array is: 
3	12	23	40	45	

Enter the value you are searching for: 23

23 is present in the array at position 3


********************************************************************************************************/


#include <stdio.h>
#define size 10

int smallest(int arr[], int k, int n); 
void selection_sort(int arr[], int n); 

int main(int argc, char *argv[]) {
	int arr[size], num, i, n, beg, end, mid, found=0;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}

	selection_sort(arr, n); // Sort the array

	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf("%d\t", arr[i]);
	printf("\n\n Enter the value you are searching for: ");
	scanf("%d", &num);
	beg = 0, end = n-1;
	
	while(beg<=end)
	{
		mid = (beg + end)/2;
		if (arr[mid] == num)
		{
			printf("\n %d is present in the array at position %d", num, mid+1);
			found =1;
			break;
	 	}
		else if (arr[mid]>num)
			end = mid-1;
	 	else
			beg = mid+1;
	}
	if (beg > end && found == 0)
		printf("\n %d does not exist in the array", num);
	return 0;
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



