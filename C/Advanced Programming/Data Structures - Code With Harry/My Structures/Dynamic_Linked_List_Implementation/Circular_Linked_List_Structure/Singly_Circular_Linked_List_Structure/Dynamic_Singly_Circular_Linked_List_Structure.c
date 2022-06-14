#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_I_S_C_L_L_S__ERROR_01__ "\nSingly Circular Integer Linked List :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Linked List is Deleted!!!", __FUNCTION__
#define __D_I_S_C_L_L_S__ERROR_02__ "\nSingly Circular Integer Linked List :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Linked List Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Integer_Singly_Circular_Linked_List_Node
{
    int __Node_Data__;
    struct Dynamic_Integer_Singly_Circular_Linked_List_Node *__Next_Node__;
} int_S_C_L_L_Node;

/*
---
---
---
# Singly Circular Integer Linked List :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Linked List in Curly Brackets.
---
### Arguments
#### 1. int_S_C_L_List structure
---
---
## 2. delete
#### Deletes The Whole Linked List.
---
### Arguments
#### 1. int_S_C_L_List structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_S_C_L_List structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Linked List, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_S_C_L_List structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Linked List.
---
### Arguments
#### 1. int_S_C_L_List structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Linked List.
---
### Arguments
#### 1. int_S_C_L_List structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Linked List.
---
### Arguments
#### 1. int_S_C_L_List structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Singly_Circular_Linked_List_Structure
{
    int_S_C_L_L_Node *__Head_Node__;
    int_S_C_L_L_Node *__Foot_Node__;
    int __Size__; //#### Size of Linked List

    /*### Represents The Linked List in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *structure);
    /*### Deletes The Whole Linked List. */
    void (*delete)(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *structure);
    /*### Appends The Element At The End of The Linked List. */
    void (*append)(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *structure, int element);
    /*### Removes The First Occurrence Of The Specified Element in The Linked List. */
    void (*remove)(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Linked List. */
    void (*insert)(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *structure, int index, int element);

} int_S_C_L_List;

void __D_I_S_C_L_L_S_Insert__(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *Linked_List, int index, int element)
{
    if (Linked_List->__Size__ <= index)
    {
        printf(__D_I_S_C_L_L_S__ERROR_02__);
    }
    else
    {
        if (Linked_List->__Size__ == -1)
        {
            printf(__D_I_S_C_L_L_S__ERROR_01__);
        }
        else
        {
            if (Linked_List->__Size__ == 1)
            {
                Linked_List->append(Linked_List, element);
            }
            else
            {
                int_S_C_L_L_Node *current_Node = Linked_List->__Head_Node__;

                for (int i = 0; i < index - 1; i++)
                {
                    current_Node = current_Node->__Next_Node__;
                }

                int_S_C_L_L_Node *new_Node = (int_S_C_L_L_Node *)malloc(sizeof(int_S_C_L_L_Node));

                new_Node->__Next_Node__ = current_Node->__Next_Node__;
                current_Node->__Next_Node__ = new_Node;

                new_Node->__Node_Data__ = element;
                Linked_List->__Size__++;
            }
        }
    }
}

void __D_I_S_C_L_L_S_Remove__(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *Linked_List, int element)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_I_S_C_L_L_S__ERROR_01__);
    }
    else
    {
        if (Linked_List->__Head_Node__->__Node_Data__ == element)
        {
            int_S_C_L_L_Node *temp_Node = Linked_List->__Head_Node__;
            Linked_List->__Head_Node__ = Linked_List->__Head_Node__->__Next_Node__;
            Linked_List->__Size__--;
            free(temp_Node);
        }
        else
        {
            int_S_C_L_L_Node *current_Node = Linked_List->__Head_Node__->__Next_Node__;

            for (int i = 0; i < Linked_List->__Size__ - 1; i++)
            {
                if (current_Node->__Next_Node__->__Node_Data__ == element)
                {
                    break;
                }
                else
                {
                    current_Node = current_Node->__Next_Node__;
                }
            }
            if (current_Node->__Next_Node__ == Linked_List->__Head_Node__)
            {
            }
            else if (current_Node->__Next_Node__->__Node_Data__ == element)
            {
                int_S_C_L_L_Node *temp_Node = current_Node->__Next_Node__;
                current_Node->__Next_Node__ = current_Node->__Next_Node__->__Next_Node__;
                free(temp_Node);
                Linked_List->__Size__--;
            }
        }
    }
}

