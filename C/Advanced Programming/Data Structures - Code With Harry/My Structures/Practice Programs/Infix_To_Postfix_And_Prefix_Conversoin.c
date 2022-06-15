#include <stdio.h>
#include <string.h>
#include "Parentheses_Matching.c"
#include "../Dynamic Array Implementation\Dynamic_Array_Structure.c"

int scan_Operator(char operator);
char *infix_To_Postfix_Converter(char *infix_Expression);

int main()
{
    char infix[] = "(a+b)*c";
    char *postfix = infix_To_Postfix_Converter(infix);
    printf("\nPostfix Expression: ");
    puts(postfix);
    return 0;
}

int scan_Operator(char operator)
{
    /*
    )          - 5
    (          - 4
    ? ^ $      - 3
    * /        - 2
    + -        - 1
    operand    - 0

    */

    switch (operator)
    {
    case ')':
        return 5;
    case '(':
        return 4;
    case '?':
        return 3;
    case '^':
        return 3;
    case '$':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

char *infix_To_Postfix_Converter(char *infix_Expression)
{
    if (isBalanced(infix_Expression) != 0)
    {
        return NULL;
    }
    char operator = infix_Expression[0];
    char temp_Operator;
    int index = 1;
    int in = 0;
    int previous_In = 0;
    int_Array post;
    init(&post);
    char_Stack stack;
    char_Stack_init(&stack);

    char stack_Operator;

    while (operator != '\0')
    {
        stack.repr(&stack);
        if (scan_Operator(operator) == 4)
        {
            in++;
        }
        if (scan_Operator(operator) == 5)
        {
            in--;
        }
        if (scan_Operator(operator) == 0)
        {
            post.append(&post, (int) operator);
        }
        else if (stack.size == 0)
        {
            stack.push(&stack, operator);
        }
        else
        {
            stack_Operator = stack.pop(&stack);
            stack.push(&stack, stack_Operator);

            if (scan_Operator(operator) <= scan_Operator(stack_Operator))
            {
                previous_In = in; 
                while (stack.size != 0)
                {
                    temp_Operator = stack.pop(&stack);
                    if (scan_Operator(temp_Operator) < scan_Operator(operator))
                    {
                        stack.push(&stack, temp_Operator);
                        break;
                    }
                    post.append(&post, (int) temp_Operator);
                }
                stack.push(&stack, operator);
            }
            else if (scan_Operator(operator) > scan_Operator(stack_Operator))
            {
                stack.push(&stack, operator);
            }
        }
        
        operator = infix_Expression[index];
        index++;
    }
    int stack_size = stack.size;
    for (int i = 0; i < stack_size; i++)
    {
        temp_Operator = (char) stack.pop(&stack);
        post.append(&post, (int) temp_Operator);
    }
    char *postfix = (char *)malloc((post.size + 1) * sizeof(char));

    for (int i = 0; i < post.size; i++)
    {
        postfix[i] = (char) post.__Base_Address__[i];
    }
    postfix[post.size] = '\0';
    return postfix;
}