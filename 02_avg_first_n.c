/*****************************************************************************
Author: Nyasha Masamba

This C program calculates the average of the first n numbers, where n is any
integer entered into the console by the user on being prompted. To obtain the
average, the first n numbers are summed up and then the sum is divided by the
number of observations (n) to obtain an arithmetic mean. Both the sum and the
average are then printed out to the console for the user's benefit. Note the 
use of the do-while loop, which executes the code block within the loop at 
least once before evaluating whether the looping condition is true or false.
Other looping constructs such as the while loop would have also worked, albeit
with slightly different execution in places.

******************************************************************************/



#include <stdio.h>

int main() {
	int n, i = 0, total = 0;
	double avg;

	printf(" \n Enter the value of n: ");
	scanf("%d", &n);
	
	/* Conditional looping to go through each number up to n and add it
	to the running total */
	do
	{
		total += i;
		i++;
	} while (i<=n);
	
	/* Compute the average using the total obtained from the looping stage.
	Note that this operation is executed after exiting the loop. */
	avg = (double) total/n;

	/* Print out the grand total and the average of the first n numbers */
	printf(" \n The sum of the first %d numbers is %d \n ", n, total);
	printf(" \n The average of the first %d numbers is %.2f \n", n, avg);

	return 0;
	
	}
