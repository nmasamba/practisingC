/***************************************************************

Author: Nyasha Masamba

This C program illustrates the differences and similarities
between struct and union types. The main similairites are in
declaration syntax and accessing members (e.g using the dot
operator). The main difference between them is the fact that 
a union's fields share memory space, so the fields of a union
cannot be initialised all at once and they also cannot be
accessed all at once. See what output the program outputs
for P2's points to understand this concept. Unions are typically
nested within structs to simplify some aspect of data storage.

****************************************************************/


#include <stdio.h>

typedef struct INSTRUCTURE
{
	int x, y;
};

typedef union INUNION
{
	int x;
	int y;
};

int main()
{
	struct INSTRUCTURE P1 = {2,3};
	// INSTRUCTURE P2 ={4,5}; Illegal in case of unions
	 
	union INUNION P2;
	P2.x = 4;
	P2.y = 5;

	printf("\n The coordinates of P1 are %d and %d", P1.x, P1.y);
	printf("\n The coordinates of P2 are %d and %d", P2.x, P2.y);
	
	return 0;

}
