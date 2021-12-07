#include<stdio.h>	// All the best programs start with a #include

int main()
{
	char string[40];			// the best string array to ever exist
	char input;			// the worst input char to ever exist
	
	printf("Please enter a sentence with a maximum of 40 characters: ");		// politely asking for the string
	scanf("%[^\n]%*c", string);													// lets actually input that string into the array shall we?
	
	while(1)	// an INFINITE LOOP that only breaks when a or b is selected
	{
		printf("Please enter (a) CAPITALIZE or (b) Title Case: ");	// very kindly asking for a or b
		scanf(" %c", &input);										// I suppose we should scan for the input
		
		if(input == 'a')	// If 'a' was the button pressed on the key board
		{
			for(int index = 0; index < 40; index++) // A for loop checking ALL forty digits in the array
			{
				if (string[index] >= 'a' && string[index] <= 'z')	// we dont want ANY of those character to be lowercase do we?
					string[index] = string[index] - 32;				// so lets make em all uppercase! (using ASCII of course)
			}
			printf("Capitalized String: %s\n", string);				// and lets show all our hard work and print it to the screen
			break; 													// I suppose we should break that INFINITE LOOP
		}
		else if(input == 'b')	// If 'b' instead was the lucky character to be chosen
		{
			for(int index = 0; index < 40; index++)	// A for loop checking every single digit in a forty digit string (Thats a lot!)
			{
				if ((string[index] >= 'a' && string[index] <= 'z') && (index == 0 || string[index-1] == ' '))		// is that a lowercase letter at the start of a word? we cant have that
					string[index] = string[index] - 32;																// so lets change it to an uppercase
				else if((string[index] >= 'A' && string[index] <= 'Z') && !(index == 0 || string[index-1] == ' '))	// is that an uppercase letter anywhere else in the string?!?!?!?!
					string[index] = string[index] + 32;																// we CAN NOT tolerate that!!
			}
			printf("Title Cased String: %s\n", string);																// SHOW ME THAT TITLE CASED STRING 
			break;																									// lets get out of that pesky INFINTE LOOOOOOOP
		}
		else	// else you did something other than 'a' or 'b', what is wrong with you? why would you do something like this???
			printf("Woah there buddy looks like something went wrong, how 'bout you try that again?\n");	// ima let you know how dissapointed I am in you
	}
	
	return 0;
}
