#include<stdio.h>

int main()
{
    int z=0, y=10, *p, *s;
    p = &z;
    printf("The address of z is %p \n", &z);
    *p = 13;
    s = &y;
    s = p;
    p = &y;

    printf("The memory address of p is %p \n", &p);
    printf("The memory address of s is %p \n", &s);

    return 0;
}