#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX 10

int i=12345;
double y=1.23456;

void display_variables() 
{
    double y=4.352;
    printf("i=%d, y=%f\n", i,y);
}

int fib(int n)
{
    if ( n == 0 )
        return 0;
    else if ( n == 1 )
        return 1;
    else    
        return ( fib(n-1) + fib(n-2) );
}

int main()
{
    printf("i=%d, y=%f", i,y);
    display_variables();
    int c,i=0;
    for (c = 0; c <= MAX; c++)
    {
        printf("%d\n", fib(i));
        i++;
    }

    if(fork() == 0)
    {
        int c,i=0;
        for (c = 0; c <= MAX; c++)
        {
            printf("%d\n", fib(i));
            i++;
        }
        sleep(3);
    }
    else
    {
        wait(NULL);
    }

    return 0;
}
