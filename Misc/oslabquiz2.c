#include <stdio.h>
#include <pthread.h>
#include <ctype.h>
#include <stdlib.h>

void *get_character(void *m)
{
    int c;
    while((c = getchar()) !='Q')
        putchar(c);
    return m;
}

int main()
{
    void *m;
    pthread_t t1;
    pthread_create(&t1, NULL, get_character, (void *) m);
    pthread_join(t1, NULL);
}