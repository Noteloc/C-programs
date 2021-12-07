#include<stdio.h>

void summary(unsigned char magic[], int textCount, int count, FILE *fptr)
{
    float percent = (float)textCount / count;
    printf("\nMagic Number: 0x");
    for(int i=0; i<4; i++)
        printf("%02X", magic[i]);

    if(percent > 0.75)
        printf("\nThis is definitely a text file\n");
    else if(percent > 0.25)
        printf("\nThis is probably a text file\n");
    else
        printf("\nThis is definitely a binary file\n");
    fclose(fptr);
}

void read(FILE *fptr)
{
    unsigned char hexOutput[17] = {'\0'};
    unsigned char magic[4] = {'\0'};
    unsigned char ascii[17] = {'\0'};
    int count = 0;
    int textCount = 0;

    printf("\nOffset\tHexadecimal data format\t\t\t\t\tCharacter Format\n");
    printf("________________________________________________________________\n");

    fread(magic, 1, 4, fptr);
    rewind(fptr);
    while(fread(hexOutput, 1, 16, fptr))
    {
        printf("%05X\t", count);
        for(int i=0; i<16; i++)
        {
            printf("%02X ", hexOutput[i]);
            if(hexOutput[i] < 31 || hexOutput[i] > 127)
                ascii[i] = '.';
            else
            {
               ascii[i] = hexOutput[i]; 
               textCount++;
            }
            count++;
        }
        printf("\t\t| %s |\n", ascii);
        for(int i=0; i<16; i++)
        {
            hexOutput[i] = '\0';
            ascii[i] = '\0';
        }
    }
    summary(magic, textCount, count, fptr);
}

void openFile()
{
    char name[10];
    printf("Please enter the name of the file to open: ");
    scanf(" %s", name);
    FILE *fptr = fopen(name, "r");
    read(fptr);
}

int main()
{
    openFile();
    return 0;
}