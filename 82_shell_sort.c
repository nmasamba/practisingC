
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements shell sort. Shell sort, invented by Donald Shell in 1959, is a sorting 
algorithm that is a generalization of insertion sort. Shell sort is considered an improvement over 
insertion sort as it compares elements separated by a gap of several positions. This enables the element 
to take bigger steps towards its expected position. In Shell sort, elements are sorted in multiple passes 
and in each pass, data are taken with smaller and smaller gap sizes. However, the last step of shell sort 
is a plain insertion sort. But by the time we reach the last step, the elements are already 
‘almost sorted’, and hence it provides good performance.

********************************************************************************************************/

#include <stdio.h>

void main() 
{
	int arr[10]={-1};
	int i, j, n, flag = 1, gap_size, temp;
	printf("\n Enter the number of elements in the array: ");
	scanf("%d", &n);
	printf("\n Enter %d numbers: ",n); // n was added
	for(i=0;i<n;i++)
	 	scanf("%d", &arr[i]);
	gap_size = n;
	while(flag == 1 || gap_size > 1)
	{
	 	flag = 0;
	 	gap_size = (gap_size + 1) / 2;
	 	for(i=0; i< (n - gap_size); i++)
 		{
	 	 	if( arr[i+gap_size] < arr[i])
 			{
	 	 	 	temp = arr[i+gap_size];
	 	 	 	arr[i+gap_size] = arr[i];
	 	 	 	arr[i] = temp;
	 	 	 	flag = 0;
 			}
 		}
	}
	printf("\n The sorted array is: \n");
	for(i=0;i<n;i++)
	{
	 	printf(" %d\t", arr[i]);
	}
}




