#include <stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("sample1.txt", "r");
    if (ptr == NULL)
    {
        printf("\nThe file does not exist.");
    }
    else
    {
        int number;
        fscanf(ptr, "%d", &number);
        int number2;
        fscanf(ptr, "%d", &number2);
        printf("\n%d & %d", number, number2);
        fclose(ptr);
    }
    return 0;
}