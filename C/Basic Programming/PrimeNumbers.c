#include <stdio.h>
#include <time.h>

void array_Printer(int *array, int *dimension_array, int dimension);
void function(int *dimension_array, int dimension, int value, int *value_array);

int main()
{
    int from, to;
    printf("\nType the list starts from :- ");
    scanf("%d", &from);
    printf("\nType the list ends to :- ");
    scanf("%d", &to);

    time_t start, end;
    start = time(NULL);

    int primenumbers[to - from];
    int primes = 0;
    int isprime = 1; // 1 if true, 0 if false.
    int factor;
    int number = from;
    int multiple;
    int index = 0;

    while (number <= to)
    {
        factor = 2;
        isprime = 1;
        while (factor <= ((int)(number / 2)))
        {
            multiple = 1;

            while ((multiple * factor) < number)
            {
                multiple += 1;
            }
            if ((multiple * factor) == number)
            {
                isprime = 0;
                break;
            }
            else
            {
                factor += 1;
            }
        }
        if (isprime && number >= factor)
        {
            primenumbers[index] = number;
            printf("\n%d :- Prime", number);
            index += 1;
            number += 1;
            primes += 1;
        }
        else
        {
            printf("\n%d :- Composite", number);
            number += 1;
        }
    }
    printf("\nnumber of primes :- %d", primes);
    int dimarr[] = {primes};
    array_Printer(&primenumbers[0], &dimarr[0], 1);
    end = time(NULL);
    printf("\nThe Time required to find %d prime numbers is %d.", primes,(difftime(end, start)));

    return 0;
}
void array_Printer(int *array, int *dimension_array, int dimension)
{
    int total = 1;
    int value_array[dimension];
    FILE *tt;
    tt = fopen("Array.txt", "w");
    for (int a = 0; a < dimension; a++)
    {
        total *= dimension_array[a];
    }
    for (int i = 0; i < total; i++)
    {

        int value_array[dimension];
        function(dimension_array, dimension, i, &value_array[0]);
        fprintf(tt, "The element at index ");
        for (int i = 0; i < dimension; i++)
        {
            fprintf(tt, "[%d]", value_array[i]);
        }
        fprintf(tt, " is : %d\n", *array);
        array++;
    }
    fclose(tt);
}
void function(int *dimension_array, int dimension, int value, int *value_array)
{
    int total = 1;
    int temp;
    for (int a = 0; a < dimension; a++)
    {
        total *= dimension_array[a];
    }
    for (int i = 0; i < dimension; i++)
    {
        total = total / dimension_array[i];
        temp = value / total;
        value_array[i] = temp;
        value = value % total;
    }
}