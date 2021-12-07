#include<stdio.h>
#include<string.h>

int functionA(void)
{
    int value = 100;

    value += 1;
    return value;
}

int functionB(void)
{
    static int value = 100;

    value += 1;
    return value;
}

int main()
{
    for(int i=0; i<5; i++)
    {   
        printf("[FUNA] The value now is: %d\n", functionA());
    }
    printf("\n");
    for(int i=0; i<5; i++)
    {
        printf("[FUNB] The value now is: %d\n", functionB());
    }
    return 0;
}
/*
1. The static keyword seems to act like a global variable, and it remembers the value stored in it on mulitiple itterations of the function
2. functionA and functionB neither return a value, they are both void types
3. functionA and functionB both take nothing as an argument type, hence the VOID
*NOTE* these answers are for the original code, not the modified code that 4. and 5. ask us to make
*/