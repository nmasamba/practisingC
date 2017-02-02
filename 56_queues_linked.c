



/*
SOLUTION STILL IN PROGRESS
Cross reference with stack linked list
*/


/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a queue using linked lists. The array implementation
of queues requires that the size of the implementation be known in advance.
The linked list implementation can grow and shrink on demand and as required.
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
	struct node *next;
};

struct queue
{
	struct node *front;
	struct node *rear;
};

struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int peek(struct queue *);

int main()
{
	int val, option;
	create_queue(q);
	
	do
	{
		 printf("\n *****MAIN MENU*****");
		 printf("\n 1. INSERT");
		 printf("\n 2. DELETE");
		 printf("\n 3. PEEK");
		 printf("\n 4. DISPLAY");
		 printf("\n 5. EXIT");
		 printf("\n Enter your option : ");
		 scanf("%d", &option);
		 switch(option)
	 	{
		 case 1:
			 printf("\n Enter the number to insert in the queue:");
			 scanf("%d", &val);
			 q = insert(q,val);
			 break;
		 case 2:
			 q = delete_element(q);
			 break;
		 case 3:
			 val = peek(q);
			 if(val != -1)
			 printf("\n The value at front of queue is : %d", val);
			 break;
		 case 4:
			 q = display(q);
			 break;
		}
	}while(option != 5);
	
	return 0;

}

void create_queue(struct queue *q)
{
	q -> rear = NULL;
	q -> front = NULL;
}

struct queue *insert(struct queue *q,int val)
{
	struct node *ptr;
	ptr = (struct node*)malloc(sizeof(struct node));
	ptr -> data = val;
	
	if(q -> front == NULL)
	{
		 q -> front = ptr;
		 q -> rear = ptr;
		 q -> front -> next = q -> rear -> next = NULL;
	}
	else
	{
		 q -> rear -> next = ptr;
		 q -> rear = ptr;
		 q -> rear -> next = NULL;
	}

	return q;
}

struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr = q -> front;
	
	if(ptr == NULL)
	 	printf("\n QUEUE IS EMPTY");
	else
	{
		 printf("\n");
		 while(ptr!=q -> rear)
		 {
		 	printf("%d\t", ptr -> data);
		 	ptr = ptr -> next;
		 }
		 printf("%d\t", ptr -> data);
	}

	return q;
}

struct queue *delete_element(struct queue *q)
{
	struct node *ptr;
	ptr = q -> front;
	
	if(q -> front == NULL)
	 	printf("\n UNDERFLOW");
	else
	{
		 q -> front = q -> front -> next;
		 printf("\n The value being deleted is : %d", ptr -> data);
		 free(ptr);
	}

	return q;
}

int peek(struct queue *q)
{
	if(q->front==NULL)
	{
		 printf("\n QUEUE IS EMPTY");
		 return -1;
	}
	else
	 	return q->front->data;
}


