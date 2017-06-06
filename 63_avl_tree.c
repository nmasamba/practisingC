/*****************************************************************************************************

Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program shows how to generate and then insert nodes into an AVL tree. 
AVL tree is a self-balancing binary search tree invented by G.M. Adelson-Velsky and E.M. Landis
in 1962. The tree is named AVL in honour of its inventors. In an AVL tree, the heights of the two
sub-trees of a node may differ by at most one. Due to this property, the AVL tree is also known
as a height-balanced tree. The key advantage of using an AVL tree is that it takes O(log n) time to
perform search, insert, and delete operations in an average case as well as the worst case because
the height of the tree is limited to O(log n).

********************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE ,TRUE } bool;

struct node
{
	int val;
	int balance;
	struct node *left_child;
	struct node *right_child;
};

struct node* search(struct node *ptr, int data)
{
	if(ptr!=NULL)
		if(data < ptr -> val)
			ptr = search(ptr -> left_child,data);
		else if( data > ptr -> val)
			ptr = search(ptr -> right_child, data);
	return(ptr);
}

struct node *insert (int data, struct node *ptr, int *ht_inc)
{
	struct node *aptr;
	struct node *bptr;

	if(ptr==NULL)
	{
		ptr = (struct node *) malloc(sizeof(struct node));
		ptr -> val = data;
		ptr -> left_child = NULL;
		ptr -> right_child = NULL;
		ptr -> balance = 0;
		*ht_inc = TRUE;
		return (ptr);
	}

	if(data < ptr -> val)
	{
		ptr -> left_child = insert(data, ptr -> left_child, ht_inc);
		if(*ht_inc==TRUE)
		{
			switch(ptr -> balance)
			{
				case -1: /* Right heavy */
					ptr -> balance = 0;
					*ht_inc = FALSE;
					break;
				case 0: /* Balanced */
					ptr -> balance = 1;
					break;
				case 1: /* Left heavy */
					aptr = ptr -> left_child;

				if(aptr -> balance == 1)
				{
					printf("Left to Left Rotation\n");
					ptr -> left_child= aptr -> right_child;
					aptr -> right_child = ptr;
					ptr -> balance = 0;
					aptr -> balance=0;
					ptr = aptr;
				}
				else
				{
					printf("Left to right rotation\n");
					bptr = aptr -> right_child;
					aptr -> right_child = bptr -> left_child;
					bptr -> left_child = aptr;
					ptr -> left_child = bptr -> right_child;
					bptr -> right_child = ptr;
					if(bptr -> balance == 1 )
						ptr -> balance = -1;
					else
						ptr -> balance = 0;
					if(bptr -> balance == -1)
						aptr -> balance = 1;
					else
						aptr -> balance = 0;
					
					bptr -> balance=0;
					ptr = bptr;
				}
				*ht_inc = FALSE;
			 }
		}
	}

	if(data > ptr -> val)
	{
		ptr -> right_child = insert(data, ptr -> right_child, ht_inc);
		if(*ht_inc==TRUE)
		{
			switch(ptr -> balance)
			{
				case 1: /* Left heavy */
					ptr -> balance = 0;
					*ht_inc = FALSE;
					break;
				case 0: /* Balanced */
					ptr -> balance = -1;
					break;
				case -1: /* Right heavy */
					aptr = ptr -> right_child;

				if(aptr -> balance == -1)
				{
					printf("Right to Right Rotation\n");
					ptr -> right_child= aptr -> left_child;
					aptr -> left_child = ptr;
					ptr -> balance = 0;
					aptr -> balance=0;
					ptr = aptr;
				}
				else
				{
					printf("Right to Left Rotation\n");
					bptr = aptr -> left_child;
					aptr -> left_child = bptr -> right_child;
					bptr -> right_child = aptr;
					ptr -> right_child = bptr -> left_child;
					bptr -> left_child = bptr;
					if(bptr -> balance == -1)
						ptr -> balance = 1;
					else
						ptr -> balance = 0;
					if(bptr -> balance == 1)
						aptr -> balance = -1;
					else
						aptr -> balance = 0;

					bptr -> balance=0;
					ptr = bptr;
				}/*End of else*/
				*ht_inc = FALSE;
			}
		}
	}

	return(ptr);
}

void display(struct node *ptr, int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr -> right_child, level+1);
		printf("\n");

		for (i = 0; i < level; i++)
			printf(" ");

		printf("%d", ptr -> val);
		display(ptr -> left_child, level+1);
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr -> left_child);
		printf("%d ",ptr -> val);
		inorder(ptr -> right_child);
	}
}

void main()
{
	bool ht_inc;
	int data;
	int option;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;

	while(1)
	{
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Quit\n");
		printf("Enter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d", &data);
				if( search(root,data) == NULL )
					root = insert(data, root, &ht_inc);
				else
					printf("Duplicate value ignored\n");
				break;
			case 2:
				if(root==NULL)
				{
					printf("Tree is empty\n");
					continue;
				}

				printf("Tree is :\n");
				display(root, 1);
				printf("\n\n");
				printf("Inorder Traversal is: ");
				inorder(root);
				printf("\n");
				break;
			case 3:
				exit(1);
				default:
				printf("Wrong option\n");
		}
	}
}














