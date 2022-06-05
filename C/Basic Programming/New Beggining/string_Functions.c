#include <stdio.h>

void reverse(int *arr, int len);
void print(int *arr, int len);

int main()
{   int size = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 67};
    print(arr, size);
    reverse(arr, size);
    print(arr, size);
    return 0;
}
void reverse(int *arr, int len)
{
    int temp;
    for (int i = 0; i < (len / 2); i++)
    {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
void print(int *arr, int len)
{
    printf("\n{%d", arr[0]);
    for (int i = 1; i < len; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}");
}