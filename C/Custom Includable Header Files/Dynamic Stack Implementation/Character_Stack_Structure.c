#include <stdio.h>
#include <stdlib.h>

// Defining Some Error Massages
#define __D_C_S_S__ERROR_01__ "\nCharacter Stack :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Character Stack is Deleted!!!", __FUNCTION__
#define __D_C_S_S__ERROR_02__ "\nCharacter Stack :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Character Stack Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Character_Stack_Structure_Node
{
    char __Node_Data__;
    struct Dynamic_Character_Stack_Structure_Node *__Previous_Node__;
} char_D_S_S_Node;

/*
---
---
---
# Character Stack :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Character Stack in Curly Brackets.
---
### Arguments
#### 1. char_Stack structure
---
---
## 2. delete
#### Deletes The Whole Character_Stack.
---
### Arguments
#### 1. char_Stack structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. char_Stack structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Character_Stack, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. char_Stack structure
#### 2. char element
---
---
## 5. append
#### Appends The Element At The End Of The Character_Stack.
---
### Arguments
#### 1. char_Stack structure
#### 2. char element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Character_Stack.
---
### Arguments
#### 1. char_Stack structure
#### 2. char element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Character_Stack.
---
### Arguments
#### 1. char_Stack structure
#### 2. int index
#### 3. char element
---
---
---
---
---
*/
typedef struct Dynamic_Character_Stack_Structure
{
    int __Size__; //#### Size of Character_Stack
    char_D_S_S_Node *__Top_Node__;
    /*### Represents The Character Stack in Curly Brackets. */
    void (*repr)(struct Dynamic_Character_Stack_Structure *structure);
    /*### Deletes The Whole Character_Stack. */
    void (*delete)(struct Dynamic_Character_Stack_Structure *structure);
    /*### Removes The Element At Top Most Index and Returns The Element. */
    char (*pop)(struct Dynamic_Character_Stack_Structure *structure);
    /*### Returns The Index of First Occurrence of The Element In The Character_Stack, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Character_Stack_Structure *structure, char element);
    /*### Appends The Element At The End of The Character_Stack. */
    void (*push)(struct Dynamic_Character_Stack_Structure *structure, char element);

} char_Stack;

void __D_C_S_S_Push__(struct Dynamic_Character_Stack_Structure *stack, char element)
{
    if (stack->__Size__ == -1)
    {
        printf(__D_C_S_S__ERROR_01__);
    }
    else
    {
        if (stack->__Size__ == 0)
        {
            stack->__Top_Node__ = (char_D_S_S_Node *)malloc(sizeof(char_D_S_S_Node));
            stack->__Top_Node__->__Node_Data__ = element;
            stack->__Top_Node__->__Previous_Node__ = NULL;
        }
        else
        {
            char_D_S_S_Node *new_Node = (char_D_S_S_Node *)malloc(sizeof(char_D_S_S_Node));
            new_Node->__Node_Data__ = element;
            new_Node->__Previous_Node__ = stack->__Top_Node__;
            stack->__Top_Node__ = new_Node;
        }
        stack->__Size__++;
    }
}

int __D_C_S_S_Search__(struct Dynamic_Character_Stack_Structure *stack, char element)
{
    if (stack->__Size__ == -1)
    {
        printf(__D_C_S_S__ERROR_01__);
        return -1;
    }
    else if (stack->__Size__ == 0)
    {
        return -1;
    }
    else
    {
        if (stack->__Top_Node__->__Node_Data__ == element)
        {
            return stack->__Size__ - 1;
        }
        else
        {
            char_D_S_S_Node *current_Node = stack->__Top_Node__;

            for (int i = 1; i < stack->__Size__; i++)
            {
                current_Node = current_Node->__Previous_Node__;

                if (current_Node->__Node_Data__ == element)
                {
                    return (stack->__Size__ - i) - 1;
                }
            }
            return -1;
        }
    }
}

char __D_C_S_S_Pop__(struct Dynamic_Character_Stack_Structure *stack)
{

    if (stack->__Size__ == -1)
    {
        printf(__D_C_S_S__ERROR_01__);
    }
    else
    {
        char_D_S_S_Node *temp_Node = stack->__Top_Node__;
        char temp_Data = temp_Node->__Node_Data__;
        stack->__Top_Node__ = stack->__Top_Node__->__Previous_Node__;
        free(temp_Node);
        stack->__Size__--;
        return temp_Data;
    }
}

void __D_C_S_S_Represent__(struct Dynamic_Character_Stack_Structure *stack)
{
    if (stack->__Size__ == -1)
    {
        printf(__D_C_S_S__ERROR_01__);
    }
    else
    {
        if (stack->__Size__ == 0)
        {
            printf("\n=========||");
            printf("\n   |===| ||");
            printf("\n   | - | ||");
            printf("\n   |===| ||");
            printf("\n=========||");
            printf("\n");
        }
        else
        {
            printf("\n===");

            for (int i = 0; i < stack->__Size__; i++)
            {
                printf("======");
            }
            printf("||");
            printf("\n");
            printf("   ");

            for (int i = 0; i < stack->__Size__; i++)
            {
                printf("|===| ");
            }
            printf("||");
            printf("\n");
            printf("   ");

            char_D_S_S_Node *current_Node = stack->__Top_Node__;
            for (int i = 0; i < stack->__Size__; i++)
            {
                printf("| %c | ", current_Node->__Node_Data__);
                current_Node = current_Node->__Previous_Node__;
            }
            printf("||");
            printf("\n");
            printf("   ");

            for (int i = 0; i < stack->__Size__; i++)
            {
                printf("|===| ");
            }
            printf("||");
            printf("\n");
            printf("===");
            for (int i = 0; i < stack->__Size__; i++)
            {
                printf("======");
            }
            printf("||");
            printf("\n");
        }
    }
}

void __D_C_S_S_Delete__(struct Dynamic_Character_Stack_Structure *stack)
{
    char_D_S_S_Node *current_Node = stack->__Top_Node__;
    char_D_S_S_Node *temp_Node = NULL;
    for (int i = 0; i < stack->__Size__; i++)
    {
        temp_Node = current_Node;
        current_Node = current_Node->__Previous_Node__;
        free(temp_Node);
    }
    stack->__Top_Node__ = NULL;
    stack->__Size__ = -1;
}

void __D_C_S_S_Initialize__(struct Dynamic_Character_Stack_Structure *new_stack)
{
    new_stack->__Size__ = 0;
    new_stack->__Top_Node__ = NULL;

    // Functions Declaration...
    (new_stack->pop) = __D_C_S_S_Pop__;
    (new_stack->repr) = __D_C_S_S_Represent__;
    (new_stack->delete) = __D_C_S_S_Delete__;
    (new_stack->search) = __D_C_S_S_Search__;
    (new_stack->push) = __D_C_S_S_Push__;
}

#define char_Stack_init __D_C_S_S_Initialize__