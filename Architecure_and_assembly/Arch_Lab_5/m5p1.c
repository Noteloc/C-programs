#include <stdio.h>

int main()
{
    long int c, x=0, y=1, s=0;
    printf("Fib Numbers\n");
    for(c=10; c!=0; c--)
    {
        printf("%d\n", x);
        s = y+x;
        x = y;
        y = s;
    }
}