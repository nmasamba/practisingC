
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements Warshalls modified algorithm to find the shortest path between the nodes
in a graph, given its adjacency matrix. As an input to the algorithm, we take the adjacency matrix A 
of graph G and replace all the values of A which are zero by infinity (or 9999 in the code). The code
implementation prints out the path matrix that has the shortest path between the vertices of the 
graph.

Example I/O

Enter the number of nodes in the graph : 3

 Enter the adjacency matrix : 
 mat[0][0] = 1

 mat[0][1] = 0

 mat[0][2] = 1

 mat[1][0] = 1

 mat[1][1] = 0 

 mat[1][2] = 0

 mat[2][0] = 0

 mat[2][1] = 1

 mat[2][2] = 1

The adjacency matrix is : 
1	0	1	
1	0	0	
0	1	1	


1	9999	1	
1	9999	2	
9999	1	1	


1	9999	1	
1	9999	2	
2	1	1	


1	2	1	
1	3	2	
2	1	1

********************************************************************************************************/

#include <stdio.h>
#define INFINITY 9999

void read (int mat[5][5], int n);
void display(int mat[5][5], int n);

int main()
{
	int adj[5][5], Q[5][5], n, i, j, k;

	printf("\n Enter the number of nodes in the graph : ");
	scanf("%d", &n);
	printf("\n Enter the adjacency matrix : ");
	read(adj, n);
	printf("\n The adjacency matrix is : ");
	display(adj, n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	 	{
			if(adj[i][j] == 0)
	 			Q[i][j] = INFINITY;
	 		else
	 			Q[i][j] = adj[i][j];
	 	}
	}
		 
	for(k=0; k<n;k++)
	{
		for(i=0;i<n;i++)
	 	{
	 		for(j=0;j<n;j++)
	 		{
	 			if(Q[i][j] <= Q[i][k] + Q[k][j])
	 				Q[i][j] = Q[i][j];
	 			else
	 				Q[i][j] = Q[i][k] + Q[k][j];
	 		}
	 	}

		printf("\n\n");
		display(Q, n);
	}

	
	return 0;
}

void read(int mat[5][5], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	 	{
	 		printf("\n mat[%d][%d] = ", i, j);
	 		scanf("%d", &mat[i][j]);
	 	}
	}
}

void display(int mat[5][5], int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
	 		printf("%d\t", mat[i][j]);
	}
}





