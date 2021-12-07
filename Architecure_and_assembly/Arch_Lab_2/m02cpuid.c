#include<stdio.h>
#include<stdlib.h>

int main()
{
    int EAX, EBX, ECX, EDX, requestCode;

    printf("Enter request code: ");
    scanf(" %X", &requestCode);
    
    __asm__ volatile(
                    "cpuid"
                    : "=a"(EAX), "=b"(EBX), "=c"(ECX), "=d"(EDX)
                    : "0"(requestCode)
                    ); // This is inline assembly …. 
                    
    printf("EAX = %X\n", EAX);
    printf("EBX = %X\n", EBX);
    printf("ECX = %X\n", ECX);
    printf("EDX = %X\n", EDX);
}