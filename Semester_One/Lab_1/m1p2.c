#include<stdio.h>

int main()
{
	int input; // Variable for the users input
	
	printf("\n\t1. Reconaissance "); 								// A bunch of print lines to print the menu
	printf("\n\t2. Weaponization ");
	printf("\n\t3. Delivery ");
	printf("\n\t4. Instalation ");
	printf("\n\t5. Exploitation ");
	printf("\n\t6. Privilage Escalation ");
	printf("\n\t7. Command and Control ");
	printf("\n\t8. Quit ");
	printf("\n\tPrint the number associated with your choice: ");
	scanf("%d", &input);											// Taking the users input
	
	printf("\n\tYou entered: %d", input);							// Spitting it back out at them
	printf("\n\tThanks for accessing the program ... Quitting!\n");
	
	return 0;
}
