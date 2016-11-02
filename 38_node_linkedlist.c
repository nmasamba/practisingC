/***********************************************

Author: Nyasha Masamba

This C program is merely meant to demonstrate 
the structure of a node in a linked list. A
node consists of 2 parts - a part that holds
data e.g an int; and another part which holds
the address of where to find that linked list's
next node in memory (nodes, unlike array elements,
are not stored at consecutive memory locations).

Note: the program is not meant to do anything,
it merely serves to illustrate a foundational 
concept.

************************************************/


#include <stdio.h>

int main() 
{
	
	/* implementation of the node of a linked list */
	/* each node contains a data part and a pointer to the next node in memory */
	struct node {
		int data;
		struct node *next;
	};

}