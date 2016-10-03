/*************************************************************

Author: Nyasha Masamba

This C program takes in n number of array elements from the
user, then interchanges the biggest element with the 
smallest one. Again, certain assumptions have been made e.g.
all the user's values will be positive integers. The concept of
passing array elements and even entire arrays to functions is
utilised.

**************************************************************/

#include <stdio.h>

// function prototypes
void read_array(int my_array[], int);
void display_array(int my_array[], int);
void interchange(int arr[], int);
int find_biggest_pos(int my_array[10], int n);
int find_smallest_pos(int my_array[10], int n);


int main()
{
	int arr[10], n;

	printf(" \n Enter the size of the array: ");
	scanf("%d", &n);
	
	/* read in array values from the user
	and return entire array to calling function */
	read_array(arr, n);

	// entire array passed to called function for interchanging
	interchange(arr, n);

	// print out the interchanged array
	printf(" \n The new array is \n ");
	display_array(arr, n);

	return 0;

}

// array object passed back to calling function
void read_array(int my_array[10], int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf(" \n arr[%d] = ", i);
		scanf("%d", &my_array[i]);
	}

}

// entire array passed into called function
void interchange(int my_array[10], int n)
{
	int temp, big_pos, small_pos;
	
	// entire arrays passed to called functions
	// integers passed back to calling functions
	big_pos = find_biggest_pos(my_array, n);
	small_pos = find_smallest_pos(my_array, n);
	
	temp = my_array[big_pos];
	
	my_array[big_pos] = my_array[small_pos];
	my_array[small_pos] = temp;
	
}

int find_biggest_pos(int my_array[10], int n)
{
	int i, large=my_array[0], pos=0;

	for(int i=1; i<n; i++) {
		if(my_array[i] > large) {
			large = my_array[i];
			pos = i;
		}
	}	
	return pos;
}

int find_smallest_pos(int my_array[10], int n) 
{
	int i, small=my_array[0], pos=0;
	for(i=1; i<n; i++) {
		if(my_array[i] < small) {
			small = my_array[i];
			pos = i;
		}		
	}
 	return pos;
}

void display_array(int my_array[10], int n) 
{
	int i;
	for(i=0; i<n; i++) {
		printf(" \n arr[%d] = %d \n ", i, my_array[i]);
	}

}
