

/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements heap sort (also known as tournament sort) that has a running time complexity
of O(n log n). Given an array ARR with n elements, the heap sort algorithm can be used to sort ARR in 
two phases:
In phase 1, build a heap H using the elements of ARR.
In phase 2, repeatedly delete the root element of the heap formed in phase 1.
In a max heap, we know that the largest value in H is always present at the root node. So in phase
2, when the root element is deleted, we are actually collecting the elements of ARR in decreasing
order. 


Example I/O

$> Enter the number of elements : 3

 Enter the elements : 10292 3838 2

 The sorted elements are:    2 3838 10292

********************************************************************************************************/

#include <stdio.h>
#define MAX 10

void RestoreHeapUp(int *,int);
void RestoreHeapDown(int*,int,int);

int main()
{
	int Heap[MAX],n,i,j;
	
	printf("\n Enter the number of elements : ");
	scanf("%d",&n);
	printf("\n Enter the elements : ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&Heap[i]);
		RestoreHeapUp(Heap, i); // Heapify
	}
	// Delete the root element and heapify the heap
	j=n;
	for(i=1;i<=j;i++)
	{
		int temp;
		temp=Heap[1];
		Heap[1]= Heap[n];
		Heap[n]=temp;
		n = n-1; // The element Heap[n] is supposed to be deleted
		RestoreHeapDown(Heap,1,n); // Heapify
	}
	n=j;
	printf("\n The sorted elements are: ");
		for(i=1;i<=n;i++)
	printf("%4d",Heap[i]);
		return 0;
}

void RestoreHeapUp(int *Heap,int index)
{
	int val = Heap[index];
	while( (index>1) && (Heap[index/2] < val) )// Check parent's value
	{
		Heap[index]=Heap[index/2];
		index /= 2;
	}
	Heap[index]=val;
}

void RestoreHeapDown(int *Heap,int index,int n)
{
	int val = Heap[index];
	int j=index*2;
	while(j<=n)
	{
		if( (j<n) && (Heap[j] < Heap[j+1]))// Check sibling's value
			j++;
		if(Heap[j] < Heap[j/2]) // Check parent's value
			break;
		Heap[j/2]=Heap[j];
		j=j*2;
	}
	Heap[j/2]=val;
}






