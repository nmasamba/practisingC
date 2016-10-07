/*****************************************************************

Author: Nyasha Masamba

This C program simply takes in elements for a 3-dimensional array
via the console. It then prints the resulting 2x2x2 matrix back to
the user, in row major order style.

*****************************************************************/


#include <stdio.h>


int main() 
{
	int i, j, k;
	int myarray[2][2][2];

	printf(" \n Enter the elements of a 2 x 2 x 2 matrix \n");
	for(i=0; i<2; i++) {
i		for(j=0; j<2; j++) {
			for(k=0; k<2; k++) {
				scanf("%d", &myarray[i][j][k]);
			}
		}
	}	

	printf(" \n Your matrix is: ");
	for(i=0; i<2; i++) {
		printf("\n");
		for(j=0; j<2; j++) {
			printf("\n");
			for(k=0; k<2; k++) {
				printf("\t array[%d][%d][%d] = %d", i, j, k, myarray[i][j][k]);	
			}	
		}	
	}

	return 0;


}
