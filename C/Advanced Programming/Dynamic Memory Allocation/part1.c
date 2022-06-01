#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *name = (char *)malloc(100 * sizeof(char));
    printf("\nValue at Heap After Allocation: %s", name);
    printf("\nEnter Your Name: ");
    gets(name);
    name = (char *)realloc(name, (strlen(name) + 1) * sizeof(char));
    printf("\nValue at Heap Before Reallocation: %s", name);
    printf("\nGood Morning, %s", name);
    printf("\nYour Name Consists of %d Characters.", strlen(name));
    printf("\nValue at Heap After Freeing: %s", name);
    return 0;
}