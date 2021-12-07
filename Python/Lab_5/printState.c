#include "printStruct.h"

void printState(char state)
{
    if(state == 'Z')
        printf("\tSTATE: Zombie\n");
    else if(state == 'I')
        printf("\tSTATE: Idle\n");
    else if(state == 'R')
        printf("\tSTATE: Running\n");
    else if(state == 'S')
        printf("\tSTATE: Sleeping\n");
    else
        printf("\tSTATE: ERROR\n");
}