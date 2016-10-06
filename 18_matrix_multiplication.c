/********************************************************************

Author: Nyasha Masamba

This C program takes in two user-specified matrices (up to dimension
5 by 5; tested only for square matrices) and performs matrix 
multiplication on them before printing out the resultant array to
the user. The concept of two-dimensional arrays is used.

********************************************************************/


#include <stdio.h>
#include <stdlib.h>

int main() 
{
	
	// 
	int i, j, k;
	int rows1, rows2, cols1, cols2, res_rows, res_cols;
	int mat1[5][5], mat2[5][5], res[5][5];
	
	// user specifies their array details
	printf(" \n Enter the number of rows in the first matrix: ");
	scanf("%d", &rows1);
	printf(" \n Enter the number of columns in the second matrix: ");
	scanf("%d", &cols1);
	printf(" \n Enter the number of rows in the second matrix: ");
	scanf("%d", &rows2);
	printf(" \n Enter the number of columns in the second matrix: ");
	scanf("%d", &cols2);

	// check if multiplication can be done on the user's arrays
	if(cols1 != rows2) {
		printf(" \n Cannot perform multiplication. Check dimensions of matrices. \n");
		exit(0);
	}

	// we'll use a combination of rows in matrix1 and columns in matrix2 for the results
	res_rows = rows1;
	res_cols = cols2;

	printf(" \n Enter the elements of the first matrix... ");
	for(i=0; i<rows1; i++) {
		for(j=0; j<cols1; j++) {
			scanf("%d", &mat1[i][j]);	
		}
	}

	printf(" \n Enter the elements of the second matrix... ");
	for(i=0; i<rows2; i++) {
		for(j=0; j<cols2; j++) {
			scanf("%d", &mat2[i][j]);	
		}
	}
	
	// multiply the two matcices
	for(i=0; i<res_rows; i++) {
		for(j=0; j<res_cols; j++) {
			res[i][j] = 0;
			for(k=0; k<res_cols; k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	// print out the resultant matrix to the user
	printf(" \n The elements of the product matrix are ");
	for(i=0; i<res_rows; i++) {
		printf(" \n ");
		for(j=0; j<res_cols; j++) {
			printf(" \t %d", res[i][j]);
		}
	}

	return 0;

}
