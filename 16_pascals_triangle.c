/***************************************************************************

Author: Nyasha Masamba

This C program introduces two-dimensional arrays, whereby an array declared as
arr[2][3] holds a 2 rows by 3 column structure. The program generates the
mathematical structure known as Pascal's Triangle, popular for solving higher
order polynomial equations (just the first 7 layers are generated, but the 
program can be extended to n layers as needed).

****************************************************************************/

#include <stdio.h>


int main() 
{
	/* initialise 2D array with 8 rows by columns so you don't run out 
	of memory. Initialise all elements as 0. */ 
	int arr[8][8] = {0};
	int row=2, col, i, j;

	// the first three individual elements will always be 1
	arr[0][0] = arr[1][0] = arr[1][1] = 1;

	while(row <= 7) {

		// every new row in the triangle starts with 1
		arr[row][0] = 1;
	
		// add together numbers from upper row
		for(col=1; col<=row; col++) {
			arr[row][col] = arr[row-1][col-1] + arr[row-1][col];
		}
		
		// add to row, move on to generate next row if row <= 7
		row++;
	}
	
	/* for loops to print out each element of the array. NOTE that you
	need to use two loops for this as the addresses of 2D array elements
	are stored in contiguous locations in memory */
	for(i=0; i<7; i++) {
		printf(" \n ");
		for(j=0; j<=i; j++) {
			printf(" \t %d", arr[i][j]);
		}	
	}
	
	return 0;


}
