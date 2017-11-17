

/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a breadth-first search algorithm and finds the shortest path
through the network. Breadth-first search (BFS) is a graph search algorithm that begins at the root 
node and explores all the neighbouring nodes. Then for each of those nearest nodes, the algorithm 
explores their unexplored neighbour nodes, and so on, until it finds the goal.
********************************************************************************************************/


#include <stdio.h>
#define MAX 10

void breadth_first_search(int adj[][MAX],int visited[],int start)
{
	int queue[MAX],rear = -1,front =- 1, i;
	queue[++rear] = start;
	visited[start] = 1;
	
	while(rear != front)
	{
		 start = queue[++front];
		 if(start == 4)
		 printf("5\t");
		 else
		 printf("%c \t",start + 65);
		 	for(i = 0; i < MAX; i++)
				{
		 	 		if(adj[start][i] == 1 && visited[i] == 0)
	 				{
	 					queue[++rear] = i;
						visited[i] = 1;
	 				}
				}
	}
}

int main()
{
	int visited[MAX] = {0};
	int adj[MAX][MAX], i, j;
	printf("\n Enter the adjacency matrix: ");
	
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
 			scanf("%d", &adj[i][j]);

	printf("BFS Traversal: ");
	breadth_first_search(adj,visited,0);
	printf("\n");

	return 0;
}




