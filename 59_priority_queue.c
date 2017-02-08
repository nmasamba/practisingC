
/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a priority queue. A priority queue is a data 
structure in which each element is assfgned a priority. The priority of
the element will be used to determine the order in which the elements
will be processed. Generally, en element with higher priority is processed
before an element with a lower priority. Two elements with the same 
priority are processed on a first-come, first-served (FCFS) basis.
A queue is a FIFO (First-In, First-Out) data structure in which the element
that is inserted first is the first one to be taken out. The elements in a 
queue are added at one end (called the REAR) and removed from the other end 
(called the FRONT) of the queue. The process of inserting an element into
a queue is to enqueue. The process of deleting/removing an element from a
queue is to dequeue.
**************************************************************************/



#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
int priority;
struct node *next;
};

struct node *start=NULL;
struct node *insert(struct node *);
struct node *delete(struct node *);
void display(struct node *);

int main()
{
	int option;

	do
	{
		printf("\n *****MAIN MENU*****");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your option : ");
		scanf( "%d", &option);
	
		switch(option)
		{
			case 1:
				start=insert(start);
				break;
		 	case 2:
		 		start = delete(start);
				break;
		 	case 3:
		 		display(start);
				break;
		 }
		}while(option!=4);

		return 0;

}

struct node *insert(struct node *start)
{
	int val, pri;
	struct node *ptr, *p;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	printf("\n Enter the value and its priority : " );
	scanf( "%d %d", &val, &pri);
	
	ptr->data = val;
	ptr->priority = pri;
	if(start==NULL || pri < start->priority )
	{
	 	ptr->next = start;
	 	start = ptr;
	}
	else
	{
	 	p = start;
		while(p->next != NULL && p->next->priority <= pri)
	 		p = p->next;
	 	ptr->next = p->next;
	 	p->next = ptr;
	}

	return start;

}

struct node *delete(struct node *start)
{
	struct node *ptr;
	
	if(start == NULL)
	{
	 	printf("\n UNDERFLOW" );
	 	return 0;
	}
	else
	{
		ptr = start;
		printf("\n Deleted item is: %d", ptr->data);
		start = start->next;
		free(ptr);
	}

	return start;

}

void display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	
	if(start == NULL)
	 	printf("\nQUEUE IS EMPTY" );
	else
	{
	 	printf("\n PRIORITY QUEUE IS : " );
		while(ptr != NULL)
	 	{
	 		printf( "\t%d[priority=%d]", ptr->data, ptr->priority );
	 		ptr=ptr->next;
	 	}
	}
}

