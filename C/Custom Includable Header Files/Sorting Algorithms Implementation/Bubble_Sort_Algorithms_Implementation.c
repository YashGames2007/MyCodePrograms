void __Float_Array_Sorter__Bubble_Sort_Algorithm__(float *array, int size)
{
    float temp;
    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] < array[1])
        {
            return;
        }
        else
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return;
        }
    }
    else
    {
        int swap_Count = 0;

        for (int i = 0; i < size  -1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                swap_Count++;
            }
        }
        if (swap_Count == (size - 1))
        {
            return;
        }
        else
        {
            __Float_Array_Sorter__Bubble_Sort_Algorithm__(array, (size - 1));
            return;
        }
    }
}

void __Double_Array_Sorter__Bubble_Sort_Algorithm__(double *array, int size)
{
    double temp;
    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] < array[1])
        {
            return;
        }
        else
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return;
        }
    }
    else
    {
        int swap_Count = 0;

        for (int i = 0; i < size  -1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                swap_Count++;
            }
        }
        if (swap_Count == (size - 1))
        {
            return;
        }
        else
        {
            __Double_Array_Sorter__Bubble_Sort_Algorithm__(array, (size - 1));
            return;
        }
    }
}

void __Integer_Array_Sorter__Bubble_Sort_Algorithm__(int *array, int size)
{
    int temp;
    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] < array[1])
        {
            return;
        }
        else
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return;
        }
    }
    else
    {
        int swap_Count = 0;

        for (int i = 0; i < size  -1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                swap_Count++;
            }
        }
        if (swap_Count == (size - 1))
        {
            return;
        }
        else
        {
            __Integer_Array_Sorter__Bubble_Sort_Algorithm__(array, (size - 1));
            return;
        }
    }
}

void __Character_Array_Sorter__Bubble_Sort_Algorithm__(char *array, int size)
{
    char temp;
    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] < array[1])
        {
            return;
        }
        else
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
            return;
        }
    }
    else
    {
        int swap_Count = 0;

        for (int i = 0; i < size  -1; i++)
        {
            if (array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            else
            {
                swap_Count++;
            }
        }
        if (swap_Count == (size - 1))
        {
            return;
        }
        else
        {
            __Character_Array_Sorter__Bubble_Sort_Algorithm__(array, (size - 1));
            return;
        }
    }
}
