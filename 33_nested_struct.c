/**********************************************************

Author: Nyasha Masamba

This C program uses a nested struct to store and print
a student's details.

**********************************************************/


#include <stdio.h>

int main() 
{
	struct DOB {
		int day;
		int month;
		int year;
	};

	struct student {
		int roll_no;
		char name[100];
		float fees;
		struct DOB date; // nested structure here
	};
	
	struct student stud1;

	printf(" \n Enter student's name: ");
        gets(stud1.name);
	printf(" \n Enter the roll number: ");
	scanf("%d", &stud1.roll_no);
	printf(" \n Enter student's fees: ");
	scanf("%f", &stud1.fees);
	printf(" \n Enter the DOB(dd mm yyyy): ");
	scanf("%d %d %d", &stud1.date.day, &stud1.date.month, &stud1.date.year);

	printf("\n ******************************* STUDENT DETAILS ******************************** ");
	printf(" \n  ROLL NUMBER = %d", stud1.roll_no);
	printf(" \n STUDENT NAME = %s", stud1.name);
	printf(" \n STUDENT FEES = %.2f", stud1.fees);
	printf(" \n STUDENT'S DOB = %d-%d-%d", stud1.date.day, stud1.date.month, stud1.date.year);

	return 0;

}
