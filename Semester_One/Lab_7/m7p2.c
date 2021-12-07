#include<stdio.h>
#include<string.h>

void getInput(char *name)
{
    printf("Please enter the first letter of a name: ");
    scanf(" %c", name);
}

void scan(FILE *writeFptr, FILE *readFptr, char *name)
{
    char read[20];
    char write[20];
    int count = 0;

    while(fscanf(readFptr, "%s", read) != EOF)
    {
        if(read[0] == *name)
        {
            fscanf(writeFptr, "%s", write);
            if(!strcasecmp(read, write) == 0)
                fprintf(writeFptr, "%s\n", read);
            if(strlen(read) > 5)
                printf("%s\n", read);
                count++;
        }
    }
    printf("Names found: %d\n", count);
    fclose(writeFptr);
    fclose(readFptr);
}

void openFile(char *name)
{
    FILE *fptr = fopen("names.txt", "r");
    FILE *writeFptr = NULL;
    char file[10];
    sprintf(file, "%cname.txt", *name);
    writeFptr = fopen(file, "a");

    scan(writeFptr, fptr, name);
}

int main()
{
    char name = 'a';
    char *ptr = &name;
    getInput(ptr);
    openFile(ptr);

    return 0;
}