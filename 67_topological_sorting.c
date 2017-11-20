
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements a topological sort. TOPOLOGICAL SORTING
Topological sort of a directed acyclic graph (DAG) G is defined as a linear ordering of its nodes
in which each node comes before all nodes to which it has outbound edges. Every DAG has one
or more number of topological sorts. Topological sorting is widely used in scheduling applications, 
jobs, or tasks. The jobs that have to be completed are represented by nodes, and there is an edge
from node u to v if job u must be completed before job v can be started. A topological sort
of such a graph gives an order in which the given jobs must be performed.

Example input:
Enter the number of vertices: 7

 Enter edge 1(0 to quit): 1 2

 Enter edge 2(0 to quit): 2 3

 Enter edge 3(0 to quit): 2 5

 Enter edge 4(0 to quit): 2 4

 Enter edge 5(0 to quit): 3 5

 Enter edge 6(0 to quit): 4 5

 Enter edge 7(0 to quit): 5 6

 Enter edge 8(0 to quit): 7 4

 Enter edge 9(0 to quit): 0 0

Example output:
 The adjacency matrix is:
  0  1  0  0  0  0  0
  0  0  1  1  1  0  0
  0  0  0  0  1  0  0
  0  0  0  0  1  0  0
  0  0  0  0  0  1  0
  0  0  0  0  0  0  0
  0  0  0  1  0  0  0
  The topological sorting can be given as : 1 7 2 3 4 5 6 
********************************************************************************************************/


#include <stdio.h>
#define MAX 10

int n,adj[MAX][MAX];
int front = -1,rear = -1,queue[MAX];
void create_graph(void);
void display();
void insert_queue(int);
int delete_queue(void);
int find_indegree(int);

void main()
{
	int node,j = 0,del_node, I;
	int topsort[MAX],indeg[MAX];

	create_graph();
	printf("\n The adjacency matrix is:");
	display();
	printf("\n");
	/*Find the in-degree of each node*/
	for(node = 1; node <= n; node++)
	{
		 indeg[node] = find_indegree(node);
		 if( indeg[node] == 0 )
			insert_queue(node);
	}
	while(front <= rear) /*Continue loop until queue is empty */
	{
		del_node = delete_queue();
		topsort[j] = del_node; /*Add the deleted node to topsort*/
		j++;
		/*Delete the del_node edges */
		for(node = 1; node <= n; node++)
		{
			if(adj[del_node][node] == 1 )
			{
			 	adj[del_node][node] = 0;
		 		indeg[node] = indeg[node] - 1;
			 	if(indeg[node] == 0)
		 			insert_queue(node);
			}
		}
	}
	printf("The topological sorting can be given as :\n");
	for(node=0;node<j;node++)
		printf("%d ",topsort[node]);
	printf("\n");
}

void create_graph()
{
	int i,max_edges,org,dest;
	printf("\n Enter the number of vertices: ");
	scanf("%d",&n);
	max_edges = n*(n - 1);
	for(i = 1; i <= max_edges; i++)
	{
		 printf("\n Enter edge %d(0 to quit): ",i);
		 scanf("%d %d",&org,&dest);
		 if((org == 0) && (dest == 0))
		 	break;
		 if( org > n || dest > n || org <= 0 || dest <= 0)
		 {
			printf("\n Invalid edge");
			i--;
		 }
		 else
		 	adj[org][dest] = 1;
	}
}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	 	printf("\n");
	 	for(j=1;j<=n;j++)
	 	printf("%3d",adj[i][j]);
	}
}
void insert_queue(int node)
{
	if (rear==MAX-1)
		printf("\n OVERFLOW ");
	else
	{
	if (front == -1) /*If queue is initially empty */
		front=0;
	queue[++rear] = node ;
	}
}

int delete_queue()
{
	int del_node;
	if (front == -1 || front > rear)
	{
		printf("\n UNDERFLOW ");
		return 0;
	}
	else
	{
		del_node = queue[front++];
		return del_node;
	}
}

int find_indegree(int node)
{
	int i,in_deg = 0;
 	for(i = 1; i <= n; i++)
 	{
 		if( adj[i][node] == 1 )
 		in_deg++;
 	}
 	return in_deg;
}


