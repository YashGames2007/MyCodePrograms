#include <stdio.h>

int file_Counter(FILE *add);
void file_Printer(FILE *add);
int main()
{
    FILE *txt;
    txt = fopen("sample1.txt", "r");
    int count = file_Counter(txt);
    printf("\nTotal number of characters are : %d", count);
    file_Printer(txt);
    
    return 0;
}
int file_Counter(FILE *add)
{
    char c;
    int count = 0;
    printf("\n");
    while (c != EOF)
    {
        c = fgetc(add);
        printf("%c", c);
        count ++;
    }
    return count;   
}
void file_Printer(FILE *add)
{
    char c;
    int count = 0;
    printf("\n");
    while (c != EOF)
    {
        c = fgetc(add);
        printf("%c", c);
        count ++;
    }
}
