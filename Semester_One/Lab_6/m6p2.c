#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void write(int start, int end, int step, char name[])   // the WRITE function to write to the file
{
    FILE *fptr = fopen(name, "w");   // make a FILE pointer and point it at the file we are gonna write to

    while(start<=end)   // WHILE start is less than or equal to end
    {   
        fprintf(fptr, "%d", start); // Print the number that was inputted
        fprintf(fptr, "%c", '\n');   // then print a new line to seperate them
        start += step;  // then increase start by the step value
    }
    fprintf(fptr, "%c", '\0');  // then end the file with a null character to tell the program later to stop reading
    fclose(fptr);   // then close the file - we dont need no stinking files
    exit(1);    // then lets get outta dodge
}

void read(char name[])  // the READ function to, you guessed it, read the contents of the file
{
    int nums;    // a INT to help us print out the numbers in the file
    char garbage = '\n';    // a CHAR to remove the newlines in the file
    FILE *fptr = fopen(name, "r");  // open that file!
    if(fptr == NULL)    // IF the file doesnt exist
        printf("File not found!\n");    // tell em so
    else    
    {
        while(garbage != '\0')  // WHILE the garbage char doesnt have null in it
        {
            fscanf(fptr, "%d", &nums);  // Scan for a number
            printf("%d ", nums);    // Print that number
            fscanf(fptr, "%c", &garbage);   // then scan for a character
        }
    }
    printf("\n");   // print out a newline to clean up the formatting
    fclose(fptr);   // CLOSE THAT FILE!!
    exit(1);    // lets blow this popsicle stand
}

int main(int argc, char *argv[])
{
    int start, startFlag = 0;  // an int for the start argument
    int end, endFlag = 0;    // one for the end
    int step, stepFlag = 0;   // and the step
    char name[100] = {'\0'};    // and a string for the array
    int nameFlag = 0;   // all these flag values are for checking to see if they have been entered or if the user is stupid

    for(int i=1; i<argc; i++)   // itterates until i is no longer smaller than the amount of arguments
    {
        if(strcmp(argv[i], "-b") == 0)  // IF it sees a -b
        {
            start = strtol(argv[i+1], NULL, 10);    // then get the number accociated with it
            startFlag = 1;  // and set the flag to 1
        }
        else if(strcmp(argv[i], "-e") == 0) // same with -e
        {
            end = strtol(argv[i+1], NULL, 10);
            endFlag = 1;
        }
        else if(strcmp(argv[i], "-s") == 0) // and with -s
        {
            step = strtol(argv[i+1], NULL, 10);
            stepFlag = 1;
            if(start + step > end)  // IF the start value and the step value is bigger than the end value
            {
                printf("Step size doesn't allow program to iterate once!\n");   // then let the user know that the error is telling them they stupid
                exit(1);    // and EXIT
            }
        }
        else if(strcmp(argv[i], "-f") == 0) // and finally with -f
        {
            strcpy(name, argv[i+1]);  
            nameFlag = 1;  
        }
    }

    for(int i=1; i<argc; i++)   // same as the other guy (for loop)
    {
        if(strcmp(argv[i], "-m") == 0)  // if it sees a -m amoung the arguments
        {
            if(*argv[i+1] == 'r')   // if its r
            {
                read(name); // then read
            }
            else if(*argv[i+1] == 'w')  // if its w
            {
                if(startFlag != 1)  // check the flags
                    printf("Range start value is missing!\n");  // and let the user know they messed up
                if(endFlag != 1)
                    printf("Range end value is missing!\n");
                if(stepFlag != 1)
                    printf("Step size value is missing!\n");
                if(nameFlag != 1)
                    printf("Name of file is missing!\n");
                if(!(startFlag != 1) && !(endFlag != 1) && !(stepFlag != 1) && !(nameFlag != 1))    // IF none are one
                    write(start, end, step, name); // then write
                else
                {
                    printf("Please try again\n");   // ELSE exit the program
                    exit(1);
                }
            }
        }
    }
    printf("Error, you have to say whether to read (r) or write (w)\n");    // print out an error if they dindnt do the -m properly

    return 0;
}