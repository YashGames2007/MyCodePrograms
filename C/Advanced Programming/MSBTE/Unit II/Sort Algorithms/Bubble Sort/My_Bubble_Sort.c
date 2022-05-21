#include <stdio.h>

int main()
{
    int size;
    printf("\nEnter The Numbe of Element In The Array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("\nEnter The Element At Index %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nYou Entered: {%d", arr[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}.");

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            
        }
    }
    printf("\nSorted Array: {%d", arr[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}.");
    return 0;
}