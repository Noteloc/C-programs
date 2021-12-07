#include<stdio.h>

int main()
{
	int input = 0; 
	int sum = 0;
	
	for(int i=1; i<11; i++)
	{
		printf("Please enter number %d: ", i);
		scanf("%d", &input);
		sum += input;
	}
	
	printf("Sum is: %d\n", sum);
	if(sum % 2 == 0)
		printf("The number is even\n");
	else
		printf("The number is odd\n");
	
	printf("The average is: %.2f\n", (float)sum/10);

	return 0;
}
