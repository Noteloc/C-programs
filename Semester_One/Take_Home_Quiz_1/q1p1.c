#include<stdio.h>
#include<string.h>
#include<strings.h>

#define SIZE 100

void getInput(char *input);

int checkDictionary(char arrChar[][20], char *guess, int rows);

void insertWord(char arrChar[][20], int rows);

int main()
{
    char dictionary[SIZE][20] = {{"Around"}, {"Pool"}, {"LifeGuard"}, {"Strangers"}, {"Ordered"}, {"Marbles"}, {"Somewhere"}, {"Futuristic"}, {"Unrealistic"}, {"Definition"}, {"Surprise"}};;
    char user[20] = {'\0'};
    char *input = user;
    int rows = 11;
    int choice = 1;

    while(choice != 0)
    {
        printf("Please enter a choice\n\n(1) Find a word in the dictionary\n(2) Add a word to the dictionary\n(0) Exit\n");
        scanf(" %d", &choice);
        if(choice == 1)
            printf("Word found at: %d\n", checkDictionary(dictionary, input, rows));
        if(choice == 2)
        {
            insertWord(dictionary, rows);
            rows++;
        }
    }
    return 0;
}

void getInput(char *input)
{
    printf("Please enter a word: ");
    scanf(" %[^\n]s", input);

    return;
}

int checkDictionary(char arrChar[][20], char *guess, int rows)
{
    int found = 0;
    int flag = 0;
    getInput(guess);
    for(int i=0; i<rows; i++)
    {
        found++;
        if(strcasecmp(guess, arrChar[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("Word not found\n");
        found = 0;
    }
    return found;
}

void insertWord(char arrChar[][20], int rows)
{
    char input[20];
    getInput(input);

    strcpy(arrChar[rows], input);
    return;
}
