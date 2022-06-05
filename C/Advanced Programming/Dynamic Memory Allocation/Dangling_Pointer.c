#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *ptr;
    {
        int *i = (int *)malloc(sizeof(int));
        *i = 5;
        ptr = i;
        printf("\nPointer Value: %x", ptr);
        printf("\nVariable Value: %d", *ptr);
        free(i);
        // free(ptr);
    }
    printf("\nPointer Value: %x", ptr);
    *ptr = 5;
    printf("\nVariable Value: %d", *ptr);
    return 0;
}