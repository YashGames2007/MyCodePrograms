#include <stdio.h>
#include <math.h>

int main()
{
    double number1 = 2;

    for (int i = 0; i < 933; i++)
    {
        number1 *= 2;
        printf("\nProcess 1 :- %d times.", i);
    }
    printf("\n");

    double number2 = pow(2, 1000);
    for (int i = 0; i < 82589; i++)
    {
        number2 *= pow(2, 1000);
        printf("\nProcess 2 :- %d times done.", i);
    }
    printf("\n");

    printf("\nThe Largest Prime Number is :- %f", number1 * number2);
    FILE *ptr;
    ptr = fopen("GPN.txt", "w");
    fprintf(ptr, "The Largest Prime Number is :- %f", number1 * number2);
    return 0;
}