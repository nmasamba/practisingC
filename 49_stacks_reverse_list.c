/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program reverses a list of elements in an array using a stack.
It takes in successive numbers and prints them reversed. A stack is a linear 
first-in-first-out (FIFO) structure, typically used when the order of
computation is important e.g for function calls, programs maintain a call
stack to track function calling and execution. 
**************************************************************************/



#include <stdio.h>

int stk[10];
int top= -1;

int pop();
void push(int);

int main()
{
	int val, n, i,
	arr[10];
	
	printf("\n Enter the number of elements in the array : ");
	scanf("%d", &n);
	printf("\n Enter the elements of the array : ");
	for(i=0;i<n;i++)
	 	scanf("%d", &arr[i]);
	for(i=0;i<n;i++)
	 	push(arr[i]);
	for(i=0;i<n;i++)
	{
	 	val = pop();
	 	arr[i] = val;
	}

	printf("\n The reversed array is : ");
	for(i=0;i<n;i++)
	 	printf("\n %d", arr[i]);
	
	return 0;
}

void push(int val)
{
	stk[++top] = val;
}

int pop()
{
	return(stk[top--]);
}