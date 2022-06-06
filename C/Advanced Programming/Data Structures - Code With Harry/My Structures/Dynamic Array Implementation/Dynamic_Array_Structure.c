#include <stdio.h>
#include <stdlib.h>

/*
Methods Belonging To Dynamic Integer Array:

*/
typedef struct Dynamic_Array_Structure
{
    int size;
    int *base_Address;

} int_Array;

void init(int_Array new)
{
    new.size = 0;
}
void append(int_Array arr, int element)
{
    arr.size++;
    arr.base_Address = (int *)realloc(arr.base_Address, arr.size * sizeof(int));
    arr.base_Address[arr.size - 1] = element;
}
void repr(int_Array arr)
{
    if (arr.size == 0)
    {
        printf("\nInteger Array: {}.");
    }
    else
    {
        printf("\nInteger Array: {%d", arr.base_Address[0]);
        
        for (int i = 1; i < arr.size; i++)
        {
            printf(", %d", arr.base_Address[i]);
        }
        printf("}.");
    }
}
int main()
{
    int_Array a;
    init(a);
    repr(a);

    return 0;
}