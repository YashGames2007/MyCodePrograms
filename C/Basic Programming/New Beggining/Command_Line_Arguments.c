#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        if (argc != 4)
        {
            printf("\nInvalid Arguments!");
        }
        else
        {
            char operator[5];
            strcpy(operator, argv[1]);
            long double operand1 = strtold(argv[2], NULL);
            long double operand2 = strtold(argv[3], NULL);
            if (strcmp(operator, "add") == 0)
            {
                printf("%Lf", operand1 + operand2);
            }
            else if (strcmp(operator, "sub") == 0)
            {
                printf("%Lf", operand1 - operand2);
            }
            else if (strcmp(operator, "mul") == 0)
            {
                printf("%Lf", operand1 * operand2);
            }
            else if (strcmp(operator, "div") == 0)
            {
                printf("%Lf", operand1 / operand2);
            }
            else
            {
                printf("\nInvalid Operator!");
            } 
        }
    }
    return 0;
}