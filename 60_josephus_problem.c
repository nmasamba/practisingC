/*****************************************************************************************************

Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a solution to the Josephus problem using a queue.
In Josephus problem, n people stand in a circle waiting to be executed. The counting starts at some
point in the circle and proceeds in a specific direction around the circle. In each step, a certain
number of people are skipped and the next person is executed (or eliminated). The elimination
of people makes the circle smaller and smaller. At the last step, only one person remains who is
declared the ‘winner’. Therefore, if there are n number of people and a number k which indicates 
that k–1 people are skipped and k–th person in the circle is eliminated, then the problem is to 
choose a position in the initial circle so that the given person becomes the winner. For example, 
if there are 5 (n) people and every second (k) person is eliminated, then first
the person at position 2 is eliminated followed by the person at position 4 followed by person at
position 1 and finally the person at position 5 is eliminated. Therefore, the person at position 3
becomes the winner. 

********************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct node
{
int player_id;
struct node *next;
};

struct node *start, *ptr, *new_node;

int main()
{
	int n, k, i, count;
	
	printf("\n Enter the number of players : ");
	scanf("%d", &n);
	printf("\n Enter the value of k (every kth player gets eliminated): ");
	scanf("%d", &k);
	
	// Create circular linked list containing all the players
	start = malloc(sizeof(struct node));
	start->player_id = 1;
	ptr = start;
	
	for (i = 2; i <= n; i++)
	{
		new_node = malloc(sizeof(struct node));
		ptr->next = new_node;
		new_node->player_id = i;
		new_node->next=start;
		ptr=new_node;
	}
	
	for (count = n; count > 1; count--)
	{
		for (i = 0; i < k - 1; ++i)
	 		ptr = ptr->next;
	 	ptr->next = ptr->next->next; // Remove the eliminated player from the circular linked list
	}

	printf("\n The Winner is Player %d", ptr->player_id);
	
	return 0;
}