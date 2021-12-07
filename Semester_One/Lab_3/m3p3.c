#include<stdio.h>	// ah its good to see you my old friend

#define SIZE 100	// SIZE is gonna be a HUGE 100 (I did 100 cause its a big number, I tried to do a dynamically allocated string but I couldnt figure out how to do it without getting involved in 							pointers)

int main()
{
	char input[SIZE]; 	// an array, but not just any array, one that is for the users input
	char reverse[SIZE];	// ooo a second array for the reversed string? very nice
	int count = 0;		// and an int variable to round off our diverse cast of variables!
	
	printf("Enter a string... if you dare: ");	// Do you dare?!?! WELL DO YOU?!?!
	scanf(" %[^\n]s", input);	// oh I guess you do dare

	while(input[count] != '\0')	// A while loop?! well I suppose it works better than a for in this situation, but I miss my for loops
		count++;	// lets increase count to count the size of the string! (I guess)

	for(int i=0; i<SIZE; i++)	// Now im doing something *weird* in this for loop
		reverse[i] = '\0';		// im setting all the elements in the reverese array to be NULL, why you may ask? cause I was getting a weird error that when a string was 24-26-
								//-characters long it gave some weird output, but this fixes it so thats why it be here
	for(int i=0; i<count; i++)	// wow another for loop? must be my lucky day!
	{
		if(input[i] == '\0')	// lets keep that NULL character where it is, we dont want to reverse that
			reverse[i] = input[i];
		else	// but if its not a NULL.....
			reverse[i] = input[count-1-i];	// lets reverse that string!!!
	}

	for(int i=0; i<count; i++)	// in case you couldnt tell I like for loops
	{
		if((i == 0) && (reverse[i] >= 'a' && reverse[i] <= 'z'))	// if its the first index AND its a lowercase
			reverse[i] -= 32;	// make it uppercase
		else if((reverse[i-1] == ' ') && (reverse[i] >= 'a' && reverse[i] <= 'z'))	// if the LAST index was a space, AND its lowercase
			reverse[i] -= 32;	// make it uppercase, as well (I know I could have combined the last two if statments but then it would have been real confusing)
		else if((i != 0) && (reverse[i-1] != ' ') && (reverse[i] >= 'A' && reverse[i] <= 'Z'))	// if its NOT the first index and its NOT the first character AND its uppercase
			reverse[i] += 32;	// make it lowercase (I know the else statements should have made the first condition in this redundant but it wasnt working without it soooooo here we are)
	}
	
	printf("%s\n", reverse);	// oh yes before I forget lets print that reversed, titlecased string
	printf("Length of the string is: %d\n", count);	// and one final print of count to round it off

	return 0;	// oh AND OF COURSE the return 0
}
