/******************************************************************************************

Author: Nyasha Pride Masamba

The purpose of this C program is to emphasise the point that the concept of the array is
bound to the concept of the pointer. The array name points to the starting address of the
array in memory (base address), which is pretty much the first element of the array; and which also 
happens to be similar in nature to a pointer. The program below prints out all three
addresses. Compare them to understand what is really happening underneath the hood.

******************************************************************************************/

#include <stdio.h>


int main() 
{
	int arr[] = { 2, 4, 6, 8, 10};

	printf(" \n The address of the array is \t %p \t %p \t %p \n ", arr, &arr, &arr[0]);

	return 0;

}
