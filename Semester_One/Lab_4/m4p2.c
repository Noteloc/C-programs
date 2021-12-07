#include "header.h" // lets call my OWN header that I made special for this program

// our main is first?! how strange, it must be cause the protoytypes are in that header file
int main()
{
    char strings[AMOUNT][SIZE] = {'\0'};    // our first 2D array, and its a string array!
    getStrings(strings);                    // calling getStrings, This one is pretty easy to understand
    isPalindrome(strings);                  // calling isPalindrome, I think this one is self explanatory

    return 0;   // it just feels *weird* to have return 0 so high up in the program
}

// a function called getStrings, which will be getting strings, shocking I know. We pass it a 2D array
void getStrings(char strings[AMOUNT][SIZE])
{
    printf("Hey! You! enter %d strings (but dont go over %d characters or you'll be sorry!)\n", AMOUNT, SIZE);  // lets ask for some strings!
    for(int i=0; i<AMOUNT; i++) // our first for loop of the program, which will take AMOUNT strings
    {
        printf("Enter string %d: ", i+1);   // asking for strings
        scanf(" %[^\n]s", strings[i]);  // inputing the strings
    }
}

// a function that reverses the string that is inputted into it
void reverseStr(char string[SIZE])
{
    char reverse[SIZE] = {'\0'};    // a string called reverse to store the reversed string
    int count = 0;  // and a variable called count, to reverse te string
    for(int i=0;i<SIZE;i++) // a for loop that runs for the size of the string array
    {
        if(string[SIZE-i] != '\0')  // IF we are not at a NULL
        {
            reverse[count] = string[SIZE-i];    // then reverse the string
            count++;    // and increase count by one
        }
    }
    for(int i=0;i<SIZE;i++) // same as the previous for loop
        string[i] = reverse[i]; // and copy the reversed string into the string we wanted to reverse
}

// and a function that checks to see if a string is a palindrome
void isPalindrome(char strings[AMOUNT][SIZE])
{
    char test[SIZE] = {'\0'};   // a string called test that will be reversed so we can test the palindromeness of that string
    int flag = 0;   // a flag 0 = palindrome 1 = not a palindrome
    for(int row=0;row<AMOUNT;row++) // a for loop with rows for our 2D array needs
    {
        flag = 0;   // reset that flag to 0
        for(int i=0;i<SIZE;i++) // so many for loops im so happy
            test[i] = strings[row][i];  // lets copy a string into test
        reverseStr(test);   // and reverse test
        for(int i=0;test[i] != '\0';i++)    // while test[i] isnt null
            if(test[i] != strings[row][i])  // IF the reversed string at any point is different
                flag = 1;   // then flag is set to one
        if(flag == 1)   // if flag is 1 then its not a palindrome
            printf("%s is not a palindrome!\n", strings[row]);  // and we say as much
        else    // otherwise it IS a palindrome
            printf("%s is a palindrome!\n", strings[row]);  // so lets say that       
    }
}