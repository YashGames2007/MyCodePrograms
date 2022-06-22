void __Float_Array_Sorter__Selection_Sort__(float *array, int size)
{
    float temp;

    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
        return;
    }
    else
    {
        int lowest_Index = 0;

        for (int i = 1; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                lowest_Index = i + 1;
            }
        }
        temp = array[0];
        array[0] = array[lowest_Index];
        array[lowest_Index] = temp;
        __Float_Array_Sorter__Selection_Sort__((array + 1), (size - 1));
        return;
    }
}

void __Double_Array_Sorter__Selection_Sort__(double *array, int size)
{
    double temp;

    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
        return;
    }
    else
    {
        int lowest_Index = 0;

        for (int i = 1; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                lowest_Index = i + 1;
            }
        }
        temp = array[0];
        array[0] = array[lowest_Index];
        array[lowest_Index] = temp;
        __Double_Array_Sorter__Selection_Sort__((array + 1), (size - 1));
        return;
    }
}

void __Integer_Array_Sorter__Selection_Sort__(int *array, int size)
{
    int temp;

    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
        return;
    }
    else
    {
        int lowest_Index = 0;

        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                lowest_Index = i + 1;
            }
        }
        temp = array[0];
        array[0] = array[lowest_Index];
        array[lowest_Index] = temp;
        __Integer_Array_Sorter__Selection_Sort__((array + 1), (size - 1));
        return;
    }
}

void __Character_Array_Sorter__Selection_Sort__(char *array, int size)
{
    char temp;

    if (size <= 1)
    {
        return;
    }
    else if (size == 2)
    {
        if (array[0] > array[1])
        {
            temp = array[0];
            array[0] = array[1];
            array[1] = temp;
        }
        return;
    }
    else
    {
        int lowest_Index = 0;

        for (int i = 1; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                lowest_Index = i + 1;
            }
        }
        temp = array[0];
        array[0] = array[lowest_Index];
        array[lowest_Index] = temp;
        __Character_Array_Sorter__Selection_Sort__((array + 1), (size - 1));
        return;
    }
}
