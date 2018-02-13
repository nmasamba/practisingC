
/*****************************************************************************************************
Adapted from Data Structures in C, 2nd Ed (Reema Thareja)

Edited by Nyasha Masamba

This C program implements closed hashing based on the addition method. A hash table is a data structure in which keys 
are mapped to array positions by a hash function. A value stored in a hash table can be searched in O(1) 
time by using a hash function which generates an address from the key (by producing the index of the array 
where the value is stored). This process of mapping the keys to appropriate locations (or indices) in a 
hash table is called hashing. When two or more keys are mapped to the same memory location, a collision
is said to have occured. COllisions can be resolved either by open addressing or by chaining. Hash 
tables are widely used in situations where enormous amounts of data have to be accessed
to quickly search and retrieve information. However, choosing an effective hash function can turn out to 
be more of an art than a science.

In closed hashing, all the records are directly stored in the hash table. Each record with a key
value k is stored in a location called its home position. The home position is calculated by
applying some hash function such as the folding method, addition method or multiplication method. 

********************************************************************************************************/

#include <stdio.h>

int ht[10], i, found = 0, key;
void insert_val();
void search_val();
void delete_val();
void display();

int main()
{
	int option;

	for ( i = 0;i < 10;i++ ) //to initialize every element as ‘-1’
	 	ht[i] = -1;
	do
	{
		printf( "\n MENU \n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit");
		printf( "\n Enter your option.");
		scanf( "%d", &option);

		switch (option)
		{
			case 1:
		 		insert_val();
				break;
			case 2:
		 		search_val();
				break;
		 	case 3:
		 		delete_val();
				break;
		 	case 4:
		 		display();
				break;
		   default:
				printf( "\nExiting...\n" );
		 		break;
		}

	} while (option!=5);

	return 0;
}

void insert_val()
{
	int val, f = 0;
	printf( "\nEnter the element to be inserted : " );
	scanf( "%d", &val );
	
	key = ( val % 10 ) - 1;
	
	if ( ht[key] == -1 )
	{
	 	ht[key] = val;
	}
	else
	{
		if ( key < 9 )
	 	{
			for ( i = key + 1;i < 10;i++ )
	 		{
				if ( ht[i] == -1 )
	 			{
	 				ht[i] = val;
					break;
	 			}
	 		}
	 	}
		
		for ( i = 0;i < key;i++ )
	 	{
			if ( ht[i] == -1 )
	 		{
	 			ht[i] = val;
				break;
	 		}
	 	}
	}
}

void display()
{
	for (i = 0;i < 10;i++)
	printf( "\t%d", ht[ i ] );
}

void search_val()
{
	int val, flag = 0;
	printf( "\nEnter the element to be searched :: " );
	scanf( "%d", &val );
	
	key = ( val % 10 ) - 1;
	
	if ( ht[ key ] == val )
		flag = 1;
	else
	{
		for (i = key + 1;i < 10;i++)
	 	{
			if(ht[i] == val)
	 		{
				flag = 1;
	 			key = i;
				break;
			}
	 	}
	}

	if (flag == 0)
	{
		for (i = 0;i < key;i++)
	 	{
			if (ht[ i ] == val)
	 		{
				flag = 1;
	 			key = i;
				break;
	 		}
	 	}
	}

	if (flag == 1)
	{
		found=1;
		printf("\n The item searched was found at position %d !", key + 1 );
	}
	else
	{
		key = -1;
		printf( "\nThe item searched was not found in the hash table" );
	}
}

void delete_val()
{
	search_val();
	if (found==1)
	{
		if ( key != -1 )
	 	{
			printf( "\nThe element deleted is %d ", ht[ key ] );
	 		ht[ key ] = -1;
	 	}
	}
}

