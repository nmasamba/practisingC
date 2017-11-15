

/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program creates a graph of n vertices using an adjacency list. Also prints the graph to std I/O
 and finally to delete the graph.


A graph is an abstract data structure that is used to implement the mathematical concept of graphs.
It is basically a collection of vertices (also called nodes) and edges that connect these vertices. A
graph is often viewed as a generalization of the tree structure, where instead of having a purely
parent-to-child relationship between tree nodes, any kind of complex relationship can exist.
********************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct node
{
	char vertex;
	struct node *next;
};

struct node *gnode;
void displayGraph(struct node *adj[], int no_of_nodes);
void deleteGraph(struct node *adj[], int no_of_nodes);
void createGraph(struct node *adj[], int no_of_nodes);

int main()
{
	struct node *Adj[10];
	int i, no_of_nodes;

	printf("\n Enter the number of nodes in G: ");
	scanf("%d", &no_of_nodes);
	
	for(i = 0; i < no_of_nodes; i++)
		Adj[i] = NULL;
	createGraph(Adj, no_of_nodes);
	printf("\n The graph is: ");
	displayGraph(Adj, no_of_nodes);
	deleteGraph(Adj, no_of_nodes);

	return 0;
}

void createGraph(struct node *Adj[], int no_of_nodes)
{
	struct node *new_node, *last;
	int i, j, n, val;
	
	for(i = 0; i < no_of_nodes; i++)	
	{
		 last = NULL;
		 printf("\n Enter the number of neighbours of node %d: ", i);
		 scanf("%d", &n);
		 
		for(j = 1; j <= n; j++)
		{
			 printf("\n Enter neighbour %d of node %d: ", j, i);
			 scanf("%d", &val);
			 new_node = (struct node *) malloc(sizeof(struct node));
			 new_node -> vertex = val;
			 new_node -> next = NULL;
			 if (Adj[i] == NULL)
			 	Adj[i] = new_node;
			 else
			 	last -> next = new_node;
			 	last = new_node;
		}
	}
}

void displayGraph (struct node *Adj[], int no_of_nodes)
{
	struct node *ptr;
	int i;
	for(i = 0; i < no_of_nodes; i++)
	{
		 ptr = Adj[i];
		 printf("\n The neighbours of node %d are:", i);
		 
		 while(ptr != NULL)
		 {
		 	printf("\t%d", ptr -> vertex);
		 	ptr = ptr -> next;
		 }
	}
}

void deleteGraph (struct node *Adj[], int no_of_nodes)
{
	int i;
	struct node *temp, *ptr;
	for(i = 0; i <= no_of_nodes; i++)
	{
		 ptr = Adj[i];
		 while(ptr != NULL)
		 {
			 temp = ptr;
			 ptr = ptr -> next;
			 free(temp);
		 }
		 Adj[i] = NULL;
	}
}

