#include<stdio.h>

int main(void)
{
	short int aval = 100;		// aval is a short int so the memory space is halved
	int bval = 100;				// bval is a regualar int variable
	float cval = 100;			// cval is a float variable to contain decimal places
	double dval = 100;			// dval is a double variable so it has double the space of a regualar float
	char eval = 100;			// eval is a regualar char variable
	unsigned char fval = 100;	// fval is an unsigned char variable meaning it cant contain any negative values

	printf("Name: aval\tAddress: %p\tContent: %d\tSize: %lu\n", &aval, aval, sizeof(aval));		// the print statments for all the values, with the appropiate format specifiers
	printf("Name: bval\tAddress: %p\tContent: %d\tSize: %lu\n", &bval, bval, sizeof(bval));
	printf("Name: cval\tAddress: %p\tContent: %f\tSize: %lu\n", &cval, cval, sizeof(cval));
	printf("Name: dval\tAddress: %p\tContent: %f\tSize: %lu\n", &dval, dval, sizeof(dval));
	printf("Name: eval\tAddress: %p\tContent: %c\tSize: %lu\n", &eval, eval, sizeof(eval));
	printf("Name: fval\tAddress: %p\tContent: %c\tSize: %lu\n", &fval, fval, sizeof(fval));
	
	

	return 0;
}
