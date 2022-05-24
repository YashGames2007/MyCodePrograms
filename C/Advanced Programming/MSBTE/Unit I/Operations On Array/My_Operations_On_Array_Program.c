#include <stdio.h>

int main()
{
    int size, position;
    printf("\nType The Number of Element That Should Be Stored In Array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("\nType The Element That Should Be Stored At Index %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nYou Enetered : {%d", arr[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}");
    
    printf("\nType The Index Value Of The Element That Should Be Deleted : ");
    scanf("%d", &position);

    if (position >= size)
    {
        printf("\nDeletion Not Possible.");
    }
    else
    {
        while (position < size)
        {
            arr[position] = arr[position + 1];
            position++;
        }
        printf("\nArray After Deletiion : {%d", arr[0]);
        for (int i = 1; i < size - 1; i++)
        {
            printf(", %d", arr[i]);
        }
        printf("}");
    }
    
    
    
    return 0;
}