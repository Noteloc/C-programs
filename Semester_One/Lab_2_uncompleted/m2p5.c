#include <stdio.h>

int main()
{
	int input = 0;
	int rem;
	
	while(input <= 65535)
	{
		printf("Please enter a number between 0 and 65535: ");
		scanf("%d", &input);
		
		if(input > 65535)
			break;
			
		
		for(int i=0; i<16; i++)
		{
			rem = input%2;	
			input = input/2;
			
			printf("%d", rem);
		}
		printf("\n");
	}
	
	return 0;
}
