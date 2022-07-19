#include <stdio.h>
#include <stdlib.h>

void print(int *array, int size)
{
    printf("\n{%d", array[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", array[i]);
    }
    printf("}.");
}

void __Integer_Array_Sorter__Count_Sort__(int *array, int size)
{
    int highest_Element, current_Element, lowest_Element;
    lowest_Element = array[0];
    highest_Element = array[0];
    int *auxiliary_Array = NULL;

    for (int i = 0; i < size; i++)
    {
        current_Element = array[i];

        if (current_Element > highest_Element)
        {
            highest_Element = current_Element;
        }
        else if (current_Element < lowest_Element)
        {
            lowest_Element = current_Element;
        }
    }

    int auxiliary_Size = (highest_Element - lowest_Element) + 1;

    auxiliary_Array = (int *)malloc((auxiliary_Size * sizeof(int)));

    for (int i = 0; i < auxiliary_Size; i++)
    {
        auxiliary_Array[i] = 0;
    }

    int *auxiliary = &(auxiliary_Array[abs(lowest_Element)]);

    for (int i = 0; i < size; i++)
    {
        current_Element = array[i];
        auxiliary[current_Element]++;
    }
    int index = 0;

    for (int i = lowest_Element; i <= highest_Element; i++)
    {
        while (auxiliary[i] != 0)
        {
            auxiliary[i]--;
            array[index] = i;
            index++;
        }
    }
    free(auxiliary_Array);
}

int main()
{
    int arr[] = {-5, -4, 10, 100, -100};
    int size = (sizeof(arr) / sizeof(int));

    print(arr, size);
    __Integer_Array_Sorter__Count_Sort__(arr, size);
    print(arr, size);
    return 0;
}