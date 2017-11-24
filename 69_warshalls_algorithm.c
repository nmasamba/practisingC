
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements Warshalls algorithm to find the path matrix. If a graph G is given as G=(V, E), 
where V is the set of vertices and E is the set of edges, the path matrix of G can be found as, 
P = A + A^2 + A^3 + ... + A^n. 
This is a lengthy process, so Warshall provided a very efficient algorithm to calculate the path
matrix. 

*NB: algorithm needs a bit of work*

********************************************************************************************************/

#include <stdio.h>

void read (int mat[5][5], int n);
void display (int mat[5][5], int n);
void mul(int mat[5][5], int n);

int main()
{
	int adj[5][5], P[5][5], n, i, j, k;
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
		 	 	 		P[i][j] = 0;
	 				else
	 					P[i][j] = 1;
	 			}
	 	}
		
		for(k=0; k<n;k++)
		{
			for(i=0;i<n;i++)
	 		{
		 	 	for(j=0;j<n;j++)
	 				P[i][j] = P[i][j] | ( P[i][k] & P[k][j]);
	 		}
		}
	printf("\n The Path Matrix is :");
	display (P, n);
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
		printf("\n");
	 	for(j=0;j<n;j++)
 			printf("%d\t", mat[i][j]);
}
