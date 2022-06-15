#include <stdio.h>
#include <string.h>
#include "..\Dynamic Stack Structure Implementation\Dynamic_Stack_Structure.c"

int isBalanced(char *exp);

int main2()
{
    char *expression = "{[{[})]}]}";
    printf("Balance Rate: %d", isBalanced(expression));
    return 0;
}

int isBalanced(char *exp)
{
    char i = exp[0];
    char_Stack stack;
    char_Stack_init(&stack);
    int index = 0;
    char value = ' ';

    while (i != '\0')
    {
        if (i == '(' || i == '[' || i == '{')
        {
            stack.push(&stack, i);
        }
        else if (i == ')' || i == ']' || i == '}')
        {
            if (stack.__Size__ <= 0)
            {
                return -1;
            }
            else
            {
                value = stack.pop(&stack);

                if (value == '(' && i != ')')
                {
                    return -2;
                }
                else if (value == '[' && i != ']')
                {
                    return -3;
                }
                else if (value == '{' && i != '}')
                {
                    return -4;
                }
            }
        }
        index++;
        i = exp[index];
    }
    int result = stack.__Size__;
    stack.delete(&stack);
    return result;
}