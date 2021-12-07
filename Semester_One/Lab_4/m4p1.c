#include<stdio.h>   // once more, under the bridge, we start with include stdio.h

#define SIZE 12     // it gets *real* annoying to type out 12 over and over again so instead lets do SIZE

// The FIRST function, it is passed two arrays and an integer of how much girth we got in those arrays, then prints those arrays out in a pleasing format
void printNums(float array[], float sortedArray[], int size)
{
    printf("Unsorted\tSorted\n");   // Just some formatting here
    printf("========\t======\n");   // pay no attention to the formatting behind the curtain
    for(int i=0; i<size; i++)   // WOO a for loop! that will run based on the size of the arrays
    {
        printf("%.2f", array[i]);   // print out that first array
        printf("\t\t%.2f\n", sortedArray[i]);   // and of course print out that second array
    }
}

// ANOTHER function, it sorts an array and it is passed an array (just one this time) and the size of said array we talked about previously in this same sentance
void sortNums(float array[], int size)
{
    int flag = 0;   // an int to act as a flag cause we got no bools
    float buffer = 0;   // a float to act as a buffer cause we need to swap some values
    float sorted[size]; // a whole array of floats to, as the name implies, store our sorted values
    for(int i=0; i<size; i++)   // a for loop (oh yeah) that runs based off of the size of the array
        sorted[i] = array[i];   // lets copy that array into the other array that we need to be the same as the first array
    while(flag == 0)    // while that flag is not a one or a two or a three or a four or ... we gonna run this loop
    {
        flag = 1;   // wow that flag is now a one 
        for(int i=0; i<size; i++)   // weve done this all before, do I even need to say what this is?
        {
            if(sorted[i] < sorted [i+1])    // IF the index we are looking at is less than the next index
            {
                flag = 0;   // then that flag goes back to zero
                buffer = sorted[i];     // AND 
                sorted[i] = sorted[i+1];    // WE
                sorted[i+1] = buffer;   // SORT (the bubble kind)
            }
        }
    }
    printNums(array, sorted, size); // lets call the function printNums, to print our nums
}

// the LAST function, it takes an array from the user, and is passed the orginal array that will be storing the array that will be inputted
int getNums(float input[])
{
    int count = 0;  // an integer called count, which will do its job and count the size of the array
    printf("Enter up to 12 different numbers, or a zero if you are a rebel and want to end early\n");   // askiong for dat input
    printf("====================================================================================\n");   // and formatting looking so nice
    for(int i=0; i<SIZE; i++)   // uppercase SIZE this time cause we dont want it to be more than 12
    {
        printf("Enter number %d: ", i+1);   // ask for the number
        scanf(" %f", &input[i]);    // and take that number
        if(input[i] == 0)   // IF they were a rebel and inputted 0
            break;  // then we break. THE. LOOOOOOOOOOOP!
        count++;    // lets count to see how big the *inputted* array is
    }
    sortNums(input, count); // and now we call sortNums from getNums
    return count;   // and finally we are returning the size of the array
}

// Our main function, and it looks so small
int main()
{
    float input[SIZE] = {0};    // lets start with an array
    getNums(input); // and pass that array into the functions to start the chain of what we doing

    return 0; // and end it all with a return 0
} 