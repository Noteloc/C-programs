#include <stdio.h> // this is a libary call so we can use functions such as printf

main () // this is the main function
{
    int c,n = 0; // this is declaring two integer variables and setting them to 0
    while (( c= getchar()) !='Q' ) // a loop that will loop as long as the character Q isnt entered
    printf(" char %3d is character %c with ascii code %d\n", n++, c,c); // prints out how many characters entered, the character and the ascii code
}