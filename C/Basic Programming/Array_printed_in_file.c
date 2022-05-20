#include <stdio.h>

void array_Printer(int *array, int *dimension_array, int dimension);
void function(int *dimension_array, int dimension, int value, int *value_array);

int main()
{
    int dimension = 1;
    int arr[] = {10};
    int array[10];
    int *ptr = &array[0];
    for (int i = 0; i < 10; i++)
    {
        *ptr = i + 1;
        ptr++;
    }

    array_Printer(&array[0], &arr[0], dimension);
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