#include <stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("sample1.txt", "w");
    int number = 45;
    fprintf(ptr, "The number is : %d", number);
    fclose(ptr);

    return 0;
}