#include <stdio.h>

int main()
{
    int size;
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

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] < arr[i])
            {
                /*
                ex. 1, 2, 3, 0
                s1:
                    temp = 1, target = 0
                    arr[0] = target = 0
                    target = temp = 1
                    temp = arr[x + 1] = 2
                    0, 2, 3, 0
                s2:
                    temp = 2, target = 1
                    arr[1] = target = 1
                    target = temp = 2
                    temp = arr[x + 1] = 3
                    0, 1, 3, 0
                s3:
                    temp = 3, target = 2
                    arr[2] = target = 2
                    target = temp = 3
                    temp = arr[x + 1] = 0
                    0, 1, 2, 0
                s4:
                    temp = 0, target = 3
                    arr[3] = target = 3
                    target = temp = 0
                    temp = arr[x + 1] = GB
                    0, 1, 2, 3
                */
                int temp = arr[i], target = arr[j];
                for (int x = 0; x < size; x++)
                {
                    arr[x] = target;
                    target = temp;
                    temp = arr[x + 1];
                }
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