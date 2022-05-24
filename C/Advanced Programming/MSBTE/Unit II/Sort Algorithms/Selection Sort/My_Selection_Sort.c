#include <stdio.h>

int main()
{
    int size, temp;
    printf("\nEnter The Number of Element In The Array: ");
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

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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