#include <stdio.h>

int main()
{
    // int a; scanf("%d", &a);
    // int i = a < 5 ?3 :4;
    // printf("\n%d", i);
    // printf("Type a Number: ");
    // scanf("%d", &i);

    char arr[10] = {'c', 'a', 't', 'a', 'l', 'i', 's', 't', 'e', 'r'}, temp;

    int j = 1;
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("\nType The Character For Array At Index %d : ", i);
    //     scanf("%c%c", &arr[i], &temp);
    // }
    printf("\nYour Character Array: {");

    for (int i = 0; i < 9; i++)
    {
        printf("'%c', ", arr[i]);
    }

    printf("'%c'}.", arr[9]);
    
    return 0;
}