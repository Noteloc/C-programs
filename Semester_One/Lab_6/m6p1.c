#include<stdio.h>
#include<string.h>
#include<stdlib.h>  // These are all the libraries we are using in this program, I know you were hoping for the calgary central library but I had a hard time fitting it in this program

void add(char *args[], char final[], int loc)   // This function is adding a string onto our base string, so simple it doesnt even need to be in a function
{
    strcat(final, args[loc+1]); // uses the strcat function, because whoever made that is smarter than me
}

void sub(char *args[], char final[], int loc)   // This function subtracts a substring from our string, this one is complicated to hang on tight
{
    char *ptr;  // Declaring a pointer and calling it pointer, so origanal
    int len = strlen(args[loc+1]);  // Making an INT called length and setting to the length (who woulda thunk) of the substring we are deleting

    if(ptr = strstr(final, args[loc+1]))    // Now this one is complicated, what this is doing is IF (by using strstr) we find the substring within the string, then assign ptr to point to the start of that substring and then execute the code block below
    {
        *ptr = '\0';    // change the value of the first character of the substring to NULL (gone, reduced to atoms)
        strcat(final, ptr+len); // then finally strcat the rest of the string AFTER the substring onto the end of the string BEFORE the substring (Not to brag but this is pure genius here)
    }   // Right now this is only removing the first instance of the substring, if I wanted to remove ALL instances of the substring I would replace the IF with a WHILE, and that works fine
}

void mult(char *args[], char final[], int loc)  // This function multiplies the string before the * by the number after the *
{
    for(int i=1; i<strtol(args[loc+1], NULL, 10); i++)  // this loop will iterate until i is no longer smaller than the value of the number after the *, I use the strtol because the computer is stupid
        strcat(final, args[loc-1]); // strcat's the string onto the string
}

int main(int argc, char *argv[])    // arguments baby!!!
{
    char final[100];    // A string to store the finished string in, I set it 100 cause IDK
    strcpy(final, argv[1]); // We are gonna copy the first argument into the string to do thngs with

    for(int i=0; i<argc; i++)   // check every arguement
        if(*argv[i] == '*') // IF it sees a * symbol thing
            mult(argv, final, i);   // Then do the mult function
    
    for(int i=0; i<argc; i++)   // Same as before, do I really need to repeat it?
    {
        if(*argv[i] == '+')         // IF it sees a +
            add(argv, final, i);    // then do add
        else if(*argv[i] == '-')    // IF it sees a -
            sub(argv, final, i);    // then do sub
    }

    printf("Final String: %s\n", final);    // then at last print out the final product

    return 0;
}