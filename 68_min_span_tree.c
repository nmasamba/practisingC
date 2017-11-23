/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program uses Prim's (greedy) algorithm to find the minimum spanning tree of the graph.
A minimum spanning tree (MST) is defined as a spanning tree with weight less than or equal
to the weight of every other spanning tree. In other words, a minimum spanning tree is a spanning
tree that has weights associated with its edges, and the total weight of the tree (the sum of the
weights of its edges) is at a minimum.

Example I/O
Enter the number of nodes in the Graph : 3

 Enter the adjacency matrix of the Graph1 0 1
1 1 1
0 1 0

 Enter the Source : 2

 The Edges of the Mininum Spanning Tree are 2 1 
 2 3 

 The Total cost of the Minimum Spanning Tree is : 4

********************************************************************************************************/

#include <stdio.h>
#define MAX 10

int adj[MAX][MAX], tree[MAX][MAX], n;

void readmatrix()
{
	int i, j;
	printf("\n Enter the number of nodes in the Graph: ");
	scanf("%d", &n);
	printf("\n Enter the adjacency matrix of the Graph: ");
	for (i = 1; i <= n; i++)
	 	for (j = 1; j <= n; j++)
	 		scanf("%d", &adj[i][j]);
}

int spanningtree(int src)
{
	int visited[MAX], d[MAX], parent[MAX];
	int i, j, k, min, u, v, cost;
	
	for (i = 1; i <= n; i++)
	{
		d[i] = adj[src][i];
		visited[i] = 0;
	 	parent[i] = src;
	}
	visited[src] = 1;
	cost = 0;
	k = 1;
	for (i = 1; i < n; i++)
	{
		min = 9999;
	 	for (j = 1; j <= n; j++)
	 	{
		 	if (visited[j]==0 && d[j] < min)
	 		{
	 			min = d[j];
				u = j;
				cost += d[u];
	 		}
	 	}
	visited[u] = 1;
	//cost = cost + d[u];
	tree[k][1] = parent[u];
	tree[k++][2] = u;
	for (v = 1; v <= n; v++)
		if (visited[v]==0 && (adj[u][v] < d[v]))
	 	{
	 		d[v] = adj[u][v];
			parent[v] = u;
	 	}
	}
	return cost;
}

void display(int cost)
{
	int i;
	printf("\n The Edges of the Mininum Spanning Tree are");
	for (i = 1; i < n; i++)
		printf(" %d %d \n", tree[i][1], tree[i][2]);
	printf("\n The Total cost of the Minimum Spanning Tree is : %d", cost);
}
	
int main()
{
	int source, treecost;
	readmatrix();
	printf("\n Enter the Source : ");
	scanf("%d", &source);
	treecost = spanningtree(source);
	display(treecost);
	return 0;
}







