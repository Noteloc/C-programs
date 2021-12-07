#include<stdio.h>

int main()
{
	
	for(int c=0; c<5; c++)
	{
		for(int r=0; r<8; r++)
		{
			if(c == 0 || c == 4)
			{	
				printf("*");
			}
			else if((c == 1 || c == 3) && (r == 0 || r == 7))
			{
				printf(" ");
			}
			else if((c == 1 || c == 3) && !(r == 0 || r == 7))
			{
				printf("*");
			}
			else if((c == 2) && (r == 3 || r == 4))
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
