#include <stdio.h>

int main()
{
    int num;
    printf("\nEnter A Number You Want Multiplication Table Of: ");
    scanf("%d", &num);
    printf("\nTable Of %d:", num);
    for (int i = 1; i < 11; i++)
    {
        if (i == 10)
        {
            printf("\n%d X %d = %d", num, i, num*i);
        }
        else
        {
            printf("\n%d X %d  = %d", num, i, num*i);
        }
    }
    return 0;
}