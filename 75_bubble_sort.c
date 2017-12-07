

/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements bubble sort. Bubble sort is a very simple method that sorts the 
elements by repeatedly moving the largest element to the highest index position of the segment 
(in the case of arranging elements in ascending order). In bubble sorting, consecutive adjacent 
pairs of elements in the array are compared with each other. If the element at the lower index is 
greater than the element at the higher index, the two elements are interchanged so that the element 
is placed before the bigger one. This process will continue till the list of unsorted elements exhausts.
The complexity of bubble sort algorithm is O(n^2). 

If the array is already sorted, we would need to pass over all the elements at least once but we 
would not need to do a second pass. It would be good to detect when this is the case. We can have 
a flag that is set to TRUE when swapping is done at any point during the first pass, but it is set
to FALSE if no swapping is done during the first pass. If the array is already sorted, the algorithm 
simply exits after the first pass. This is an example of an optimised bubble sort algorithm, 
implemented as shown below:
void bubble_sort(int *arr, int n)
{
int i, j, temp, flag = 0;
    for(i=0; i<n; i++)
 {
       for(j=0; j<n–i–1; j++)
 {
          if(arr[j]>arr[j+1])
 {
             flag = 1;
             temp = arr[j+1];
             arr[j+1] = arr[j];
             arr[j] = temp;
          }
       }
      if(flag == 0) // array is sorted
         return;
   }
} 

Example I/O

$> Enter the number of elements in the array : 10

 Enter the elements: 1 102 2 101 3 23 12 23 13 22 21

 The array sorted in ascending order is :
1	2	3	12	13	22	23	23	101	102

********************************************************************************************************/

#include <stdio.h>

int main()
{
	int i, n, temp, j, arr[10];

	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr [i]);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
	 	{
			if(arr[j] > arr[j+1])
	 		{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\n The array sorted in ascending order is :\n");
		for(i=0;i<n;i++)
	printf("%d\t", arr[i]);
	
	return 0;
}