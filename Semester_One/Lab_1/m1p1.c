#include<stdio.h>

int main()
{
	int input; 			// variable for the users input
	float sum = 0;   	// variable for the sum of the number, note that it is a float so we can get the average
	int times = 0;	    // variable for counting the loop
	
	
	printf("\nPlease enter the amount of numbers: "); 	// Opening statment to ask the user for input
	scanf("%d", &times);									//collection the input
										
	for(int i=0; i<times; i++)	// a simple for loop to repeat this as many times as the user inputted
	{
		printf("\nEnter a number: "); 	// Asking the user for input
		scanf("%d", &input);			// Taking the users input
		
		sum += input;					// Adding the inputs for the sum
	}
	
	printf("\nThe sum is: %.0f", sum);				// Outputting the sum, removing the decimal place as we dont need it here
	printf("\nThe average is: %.2f\n", sum/times);	// Outputting the average, keeping it at two decimal places for looks

	return 0;
}
