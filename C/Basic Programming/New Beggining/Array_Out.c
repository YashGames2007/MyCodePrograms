#include <stdio.h>

void array_Printer(int *array, int *dimension_Array, int dimension);
void dimension_Updater(int *total_Dimensions, int *current_Dimension);

int main()
{
    int array[2][3] = {{{4, 3}, {3, 5}, {7, 8}}, {{4, 3}, {3, 5}, {7, 8}}};
    int dimension_Array[2] = {2, 3};
    int total_Dimensions = 2;
    array_Printer(array, dimension_Array, total_Dimensions);
    return 0;
}
void array_Printer(int *array, int *dimension_Array, int dimension)
{
    int current_Dimension_Array[dimension];
    int current_Dimension = 0;
    for (int i = 0; i < dimension; i++)
    {
        current_Dimension_Array[i] = 0;
    }
    printf("\n{");
    for (int i = 0; i < current_Dimension_Array[current_Dimension]; i++)
    {
        if (dimension_Check(dimension_Array, current_Dimension_Array, dimension))
        {
            printf("\n");
        }
        
    }
    
    
}
void dimension_Updater(int *total_Dimensions, int *current_Dimension)
{

}