void __D_I_S_C_L_L_S_Append__(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *Linked_List, int element)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_I_S_C_L_L_S__ERROR_01__);
    }
    else if (Linked_List->__Size__ == 0)
    {
        Linked_List->__Head_Node__ = (int_S_C_L_L_Node *)malloc(sizeof(int_S_C_L_L_Node));
        Linked_List->__Head_Node__->__Node_Data__ = element;
        Linked_List->__Head_Node__->__Next_Node__ = NULL;
        Linked_List->__Size__++;
    }
    else if (Linked_List->__Size__ == 1)
    {
        Linked_List->__Foot_Node__ = (int_S_C_L_L_Node *)malloc(sizeof(int_S_C_L_L_Node));
        Linked_List->__Foot_Node__->__Next_Node__ = Linked_List->__Head_Node__;
        Linked_List->__Head_Node__->__Next_Node__ = Linked_List->__Foot_Node__;
        Linked_List->__Foot_Node__->__Node_Data__ = element;
        Linked_List->__Size__++;
    }
    else
    {
        int_S_C_L_L_Node *new_Node = (int_S_C_L_L_Node *)malloc(sizeof(int_S_C_L_L_Node));

        int temp_Data = Linked_List->__Foot_Node__->__Node_Data__;
        Linked_List->__Foot_Node__->__Next_Node__ = new_Node;
        Linked_List->__Foot_Node__->__Next_Node__->__Node_Data__ = element;
        Linked_List->__Foot_Node__->__Next_Node__->__Next_Node__ = Linked_List->__Head_Node__;
        Linked_List->__Foot_Node__ = Linked_List->__Foot_Node__->__Next_Node__;
        Linked_List->__Size__++;
    }
}

void __D_I_S_C_L_L_S_Represent__(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *Linked_List)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_I_S_C_L_L_S__ERROR_01__);
    }
    else if (Linked_List->__Size__ == 0)
    {
        printf("\n|> >> |");
        printf("\n/\\   \\/");
        printf("\n| << <|");
    }
    else
    {
        int digit_Array[Linked_List->__Size__];
        int temp = 0, count = 0;

        printf("\n");
        printf("|>");

        int_S_C_L_L_Node *current_Node = Linked_List->__Head_Node__;

        for (int i = 0; i < Linked_List->__Size__; i++)
        {
            printf(" %d >-|", current_Node->__Node_Data__);
            temp = (int)current_Node->__Node_Data__;
            current_Node = current_Node->__Next_Node__;
            count = 0;

            if (temp != abs(temp))
            {
                count = 1;
            }

            while (temp != 0)
            {
                temp /= 10;
                count++;
            }
            digit_Array[i] = count;
        }
        printf("\n");
        printf("/\\");

        for (int i = 0; i < Linked_List->__Size__; i++)
        {
            printf("   ");
            if (i != Linked_List->__Size__ - 1)
            {
                printf(" ");
            }
            for (int j = 0; j <= digit_Array[i]; j++)
            {
                printf(" ");
            }
        }
        printf("\b\\/");
        printf("\n");

        for (int i = 0; i < Linked_List->__Size__; i++)
        {
            if (i == Linked_List->__Size__ - 1)
            {
                if (i == 0)
                {
                    printf("|");
                    for (int j = 0; j < digit_Array[i]; j++)
                    {
                        printf("-");
                    }

                    printf("----<|");
                }
                else
                {
                    for (int j = 0; j < digit_Array[i]; j++)
                    {
                        printf("-");
                    }
                    printf("-----<|");
                }
            }
            else if (i == 0)
            {
                printf("|");
                for (int j = 0; j < digit_Array[i]; j++)
                {
                    printf("-");
                }
                printf("---<");
            }
            else
            {
                for (int j = 0; j < digit_Array[i]; j++)
                {
                    printf("-");
                }
                printf("----<");
            }
        }
    }
    printf("\n");
}

void __D_I_S_C_L_L_S_Delete__(struct Dynamic_Integer_Singly_Circular_Linked_List_Structure *Linked_List)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_I_S_C_L_L_S__ERROR_01__);
    }
    else
    {
        int_S_C_L_L_Node *current_Node = Linked_List->__Head_Node__;

        int_S_C_L_L_Node *temp_Node;

        while (Linked_List->__Head_Node__->__Next_Node__ != Linked_List->__Head_Node__->__Next_Node__)
        {
            temp_Node = Linked_List->__Head_Node__->__Next_Node__;
            Linked_List->__Head_Node__->__Next_Node__ = Linked_List->__Head_Node__->__Next_Node__->__Next_Node__;
            free(temp_Node);
        }
        free(Linked_List->__Head_Node__);
        Linked_List->__Size__ = -1;
    }
}

void __D_I_S_C_L_L_S_Initialize__(int_S_C_L_List *new_Linked_List)
{
    new_Linked_List->__Head_Node__ = NULL;
    new_Linked_List->__Foot_Node__ = NULL;
    new_Linked_List->__Size__ = 0;

    // Functions Declaration...
    (new_Linked_List->repr) = __D_I_S_C_L_L_S_Represent__;
    (new_Linked_List->delete) = __D_I_S_C_L_L_S_Delete__;
    (new_Linked_List->append) = __D_I_S_C_L_L_S_Append__;
    (new_Linked_List->remove) = __D_I_S_C_L_L_S_Remove__;
    (new_Linked_List->insert) = __D_I_S_C_L_L_S_Insert__;
}

#define init __D_I_S_C_L_L_S_Initialize__
#define size __Size__