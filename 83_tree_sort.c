
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a tree sort algorithm. 
Atree sort is a sorting algorithm that sorts numbers by making use of the properties of binary search
tree. The algorithm first builds a binary search tree using the numbers
to be sorted and then does an in-order traversal so that the numbers are retrieved in a sorted order. 
Tree sort takes O(n log n) time in the best case, O(n^2) in the worst case.

Example I/O

>$ Enter 10 elements : 1 20 3 40 5 60 7 80 9 100

 The elements of the array are : 
1	20	3	40	5	60	7	80	9	100	
 The sorted array is : 
1	3	5	7	9	20	40	60	80	100

********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct tree
{
	struct tree *left;
	int num;
	struct tree *right;
};

void insert (struct tree **, int);
void inorder (struct tree *);

void main()
{
	struct tree *t ;
	int arr[10];
	int i ;
	printf("\n Enter 10 elements : ");
	for(i=0;i<10;i++)
	scanf("%d", &arr[i]);
	t = NULL ;
	printf ("\n The elements of the array are : \n" ) ;
	for (i = 0 ; i <10 ; i++)
	printf ("%d\t", arr[i]) ;
	for (i = 0 ; i <10 ; i++)
	insert (&t, arr[i]) ;
	printf ("\n The sorted array is : \n") ;
	inorder (t ) ;
}

void insert (struct tree **tree_node, int num)
{
	if ( *tree_node == NULL )
	{
		*tree_node = malloc (sizeof ( struct tree )) ;
		( *tree_node ) -> left = NULL ;
		( *tree_node ) -> num = num ;
		( *tree_node ) -> right = NULL ;
	}
	else
	{
		if ( num < ( *tree_node ) -> num )
			insert ( &( ( *tree_node ) -> left ), num ) ;
		else
			insert ( &( ( *tree_node ) -> right ), num ) ;
	}
}

void inorder (struct tree *tree_node )
{
	if ( tree_node != NULL )
	{
		inorder ( tree_node -> left ) ;
		printf ( "%d\t", tree_node -> num ) ;
		inorder ( tree_node -> right ) ;
	}
}



