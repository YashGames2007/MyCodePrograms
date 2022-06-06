#include <stdio.h>
#include "Dynamic_Array_Structure.c"

int main()
{
    int_Array a;
    init(a);
    append(a, 1);
    append(a, 2);
    append(a, 3);
    repr(a);
    return 0;
}