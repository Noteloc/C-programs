#include<stdio.h>   // we got SO MANY includes this time
#include<stdlib.h>  // gone are the days of just stdio.h
#include<time.h>    // a new era has dawned

#define SIZE 30 // SIZE is 30, cause reasons

// the challange function to do weird things in cause reasons
void challenge()
{
    char input[200] = {'\0'};   // make a input string and set it to 200 cause reasons
    char answer1[] = {"King Arthur"};   // the first answer is King Arthur cause reasons
    char answer2[] = {"To seek the Holy Grail"};    // the second answer is to seek the Holy Grail cause reasons
    char answer3[] = {"African or European?"};  // the third answer is African or European? cause reasons
    int flag = 0;   // we have a flag to detirmine if they got the answer right cause reasons
    srand(time(NULL));  // random seed cause reasons
    int random = rand()%3;  // random number between 0-2 cause reasons
    if(random == 0) // IF the random seed was 0 do the first question cause reasons
    { 
        printf("What is your name?\n"); // print out the question cause reasons
        scanf(" %[^\n]s", input);   // take that input cause reasons
        for(int i=0;input[i] != '\0';i++)   // a for loop to test everything until it hits a null cause reasons
        {
            if(input[i] != answer1[i])  // IF it does not match cause reasons
                flag = 1;   // flag is set to one cause reasons
        }
        if(flag == 0)   // IF flag is 0 cause reasons
        {
            printf("Right, off you go\n");  // print out that you got the question right cause reasons
            exit(-1);   // and exit the program cause reasons
        }
    }
    else if(random == 1)    // same as the last one just with the 2 question cause reasons
    {
        printf("What is your quest?\n");
        scanf(" %[^\n]s", input);
        for(int i=0;input[i] != '\0';i++)
        {
            if(input[i] != answer2[i])
                flag = 1;
        }
        if(flag == 0)
        {
            printf("Right, off you go\n");
            exit(-1);
        }
    }
    else if(random == 2)    // and again same just with question 3 cause reasons
    {
        printf("What is the average air speed of an unladen swallow?\n");
        scanf(" %[^\n]s", input);
        for(int i=0;input[i] != '\0';i++)
        {
            if(input[i] != answer3[i])
                flag = 1;
        }
        if(flag == 0)
        {
            printf("Right, off you go\n");
            exit(-1);
        }
    }
}

// a function to get a string of random chars, cause reasons
void randchars()
{
    char random[SIZE] = {'\0'}; // start with as string cause reasons
    srand(time(NULL));  // random number generator cause reasons
    for(int i=0;i<SIZE;i++) // loop for the size of the string cause reasons
        random[i] = rand()%SIZE+'a';    // random character cause reasons
    for(int i=0;i<SIZE;i++) // loop for the size of the string cause reasons
        printf("%c", random[i]); // print out that random character cause reasons
    printf("\n");   // print out a new line cause reasons
}

// a function to get input cause reasons
void getInput(char string[])
{
    printf("Enter a string... ");   // asking for input cause reasons
    scanf(" %[^\n]s", string);  // taking that input cause reasons
}

// a function to convert the inputted string to a weird value cause reasons
void convert(char string[])
{
    int value = 0;  // a integer to store the weird value we calculate cause reasons
    int length = 0; // a integer to store the length of the string cause reasons
    for(int i=0; string[i] != '\0'; i++)    // a for loop that will run until it hits a null cause reasons
        length++;   // every itteration increase length by one cause reasons
    for(int i=0; i<=length; i++)    // a for loop that will run for the length of the string cause reasons
        value += string[i] * (length - i);  // calculate that weird value cause reasons
    if(value == 8470)   // if the weird value we calculated is 8470 cause reasons
    {
        challenge();    // do the challenge function cause reasons
        exit(-1);   // then exit the program cause reasons
    }
    else    // else cause reasons
    {
        printf("Welcome ... you may proceed\n");    // print out that message cause reasons
        randchars();    // then call randchars cause reasons
    }
}

// the main function cause reasons
int main()
{
    char string[SIZE];  // a string cause reasons
    int count = 0;  // an integer called count to count ittereations cause reasons
    while(count < 3)    //while count is less than 3 cause reasons
    {
        getInput(string);   // do getInput cause reasons
        convert(string);    // then convert cause reasons
        count++;    // then add one to count
        if(count == 3)   // and if count has reached 3 cause reasons
            exit(-1);   // exit cause reasons
    }
   
    return 0;
}
/*
 By "good" do you mean does it work? because if so then yes, if you mean does it serve a purpose? then no. its just random nonsense that doesnt do anything
 you may have noticed many "cause reasons" this time, thats cause I have no idea why we are doing any of this its complete nonsense
*/