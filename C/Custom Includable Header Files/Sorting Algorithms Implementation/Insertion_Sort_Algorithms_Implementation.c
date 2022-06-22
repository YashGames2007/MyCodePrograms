void __Float_Array_Sorter__Insertion_Sort_Algorithm__(float *array, int size)
{
    float temp;

    if (size < 1)
    {
        return;
    }
    else if (size == 1)
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
        int difference, temp, current;

        for (int i = 1; i < size; i++)
        {
            current = i;
            if (array[i] < array[i - 1])
            {
                for (int j = current - 1; j >= 0; j--)
                {

                    if (array[j] > array[current])
                    {
                        temp = array[j];
                        array[j] = array[current];
                        array[current] = temp;
                        current = j;
                    }
                }
            }
        }
    }
}

void __Double_Array_Sorter__Insertion_Sort_Algorithm__(double *array, int size)
{
    double temp;

    if (size < 1)
    {
        return;
    }
    else if (size == 1)
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
        int difference, temp, current;

        for (int i = 1; i < size; i++)
        {
            current = i;
            if (array[i] < array[i - 1])
            {
                for (int j = current - 1; j >= 0; j--)
                {

                    if (array[j] > array[current])
                    {
                        temp = array[j];
                        array[j] = array[current];
                        array[current] = temp;
                        current = j;
                    }
                }
            }
        }
    }
}

void __Integer_Array_Sorter__Insertion_Sort_Algorithm__(int *array, int size)
{
    int temp;

    if (size < 1)
    {
        return;
    }
    else if (size == 1)
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
        int difference, temp, current;

        for (int i = 1; i < size; i++)
        {
            current = i;
            if (array[i] < array[i - 1])
            {
                for (int j = current - 1; j >= 0; j--)
                {

                    if (array[j] > array[current])
                    {
                        temp = array[j];
                        array[j] = array[current];
                        array[current] = temp;
                        current = j;
                    }
                }
            }
        }
    }
}

void __Character_Array_Sorter__Insertion_Sort_Algorithm__(char *array, int size)
{
    char temp;

    if (size < 1)
    {
        return;
    }
    else if (size == 1)
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
        int difference, temp, current;

        for (int i = 1; i < size; i++)
        {
            current = i;
            if (array[i] < array[i - 1])
            {
                for (int j = current - 1; j >= 0; j--)
                {

                    if (array[j] > array[current])
                    {
                        temp = array[j];
                        array[j] = array[current];
                        array[current] = temp;
                        current = j;
                    }
                }
            }
        }
    }
}
