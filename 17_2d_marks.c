/***********************************************************************

Author: Nyasha Masamba

This C program uses 2-dimensional arrays to store three marks for each
of 5 students. The students are represented by the rows whilst the
marks are represented by the columns. After all the marks have been
input, they are analysed by the program and the highest mark is printed
back to the teacher.

************************************************************************/


#include <stdio.h>

int calculate_max(int marks[5][3], int, int);

int main() 
{
	int marks[5][3], i, j, highest;
	
	for(i=0; i<5; i++) {
		printf(" \n Enter marks obtained by student number %d: ", i+1);
		for(j=0; j<3; j++) {
			printf(" \n marks[%d][%d] = ", i, j);
			scanf("%d", &marks[i][j]);
		}	
	}

	highest = calculate_max(marks, i, j);
	
	printf(" \n The highest mark obtained by the students was %d \n", highest);

	return 0;

}

int calculate_max(int marks[5][3], int i, int j) 
{
	int max_marks = 0;
	
	for(j=0; j<3; j++) {
		for(i=0; i<5; i++) {
			if (marks[i][j] > max_marks)
				max_marks = marks[i][j];
		}
	}

	return max_marks;
}
