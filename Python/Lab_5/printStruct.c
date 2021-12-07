#include "printStruct.h"

void printStruct(process myProcess, int childcount, temp myUnion)
{
    printf("This is the fanciest printing you have ever seen\n");
    printf("===============MYPROCESS==================\n");
    printf("\tNAME: %s\n", myProcess.name);
    printf("\tPID: %d\n", myProcess.pid);
    printf("\tPPID: %d\n", myProcess.ppid);
    printState(myProcess.state);

    for(int count = 0; count < childcount; count++)
    {
        printf("\t     Child Name: %s\n", myProcess.children[count]);
    }
    printf("===============MYPROCESS==================\n");
    printf("\n=============== MYUNION ==================\n");
    printf("\tmyUnion: %d %c\n", myUnion.count, myUnion.value);
    printf("\n=============== MYUNION ==================\n");
}