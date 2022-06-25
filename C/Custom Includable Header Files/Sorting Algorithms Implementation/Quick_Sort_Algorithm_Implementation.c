#include <stdio.h>

void print(int *array, int size)
{
    printf("\n{%d", array[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", array[i]);
    }
    printf("}.\n");
}

void __Integer_Array_Sorter__Quick_Sort_Algorithm__(int *array, int size)
{
    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            int temp;
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return;
        }
        return;
    }
    else
    {
        int pivot, left, right, temp;

        pivot = 0;
        left = 1;
        right = size - 1;

        while (right >= left)
        {
            while (array[left] <= array[pivot])
            {
                left++;
                if (right < left)
                {
                    break;
                }
            }
            if (right <= left)
            {
                break;
            }
            while (array[right] >= array[pivot])
            {
                right--;
                if (right < left)
                {
                    break;
                }
            }
            if (right <= left)
            {
                break;
            }
            temp = array[right];
            array[right] = array[left];
            array[left] = temp;
            left++;
            right--;
        }
        temp = array[pivot];
        array[pivot] = array[right];
        array[right] = temp;

        if (right == 0)
        {
            __Integer_Array_Sorter__Quick_Sort_Algorithm__(&array[1], (size - 1));
        }
        else if (left == size)
        {
            __Integer_Array_Sorter__Quick_Sort_Algorithm__(array, (size - 1));
        }
        else
        {
            __Integer_Array_Sorter__Quick_Sort_Algorithm__(array, right);
            __Integer_Array_Sorter__Quick_Sort_Algorithm__(&array[right + 1], (size - right - 1));
        }
        return;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {5, 4, 10, 2, 1};
    int size = (sizeof(arr) / sizeof(int));
    print(arr, size);
    __Integer_Array_Sorter__Quick_Sort_Algorithm__(arr, size);
    print(arr, size);
    return 0;
}
