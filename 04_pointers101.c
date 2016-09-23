/*************************************************************************************************************
Author: Nyasha Masamba

This C program illustrates the use of pointers as variables which contain the address of another variable
 in memory. In other words, a pointer points to the location of a data item, such as a variable or an array
element. Pointers are frequently used in C. In the program, we declare a pointer variable and tell the compiler
that the pointer will contain the address of an integer variable. Next, we assign the value of an integer 
variable called num to the pointer. The user then provides an integer value to assign to num, then subsequently
that value is printed out to them, along with the value's address in memory.

***************************************************************************************************************/ 


#include <stdio.h>

int main() 
{
	/* declare pointer variable */
	int num, *pnum;

	/* assign the address of num to the pointer variable */
	pnum = &num;

	/* get input from user to store in memory */
	printf(" \n Enter a number for storage in memory: ");
	scanf("%d", &num);

	/* print the value and its address in memory back to the user, using the pointer variable */
	printf(" \n The number you entered was %d, which was stored at memory location %p \n", *pnum, &num);

	return 0;

}
