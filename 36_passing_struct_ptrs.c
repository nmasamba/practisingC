/******************************************************************

Author: Nyasha Masamba

This C program demonstrates how to pass a pointer of a struct to
a function. Also note the use of malloc to allocate memory the 
size of the struct and to return a pointer to the beginning of 
the memory block.

******************************************************************/



#include <stdio.h>
#include <stdlib.h>

struct student
{
	int r_no;
	char name[20];
	char course[20];
	int fees;
};

// function prototype to receive passed struct pointer
void display (struct student *);

int main()
{

	struct student *ptr;

	// allocate block of memory the size of the struct
	ptr = (struct student *)malloc(sizeof(struct student));

	printf("\n Enter the data for the student ");
	printf("\n ROLL NO.: ");
	scanf("%d", &ptr->r_no);
	printf("\n NAME: ");
	gets(ptr->name);
	printf("\n COURSE: ");
	gets(ptr->course);
	printf("\n FEES: ");
	scanf("%d", &ptr->fees);
	
	display(ptr);
	
	return 0;

}

// function receiving struct pointer
void display(struct student *ptr)
{
	printf("\n DETAILS OF STUDENT");
	printf("\n ROLL NO. = %d", ptr->r_no);
	printf("\n NAME = %s", ptr->name);
	printf("\n COURSE = %s ", ptr->course);
	printf("\n FEES = %d", ptr->fees);
}
