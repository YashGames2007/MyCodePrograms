#include <stdio.h>

int main()
{
    int n, key, found = 0;
    printf("\nType Number Of Elements: ");
    scanf("%d", &n);
    int arr[n];
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

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("\nRecord Found At Index %d", i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("\nElement Not Found.");
    }
    return 0;
}