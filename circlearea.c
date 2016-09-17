/***************************************************************
Author: Nyasha Masamba

The purpose of this C program is to calculate the area of a
circle given a radius by the user. It utilises the formula

Area of circle = pi * radius^2,

where pi is approximated to 3.141 and the radius can be given
by the user as a floating point number. The area is calculated
and printed to the console, approximated to 2 decimal places.

**************************************************************/

#include <stdio.h>

int main() {
        float radius;
	double area;	
	
	/* Ask the user to input radius via standard I/O console */
        printf(" \n Please enter radius of circle: ");
        
	/* Read in radius from console input */
	scanf("%f", &radius);

	/* Calculate the circle's area and print it out to the user */
        area = 3.141 * radius * radius;
        printf(" \n The area of the circle is =  %.2lf \n ", area);

        return 0;
}
