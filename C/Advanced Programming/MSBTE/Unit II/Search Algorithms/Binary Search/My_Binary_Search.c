#include <stdio.h>

int main()
{
    int top, bottom, mid, key, n, found = 0;
    
    printf("\nType Number Of Elements: ");
    scanf("%d", &n);
    int arr[n];
    top = 0;
    bottom = n - 1;

    for (int i = 0; i < n; i++)
    {
        printf("\nType The Element For Index %d : ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nYou Entered: {%d", arr[0]);
    for (int i = 1; i < n; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}");

    printf("\nType The Value of Element to be Searched For: ");
    scanf("%d", &key);

    while (top <= bottom)
    {
        mid = (top + bottom) / 2;
        if (arr[mid] == key)
        {
            printf("\nElement Found At Index %d", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            top = mid + 1;
        }
        else
        {
            bottom = mid - 1;
        }
    }
    if (!found)
    {
        printf("\nElement Not Found");
    }
    return 0;
}