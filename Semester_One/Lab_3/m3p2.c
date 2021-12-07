#include <stdio.h>	// Ah good ole' include stdio.h, what ever would I do without you

#define SIZE 16		// lets make a SIZE, and what should that SIZE be? why, 16 of course!

int main()
{
	int input;				// A variable for getting that sweet, sweet user input
	int hex;				// ooooo spooky hex variable, for that spooooooky hexadecimal
	int inputArr[SIZE];		// An array, cause arrays make everything better (including storing a binary number)
	
	while(1)	// an INFINITE LOOOOOOOP
	{
		printf("Enter a decimal number and through the power of MAGIC I will convert it to binary and hexadecimal: ");	// Gotta keep the usaer entertained with this print to the screen dont we?
		scanf(" %d", &input);	// and y'know, we should *probably* get the input from them
		if(input > 65535)	// is the number a good number within the number paramaters? number
			printf("Do you are have stupid? enter one less than 16 bits\n");	// hey now, that seems a bit aggressive
		else	
			break;	// break out of the INFINTE LOOP
	}
	hex = input;			// lets make hex the same as input, for the fun of it (and cause we'll need that value later)

	for(int i=0; i<SIZE; i++)	// The best kind of loop, a for loop, for all your array index needs
	{	
		inputArr[i] = input % 2;	// calculating binary numbers is my favorite pasttime
		input /= 2;					// no sir nothing better than calculating binary numbers
	}
	
	int binary[SIZE];	// A new array??? but why??? could it be that we need to reverse the binary number???
	for(int i=0; i<SIZE; i++)	// *another* for loop? this program is getting spoiled rotten
		binary[i] = inputArr[SIZE-1-i];	// Ah yes, lets reverse the array into the now unreversed reversed array, makes sense right?
	
	int index = 0; // a variable named index? whatever could I use this for?
	int count = 0; // we are using it to count how many digits are 0, 1,2,3 or 4
	for(int i=0; i<SIZE; i++) // how many for loops this program got anyhow???
	{
		if(binary[i] == 1) // is the binary digit a 0? no? then it MUST BE A ONE, which means this nibble is safe, it can be spared deletion
		{
			index = i - count;	// lets make that index equal to whatever the hell 'i' is, subtracting count+1 of course
			break;	// and lets BREAK THE LOOP, BREAK IT DOWN
		}
		count++;	// lets increase count, build it up
		if(count == 4)	// every 4 times this loop repeats (but only every FOUR times - cause a nibble is 4)
			count = 0;	// make count go back to its roots, back to one
	}	// So essenitally what this weird block of code is doing is removing the leading nibbles if its all 0's, by counting all four digits of it and setting the print to start printing only on the 				nibble that isnt all 0's
	
	printf("Binary = ");	// lets give a subtle hint that we are printing out a binary number
	for(int i=index; i<SIZE; i++)	// ANOTHER GOSH DARN FOR LOOP ARE YOU KIDDING ME?!?!!?
	{
		if(i % 4 == 0)	// on every FOURTH itteration of the loop
			printf(" ");	// add a beutiful space in there to make things look good
		printf("%d", binary[i]);	// oh and I suppose we should also do the actual numbers too
	}
	printf("\n"); // and a new line so those lines dont feel too crowded 
	
	printf("Hexadecimal = 0x%X\n", hex);	// Oh and before I forget lets do the hexadecimal too, a little simpler than the binary, just a little
	
	return 0;	// and of course, the cherry on top, the return 0
}

/*
1. while it might appear to be smarter to use char as it only uses 1 byte, it is much simpler to use int to perform the algorithms we are using
2. you would choose char becuase it uses the least memory (1 byte), however I chose int because it is so much easier to work with in this program
3. you need a long int to store that value so 32 bits
*/
