#include <stdio.h>

void print(int *array, int size)
{
    printf("\n{%d", array[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", array[i]);
    }
    printf("}.");
}

void __Integer_Array_Sorter__Merger__Merge_Algorithm__(int *array, int size_A, int size_B)
{
    if ((size_A == 1) && (size_B  == 1))
    {
        if (array[0] > array[1])
        {
            int temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
        return;
    }
    else if ((size_A == 0) || (size_B == 0))
    {
        return;
    }
    else
    {
        int duplicate_Array[(size_A + size_B)];

        int index_1, index_2, index_Origin;

        index_1, index_Origin = 0;
        index_2 = size_A;

        while (((index_1 < size_A) && (index_2 < (size_A + size_B))))
        {
            if (array[index_1] > array[index_2])
            {
                duplicate_Array[index_Origin] = array[index_2];
                index_2 ++;
            }
            else
            {
                duplicate_Array[index_Origin] = array[index_1];
                index_1 ++;
            }
            index_Origin ++;
        }
        while (index_1 < size_A)
        {
            duplicate_Array[index_Origin] = array[index_1];
            index_Origin ++;
            index_1 ++;
        }
        while (index_2 < (size_A + size_B))
        {
            duplicate_Array[index_Origin] = array[index_2];
            index_Origin ++;
            index_2 ++;
        }
        for (int i = 0; i < (size_A + size_B); i++)
        {
            array[i] = duplicate_Array[i];
        }
        printf("");
    }
}

void __Integer_Array_Sorter__Merge_Sort__(int *array, int size)
{
    if ((size == 0) || (size == 1))
    {
        return;
    }
    else
    {
        int mid = (size / 2);
        printf("");
        __Integer_Array_Sorter__Merge_Sort__(array, mid);
        printf("");
        __Integer_Array_Sorter__Merge_Sort__(array + mid, (size - mid));
        printf("");

        __Integer_Array_Sorter__Merger__Merge_Algorithm__(array, mid, (size - mid));
        printf("");
        array[0] = array[0];
        printf("");
        return;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 2, 3, 4, 5};
    int size = (sizeof(a) / sizeof(int));
    // size = 5;
    // print(a, size);
    __Integer_Array_Sorter__Merge_Sort__(a, size);
    print(a, size);
    return 0;
}
