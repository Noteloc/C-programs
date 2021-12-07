#include<stdio.h>
int main()
{
    int x;
    int *p;
    int y = 10;
    int *s = &y;
    x = 2;
    printf("variable x = %d\n", x);
    printf("variable y = %d\n", y);
    p = &x;
    printf("P contains the memory address of variable x (pointer) p = %p\n", p);
    *p = 5;
    printf(" variable x = %d\n", x);
    printf(" variable (pointer) p = %p\n", p);
    printf("Memory address of variable y = %p\n", &y);
    printf("Content of pointer variable s = %d\n", *s);
    printf("Memory address of pointer variable s = %p\n", s);
}