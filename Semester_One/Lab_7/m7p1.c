#include<stdio.h>

void scan()
{
    FILE *fptr = fopen("numbers.txt", "rb");
    FILE *fptrAbove = fopen("above60.txt", "w");
    FILE *fptrBelow = fopen("below60.txt", "w");
    float buffer;
    int count = 0;
    int belowCount = 0;
    int aboveCount = 0;

    while(!feof(fptr))
    {
        fread(&buffer, 4, 1, fptr);
        if(buffer < 60)
        {
            fprintf(fptrBelow, "Position: %d\t\tNum: %0.2f\n", belowCount+1, buffer);
            belowCount++;
        }
        else if(buffer >= 60)
        {
            fprintf(fptrAbove, "Position: %d\t\tNum: %0.2f\n", aboveCount+1, buffer);
            aboveCount++;
        }
        count++;
    }
    printf("Number of floats in the file numbers.txt: %d\n", count);
    printf("Number of lines in the file below60.txt: %d\n", belowCount);
    printf("Number of lines in the file above60.txt: %d\n", aboveCount);

    fclose(fptr);
    fclose(fptrAbove);
    fclose(fptrBelow);
}

int main()
{
    scan();

    return 0;
}