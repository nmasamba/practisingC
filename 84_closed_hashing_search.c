
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
