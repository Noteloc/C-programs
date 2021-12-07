#include<stdio.h>

int main ()
{
	unsigned short int aval = 65535;	// aval is an unsigned short integer, meaning it cant go into negative numbers
	unsigned short int bval = 0;		// bval is also an unsigned short integer
	int cval;							// cval is just a regular, signed int
	
	printf("First printf statment:\n");									
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);	// Printing out the values of all three variables
	bval = aval + 1;													// Changing bval to be 1 more than aval
	cval = aval + 1;													// Changing cval to be 1 more than aval, however this wont work as cval cant store a number that high
	printf("Second printf statment:\n");
	printf("\taval: %d\n\tbval: %d\n\tcval: %d\n", aval, bval, cval);	// Printing out the new values
	 
	 
	/*	 
	a. aval value is 65535, bval value is 0, cval value is not assigned
	b. cval didnt get assigned a value so its value is what ever was left in the memory slot
	c. the qualifier unsigned tells the int variable to only store values in the positive numbers, not negative, as well it can store a higher positive number than a signed int
	d. the qualifier short tells the int variable to limit the value stored in it by half of the usual limit
	e. aval stays unchanged because we are changing bval and cval
	f. the reason bval and cval are not the same is that bval is unsigned while cval is signed so cval has a lower limit to the size of positive numbers it can store
	*/
	
	return 0;
}
