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


    for (int i, k = 0; i <= size - 1; i++)
    {
        temp = arr[i];
        k = i - 1;
        while (k >= 0 && arr[k] > temp)
        {
            arr[k + 1] = arr[k];
            k --;
        }
        arr[k + 1] = temp;
    }
    printf("\nSorted Array: {%d", arr[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}.");    
    
    return 0;
}