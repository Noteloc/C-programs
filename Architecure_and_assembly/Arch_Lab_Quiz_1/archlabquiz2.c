#include<stdio.h>

char fun2(int num1, char ch1, short int val1)
{
    printf("Hex values passed: %#04x %#04x %#04x\n", num1, ch1, val1);
    if(val1 < 0x1122)
        return num1 + ch1 + val1;
    return num1 * 20;
}

int fun1(int num1, int num2, int num3)
{
    printf("Nums passed: %d %d %d\n", num1, num2, num3);
    int localfun1 = fun2(num1, (char)num2, (short)num3);
    return (num1 +num2+num3+ localfun1);
}

int main()
{
    int index, num = 1;
    for(index = 1; index < 3; index++)
    {
        num = num * index;
    }
    index = fun1(num, num * 2, num * 3);
    printf("Value of num: %d and index = %d\n", num, index);
}