/*****************************************************************************************************

Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program shows how to generate and then show a one-way threaded binary tree. 
A threaded binary tree is the same as that of a binary tree but with a difference in storing the NULL
pointers. In one-way threading, a thread will appear either in the right field or the left field of the
node. A one-way threaded tree is also called a single-threaded tree. If the thread appears
in the left field, then the left field will be made to point to the in-order predecessor of the
node. Such a one-way threaded tree is called a left-threaded binary tree. On the contrary,
if the thread appears in the right field, then it will point to the in-order successor of the node. 
Such a one-way threaded tree is called a right-threaded binary tree. In a two-way threaded tree, also 
called a double-threaded tree, threads will appear in both the left and the right field of the node. 
While the left field will point to the in-order predecessor of the node, the right field will point to 
its successor. A two-way threaded binary tree is also called a fully threaded binary tree. 

********************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int val;
	struct tree *right;
	struct tree *left;
	int thread;
};

struct tree *root = NULL;

struct tree* insert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{
	if(root == NULL)
	{
		root = ptr;
		if(rt != NULL)
		 {
			root->right = rt;
			root->thread = 1;
		 }
	}
	else if(ptr->val < root->val)
		root->left = insert_node(root->left, ptr, root);
	else if(root->thread == 1)
	 {
		root->right = insert_node(NULL, ptr, rt);
		root->thread=0;
	 }
	else
		root->right = insert_node(root->right, ptr, rt);
	return root;
}

struct tree* create_threaded_tree()
{
	struct tree *ptr;
	int num;
	printf("\n Enter the elements of the tree, press -1 to terminate. First element: ");
	scanf("%d", &num);
	
	while(num != -1)
	{
		ptr = (struct tree*)malloc(sizeof(struct tree));
		ptr->val = num;
		ptr->left = ptr->right = NULL;
		ptr->thread = 0;
		root = insert_node(root, ptr, NULL);
		printf(" \n Enter the next element: ");
		fflush(stdin);
		scanf("%d", &num);
	}

	return root;
}

void inorder(struct tree *root)
{
	struct tree *ptr = root, *prev;
	do
	{
		while(ptr != NULL)
		 {
			prev = ptr;
			ptr = ptr->left;

			if(prev != NULL)
			{
				printf(" %d", prev->val);
				ptr = prev->right;

				while(prev != NULL && prev->thread)
			 	{
					printf(" %d", ptr->val);
					prev = ptr;
					ptr = ptr->right;
				}
		 	}
		 }
	}while(ptr != NULL);
}

void main()
{
create_threaded_tree();
printf(" \n The in-order traversal of the tree can be given as : ");
inorder(root);
}










