#include <stdio.h>
#include "Dynamic_Stack_Structure.c"

int main()
{
    int_Stack a;
    char_Stack b;
    char_Stack_init(&b);
    b.repr(&b);
    b.push(&b, '(');
    b.repr(&b);
    b.push(&b, ')');
    b.repr(&b);
    b.push(&b, '[');
    b.repr(&b);
    b.push(&b, ']');
    b.repr(&b);
    b.push(&b, '{');
    b.repr(&b);
    b.push(&b, '}');
    b.repr(&b);

    printf("\n'(': %d", '(');
    printf("\n')': %d", ')');
    printf("\n'{': %d", '{');
    printf("\n'}': %d", '}');
    printf("\n'[': %d", '[');
    printf("\n']': %d", ']');
    // init(&a);
    // a.repr(&a);
    // a.push(&a, -1000);
    // a.repr(&a);
    // a.push(&a, 20);
    // a.repr(&a);
    // a.push(&a, 30000);
    // a.repr(&a);
    // a.push(&a, 40);
    // a.repr(&a);
    // a.push(&a, 500);
    // a.repr(&a);
    // a.pop(&a);
    // a.repr(&a);
    // a.pop(&a);
    // a.repr(&a);
    // a.pop(&a);
    // a.repr(&a);
    // a.delete(&a);
    // a.repr(&a);
    // printf("\n1 is Present at Index: %d", a.search(&a, 1));
    // printf("\nDone!");
    return 0;
}