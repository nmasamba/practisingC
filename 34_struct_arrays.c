/*****************************************************

Author: Nyasha Masamba

This C program stores details of up to 50 students in
an array of structures. It then allows the user to
choose a student and edit their details.

****************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	struct student {
 		int roll_no;
	 	char name[80];
 		int fees;
	 	char DOB[80];
	};

	struct student stud[50];
	int n, i, num, new_rolno, new_fees;
	char new_DOB[80], new_name[80];
	
	printf("\n Enter the number of students : ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++) {
	 	printf("\n Enter the name : ");
                gets(stud[i].name); 
		printf("\n Enter the roll number : ");
	 	scanf("%d", &stud[i].roll_no);
	 	printf("\n Enter the fees : ");
	 	scanf("%d",&stud[i].fees);
	 	printf("\n Enter the DOB : ");
	 	gets(stud[i].DOB);
	}

	for(i=0;i<n;i++) {
	 	 printf("\n ********DETAILS OF STUDENT %d*******", i+1);
	 	 printf("\n ROLL No. = %d", stud[i].roll_no);
	 	 printf("\n NAME = %s", stud[i].name);
	 	 printf("\n FEES = %d", stud[i].fees);
	 	 printf("\n DOB = %s", stud[i].DOB);
	}

	printf("\n Enter the student number whose record has to be edited : ");
	scanf("%d", &num);
	num = num - 1;
	printf("\n Enter the new name : ");
        gets(new_name);
	printf("\n Enter the new roll number : ");
	scanf("%d", &new_rolno);
	printf("\n Enter the new fees : ");
	scanf("%d", &new_fees);
	printf("\n Enter the new DOB : ");
	gets(new_DOB);
	stud[num].roll_no = new_rolno;
	strcpy(stud[num].name, new_name);
	stud[num].fees = new_fees;
	strcpy (stud[num].DOB, new_DOB);
	
	for(i=0;i<n;i++) {
		printf("\n **************** DETAILS OF STUDENT %d **************", i+1);
	 	printf("\n ROLL No. = %d", stud[i].roll_no);
	 	printf("\n NAME = %s", stud[i].name);
	 	printf("\n FEES = %d", stud[i].fees);
	 	printf("\n DOB = %s", stud[i].DOB);
	}
	
	return 0;

}
