/**************************************************

Author: Nyasha Masamba

This C program shows, at a very basic level,
how to create memory for a new linked list.
The display function, however, is purely for
illustrative purposes. Because this program
exists simply as proof-of-concept implementation,
such functionality has not been completed.

***************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *display_ll(struct node *);

int main(int argc, char *argv[]) 
{
	
	struct node *new_node, *ptr;
	int num;

	printf(" \n Enter -1 to stop data entry ");
	printf(" \n Enter the node's data: ");
	scanf("%d", &num);

	while(num != -1) {
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data = num;
		if(start==NULL) {
			new_node -> next = NULL;
			start = new_node;
		}
		else {
			ptr = start;
			while(ptr->next != NULL) {
				ptr = ptr->next;
				ptr->next = new_node;
				new_node->next = NULL;
			}		
		}
		
		printf(" \n Enter the data: ");
		scanf("%d", &num);
	}
	
	if(num == -1)
		start = display_ll(start);

	return 0;
}

struct node *display_ll(struct node *start) 
{
               struct node *ptr;
               ptr = start;

               while(ptr != NULL) {
                       printf("\t %d", ptr -> data);
			ptr = ptr -> next;
		}

		return start;
}
