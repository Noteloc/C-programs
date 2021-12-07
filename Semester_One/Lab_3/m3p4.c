#include<stdio.h>	// include, once more

#define SIZE 6		// SIZE is only 6? seems low to me

int main()
{
	int intArr[SIZE];	// a 6 digit int array, for all your 6 digit int array needs
	char charArr[SIZE];	// a 6 character char array, cause C doesnt have strings
	
	printf("For my next trick I need you to enter six numbers into an array...\n");	// I could tottally be a magigican with lines like these
	for(int i=0; i<SIZE; i++)	// every great program always starts with a for loop
	{
		printf("Enter number %d: ", i+1);	// print out a simple prompt for a simple program
		scanf(" %d", &intArr[i]);			// and youll take that input and youll like it
	}
	
	printf("And of course a six character string if you would: "); // well now I guess we need a string as well
	scanf(" %[^\n]s", charArr);	// and lets take that string and put it where it belongs
	
	printf("Element        Address        Hexadecimal Value\n");		// ooo making the titles look al fancy
	printf("================================================\n");		// and some nice formatting there
	for(int i=0; i<SIZE; i++)	// double the for loops...
		printf("intArr[%d]\t%p\t%X\n", i+1, &intArr[i], intArr[i]);		// print out all three values we need, with a tab in between then so they're not *too* cozy
	printf("================================================\n");		// even more nice formatting
	for(int i=0; i<SIZE; i++)	// ...double the fun
		printf("charArr[%d]\t%p\t%X\n", i+1, &charArr[i], charArr[i]);	// lets print it all out again! but for the string this time, dont want it to feel left out
	printf("================================================\n");		// ahh the nice formatting


	return 0;	// and the last return 0 
}

/*
1. intArr[1] and intArr[2] are 4 values apart
2. a int is 4 bytes
3. charArr[1] and charArr[2] are just 1 value apart
4. a char is one byte
5. you could just take the last address and subtract it by the first address
*/
