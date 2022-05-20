#include <stdio.h>

int main()
{
    FILE *add;
    add = fopen("GPN.txt", "w");
    int value = 2;

    for (int i = 0; i < 82589933; i++)
    {
        value *= 2;
        printf("\n%d times done", i);
    }

    printf("\nThe greatest prime number is :- %d", value);
    fprintf(add, "The Largest Prime Number Is :- %d", value);
    return 0;
}