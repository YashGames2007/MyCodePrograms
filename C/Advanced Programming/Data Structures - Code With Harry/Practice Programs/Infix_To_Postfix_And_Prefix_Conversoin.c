#include <stdio.h>
#include <string.h>
#include "E:\Programming files\Code\C\Advanced Programming\Data Structures - Code With Harry\Practice Programs\Parentheses_Matching.c"
#include Integer_Array

int scan_Operator(char operator);
char *infix_To_Postfix_Converter(char *infix_Expression);

int main()
{
    char infix[] = "4 $ 21 * 3 - 3 + 8 / 4 / (1 + 1)";
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
    int_Array_init(&post);
    char_Stack stack;
    char_Stack_init(&stack);

    char stack_Operator;

    while (operator != '\0')
    {
        if (scan_Operator(operator) == 4)
        {
            stack.push(&stack, operator);
            in++;
        }
        else if (scan_Operator(operator) == 5)
        {
            char i = stack.pop(&stack);
            
            while (i != '(')
            {
                post.append(&post, (int) ' ');
                post.append(&post, (int) i);
                i = stack.pop(&stack);
            }
            in--;
        }
        else if (scan_Operator(operator) == 0)
        {
            post.append(&post, (int) operator);
        }
        else if (stack.__Size__ == 0)
        {
            stack.push(&stack, operator);
        }
        else
        {
            stack_Operator = stack.pop(&stack);
            stack.push(&stack, stack_Operator);

            if (scan_Operator(operator) <= scan_Operator(stack_Operator))
            {
                while (stack.__Size__ != 0)
                {
                    temp_Operator = stack.pop(&stack);
                    if (temp_Operator == '(')
                    {
                        stack.push(&stack, temp_Operator);
                        break;
                    }
                    if (scan_Operator(temp_Operator) < scan_Operator(operator))
                    {
                        stack.push(&stack, temp_Operator);
                        break;
                    }
                    post.append(&post, (int) ' ');
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
    int stack___Size__ = stack.__Size__;
    for (int i = 0; i < stack___Size__; i++)
    {
        temp_Operator = (char) stack.pop(&stack);
        post.append(&post, (int) ' ');
        post.append(&post, (int) temp_Operator);
    }
    char postfix[post.__Size__ + 1];

    for (int i = 0; i < post.__Size__; i++)
    {
        postfix[i] = (char) post.__Base_Address__[i];
    }
    postfix[post.__Size__] = '\0';

    char *new_Postfix = (char *)malloc((post.__Size__ + 1) * sizeof(char));

    int i = 0, j = 0;

    while (postfix[i] != '\0')
    {   
        while (postfix[i] == ' ' && postfix[i + 1] == ' ')
        {
            i++;
        }
        new_Postfix[j] = postfix[i];
        i++;
        j++;
    }
    new_Postfix[j] = '\0';
    return new_Postfix;
}