
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a depth-first search algorithm and finds the shortest path
through the network. The depth-first search algorithm (Fig. 13.22) progresses by expanding the starting 
node of a graph, G, and then going deeper and deeper until the goal node is found, or until a node that 
has no children is encountered. When a dead-end is reached, the algorithm backtracks, returning to the 
most recent node that has not been completely explored.
********************************************************************************************************/


#include <stdio.h>
#define MAX 5


void depth_first_search(int adj[][MAX],int visited[],int start)
{
	int stack[MAX];
	int top = -1, i;

	printf("%c-",start + 65);

	visited[start] = 1;
	stack[++top] = start;

	while(top != -1)
	{
		 start = stack[top];
		 for(i = 0; i < MAX; i++)
		 {
		 	 if(adj[start][i] && visited[i] == 0)
		 		{
		 			stack[++top] = i;
					printf("%c-", i + 65);
					visited[i] = 1;
					break;
		 		}
		 }
			 if(i == MAX)
		 		top--;
	}
}

int main()
{
	int adj[MAX][MAX];
	int visited[MAX] = {0}, i, j;
	printf("\n Enter the adjacency matrix: ");
		 for(i = 0; i < MAX; i++)
		 	 for(j = 0; j < MAX; j++)
				scanf("%d", &adj[i][j]);
				printf("DFS Traversal: ");
		 		depth_first_search(adj,visited,0);
	printf("\n");
		 return 0;
}



