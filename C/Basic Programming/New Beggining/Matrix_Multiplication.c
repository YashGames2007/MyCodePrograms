#include <stdio.h>
#include <stdlib.h>
/*
size format:
    Function Call:
        size[0] = a[rows], b[columns]
        size[1] = a[columns]
        size[2] = b[rows]
    Return Value:
        size[0] = c[rows]
        size[1] = c[columns]
*/
int *matrix_Calculator(int *a, int *b, const int a_Rows, const int a_Columns, const int b_Rows, const int b_Columns); // It Will Multiply a & b to get the result and will store it in c.
void function(int *dimension_array, int dimension, int value, int *value_array);
void array_Printer(int *array, int *dimension_array, int dimension);
int main()
{
    // int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int b[3][2] = {{10, 11}, {20, 21}, {30, 31}};
    int a[1][3] = {{3, 4, 2}};
    int b[3][4] = {{13, 9, 7, 15}, {8, 7, 4, 6}, {6, 4, 0, 3}};
    int *c = matrix_Calculator(&a[0][0], &b[0][0], 3, 1, 4, 3);

    printf("\nMultiplication: \n");
    int temp[2] = {2, 2};
    array_Printer(c, temp, 2);
    free(c);
    return 0;
}
int *matrix_Calculator(int *a, int *b, const int a_Rows, const int a_Columns, const int b_Rows, const int b_Columns)
{
    if (a_Rows != b_Columns)
    {
        return NULL;
    }
    int *solution = (int *)malloc((b_Rows * a_Columns) * sizeof(int));
    int *ptr = solution;
    int temp = 0;
    for (int i = 0; i < a_Columns; i++)
    {
        for (int j = 0; j < b_Rows; j++)
        {
            for (int k = 0; k < a_Rows; k++)
            {
                // printf("\n%d, %d, %d : %d X %d", i, j, k, a[(i * a_Rows) + k] ,b[j + (k * b_Rows)]);
                temp += (a[(i * a_Rows) + k]) * (b[j + (k * b_Rows)]);
            }
            *ptr = temp;
            ptr++;
            temp = 0;
        }
    }
    ptr = solution;
    return ptr;
}

void array_Printer(int *array, int *dimension_array, int dimension)
{
    int total = 1;
    int value_array[dimension];
    for (int a = 0; a < dimension; a++)
    {
        total *= dimension_array[a];
    }
    for (int i = 0; i < total; i++)
    {
        int value_array[dimension];
        function(dimension_array, dimension, i, &value_array[0]);
        printf("The element at index ");
        for (int i = 0; i < dimension; i++)
        {
            printf("[%d]", value_array[i]);
        }
        printf(" is : %d\n", *array);
        array++;
    }
}
void function(int *dimension_array, int dimension, int value, int *value_array)
{
    int total = 1;
    int temp;
    for (int a = 0; a < dimension; a++)
    {
        total *= dimension_array[a];
    }
    for (int i = 0; i < dimension; i++)
    {
        total = total / dimension_array[i];
        temp = value / total;
        value_array[i] = temp;
        value = value % total;
    }
}
/*
3 2

0 0 - 0
0 1 - 1
1 0 - 1
1 1 - 1
2 0 - 1
2 1 - 1

*/