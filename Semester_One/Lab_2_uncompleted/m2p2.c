#include<stdio.h>

int main()
{
	for(int c=0; c<5; c++)
	{
		for(int r=0; r<5; r++)
		{
			if((c == 0 || c == 4) || ((c == 1 || c == 3) && (r == 1 || r == 3)) || ((c == 2) && (r == 0 || r == 2 || r == 4)))
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
