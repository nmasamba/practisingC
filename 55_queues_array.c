

/*************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a queue using linear arrays.
A queue is a FIFO (First-In, First-Out) data structure in which the element
that is inserted first is the first one to be taken out. The elements in a 
queue are added at one end (called the REAR) and removed from the other end 
(called the FRONT) of the queue. The process of inserting an element into
a queue is to enqueue. The process of deleting/removing an element from a
queue is to dequeue.
**************************************************************************/


#include <stdio.h>

#define MAX 10 // Changing this value will change length of array
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);

int main()
{
	int option, val;
	
	do
	{
		printf("\n\n ***** MAIN MENU *****");
		printf("\n 1. Insert an element");
		printf("\n 2. Delete an element");
		printf("\n 3. Peek");
		printf("\n 4. Display the queue");
		printf("\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
		 		insert();
				break;
			case 2:
				val = delete_element();
				if (val != -1)
				printf("\n The number deleted is : %d", val);
				break;
			case 3:
				val = peek();
				if (val != -1)
				printf("\n The first value in queue is : %d", val);
				break;
			case 4:
				display();
				break;
	 	}
	}while(option != 5);

	return 0;

}

void insert()
{
	int num;
	
	printf("\n Enter the number to be inserted in the queue : ");
	scanf("%d", &num);
	
	if(rear == MAX-1)
		printf("\n OVERFLOW");
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	queue[rear] = num;
}

int delete_element()
{
	int val;
	if(front == -1 || front>rear)
	{
		printf("\n UNDERFLOW");
		return -1;
	}
	else
	{
		val = queue[front];
		front++;
		if(front > rear)
			front = rear = -1;
		return val;
	}
}

int peek()
{
	if(front==-1 || front>rear)
	{
		printf("\n QUEUE IS EMPTY");
		return -1;
	}
	else
	{
		return queue[front];
	}
}
void display()
{
	int i;
	printf("\n");
	
	if(front == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else
	{
		for(i = front;i <= rear;i++)
		printf("\t %d", queue[i]);
	}
}