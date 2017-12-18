
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements the radix sort algorithm. Radix sort is a linear sorting algorithm for 
integers and uses the concept of sorting names in alphabetical order. When we have a list of sorted names, 
the radix is 26 (or 26 buckets) because there are 26 letters in the English alphabet. So radix sort is 
also known as bucket sort. 

Observe that words are first sorted according to the first letter of the name. That is, 26 classes are used
to arrange the names, where the first class stores the names that begin with A, the second class
contains the names with B, and so on. During the second pass, names are grouped according to the second letter. 
After the second pass, names are sorted on the first two letters. This process is continued till the nth pass, 
where n is the length of the name with maximum number of letters. After every pass, all the names are collected 
in order of buckets. That is, first pick up the names in the first bucket that contains the names beginning with A. 
In the second pass, collect the names from the second bucket, and so on.
When radix sort is used on integers, sorting is done on each of the digits in the number. The
sorting procedure proceeds by sorting the least significant to the most significant digit. While
sorting the numbers, we have ten buckets, each for one digit (0, 1, 2, …, 9) and the number of
passes will depend on the length of the number having maximum number of digts.


Example I/O

$> Enter the number of elements in the array: 6

 Enter the elements of the array: 101 3 73636 325 09989 355

 The sorted array is: 
 3	 101	 325	 355	 9989	 73636

********************************************************************************************************/

#include <stdio.h>
#define size 10

int largest(int arr[], int n);
void radix_sort(int arr[], int n);
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
	radix_sort(arr, n);
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
		printf(" %d\t", arr[i]);
}

int largest(int arr[], int n)
{
	int large=arr[0], i;
	for(i=1;i<n;i++)
	{
	 	if(arr[i]>large)
	 	large = arr[i];
	}
	return large;
}

void radix_sort(int arr[], int n)
{
	int bucket[size][size], bucket_count[size];
	int i, j, k, remainder, NOP=0, divisor=1, large, pass;
	large = largest(arr, n);
	while(large>0)
	{
		NOP++;
		large/=size;
	}
	for(pass=0;pass<NOP;pass++) // Initialize the buckets
	{
		for(i=0;i<size;i++)
		bucket_count[i]=0;
		for(i=0;i<n;i++)
	 	{
			 // sort the numbers according to the digit at passth place
			remainder = (arr[i]/divisor)%size;
			 bucket[remainder][bucket_count[remainder]] = arr[i];
			bucket_count[remainder] += 1;
	 	}
		 // collect the numbers after PASS pass
		i=0;
		for(k=0;k<size;k++)
		{
			for(j=0;j<bucket_count[k];j++)
		 	{
		 		arr[i] = bucket[k][j];
				i++;
		 	}
		}
		divisor *= size;
	}
}









