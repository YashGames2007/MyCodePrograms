#include <stdio.h>

// int fib_Recursive(int n);
// int fib_Iterative(int n);

int main()
{
    int a, *b, **c;
    a = 1;
    b = NULL;
    c = &b;

    int arr[3] = {a, *b, **c};
    printf("\n%x, %x, %x", &a, &*b, &**c);
    printf("\n%x, %p, %x", &arr[0], &arr[1], &arr[2]);
    // printf("\nIterative: %d", fib_Iterative(45));
    // printf("\nRecursive: %d", fib_Recursive(45));
    return 0;
}

// int fib_Recursive(int n)
// {
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else if (n == 1 || n == 2)
//     {
//         return 1;
//     }
//     else
//     {
//         int value = fib_Recursive(n - 1) + fib_Recursive(n - 2);
//         return value;
//     }   
// }

// int fib_Iterative(int n)
// {
//     int prev1, prev2, current;
//     prev2 = 0;
//     prev1 = 1;
//     current = 1;
//     for (int i = 2; i < n; i++)
//     {
//         prev2 = prev1;
//         prev1 = current;
//         current = prev1 + prev2;
//     }
//     return current;
// }