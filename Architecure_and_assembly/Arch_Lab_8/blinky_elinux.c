/* blinky_elinux.c                                                                      
 * 	Raspberry Pi GPIO example using sysfs interface.
 * Original_Author: Guillermo A. Amaral B. <g@maral.me>
 * Modified By: Gary Rowe
 * 	Description:   Raspberry Pi GPIO example using sysfs interface.
 * 	Reference: https://elinux.org/RPi_GPIO_Code_Samples
 */
#include "blinky_elinux.h"

int main(int argc, char *argv[])
{
	int repeat = 10;

	 // Enable GPIO pins
	int pin[] = {4, 17, 27, 5};
	int direction[] = {0, 0, 0, 0};
	int retval = 0;
	int size = sizeof(pin)/sizeof(int);

	printf("Enter direction for ports 4 17 27 5: ");
    scanf("%d %d %d %d", &direction[0], &direction[1], &direction[2], &direction[3]);	

	if( retval = GPIOSetup(pin, direction, size) != 0)
		return(retval); 
	do 
	{
		// Write GPIO value
		for(int count = 0; count < sizeof(pin)/sizeof(int); count++)
			if (-1 == GPIOWrite(pin[count], repeat % 2))
				return(3);
		usleep(500 * 1000);
	}while (repeat--);

	// Disable GPIO pins
	for(int count = 0; count < sizeof(pin)/sizeof(int); count++)
	{
		if (-1 == GPIOUnexport(pin[count]) )
		{
			printf("Can't release resources -> Pin %d\n", pin[count]);
			return(4);
		}
	}
	return(0);
}

