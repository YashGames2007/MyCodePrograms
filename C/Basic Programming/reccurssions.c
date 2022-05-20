#include <stdio.h>

int factorial(int n);
int fib(int n);
int doubler(int n);

int main()
{
    int number, fact, fb, db;
    printf("\nType the number :- ");
    scanf("%d", &number);

    fact = factorial(number);
    printf("\nThe factorial of %d is %d", number, fact);

    fb = fib(number);
    printf("\nThe %d th fib number is %d", number, fb);

    db = doubler(number);
    printf("\nThe %d th doubler number is %d", number, db);

    return 0;
}

int factorial(int n)
{
    // if (n == 0 || n == 1)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return (factorial(n - 1) * n);
    // }

    printf("\nCalling factorial(%d)\n", n);

    if (0)
    {
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}
int doubler(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else
    {
        return (2 * doubler(n - 1));
    }
}