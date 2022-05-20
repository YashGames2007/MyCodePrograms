#include <stdio.h>

void function(int *dimension_Array, int dimension, int value, int *value_Array);
int main()
{
    int dimension_Array[] = {2, 2, 5};
    int dimension = 3;
    int value = 6;
    int value_Array[dimension];
    function(&dimension_Array[0], dimension, value, &value_Array[0]);

    printf("The element at index ");
    for (int j = 0; j < dimension; j++)
    {
        printf("[%d]", value_Array[j]);
    }
    printf(" is : %d", value);

    return 0;
}
void function(int *dimension_Array, int dimension, int value, int *value_Array)
{
    int total = 1;

    for (int a = 0; a < dimension; a++)
    {
        total *= dimension_Array[a];
    }
    printf("Total = %d\n", total);
    int temp;
    for (int i = 0; i < dimension; i++)
    {
        total = total / dimension_Array[i];
        temp = value / total;
        value_Array[i] = temp;
        value = value % total;
    }
}