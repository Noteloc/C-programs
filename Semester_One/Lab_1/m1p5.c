#include<stdio.h>

int main(void)
{
	int valueInt = 2;
	float valueFloat = 25.8;
	
	printf("Float: %f, Integer: %d\n", valueFloat, valueInt);
	
	valueInt = (int) valueFloat;
	printf("Float: %f, Integer: %d\n", valueFloat, valueInt);

	// 1. I changed the INT variable to valueInt as well as all future referances to it
	// 2. I changed the FLOAT variable to valueFloat as well as all future referances to it
	// 3. I fixed line 6 by swaping the '-' with a '=' and adding a ';' at the end
	
	// Question 1: line 10 is casting the FLOAT value as an INT to properly store the value in the INT variable
	// Question 2: the output is different in line 11 because the value of the INT variable has changed to equal that of the FLOAT variable

	
	return 0;
}
