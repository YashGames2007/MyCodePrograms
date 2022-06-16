#include <stdio.h>
#include <stdlib.h>

#define __D_S_I_L_L_S__ERROR_01__ "\nDynamic Singly Integer Linked List:-| ERROR 01 | Unable To Perform <%s> Operation On Linked List Because List Is Deleted!!!", __FUNCTION__
#define __D_S_I_L_L_S__ERROR_02__ "\nDynamic Singly Integer Linked List:-| ERROR 02 | Unable To Perform <%s> Operation On Linked List Because Index Got Out Of Range!!!", __FUNCTION__

typedef struct Singly_Integer_Linked_List_Node
{
    int __Node_Data__;
    struct Singly_Integer_Linked_List_Node *__Next_Node__;
} int_S_L_L_Node;

/*
---
---
---
# Dynamic Integer Singly Linked List:
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
#### 1. int_S_L_List structure
---
---
## 2. delete
#### Deletes The Whole Linked List.
---
### Arguments
#### 1. int_S_L_List structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_S_L_List structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Linked List, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_S_L_List structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Linked List.
---
### Arguments
#### 1. int_S_L_List structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Linked List.
---
### Arguments
#### 1. int_S_L_List structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Linked List.
---
### Arguments
#### 1. int_S_L_List structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Singly_Integer_Linked_List_Structure
{
    int_S_L_L_Node *__Head_Node__;
    int_S_L_L_Node *__Foot_Node__;
    int __Size__;
    // Defining Some Functions...
    void (*repr)(struct Dynamic_Singly_Integer_Linked_List_Structure *structure);
    void (*delete)(struct Dynamic_Singly_Integer_Linked_List_Structure *structure);
    void (*remove)(struct Dynamic_Singly_Integer_Linked_List_Structure *structure, int element);
    void (*append)(struct Dynamic_Singly_Integer_Linked_List_Structure *structure, int element);
    void (*insert)(struct Dynamic_Singly_Integer_Linked_List_Structure *structure, int index, int element);

} int_S_L_List;

void __D_S_I_L_L_S_Insert__(int_S_L_List *linked_List, int index, int element)
{
    if (linked_List->__Size__ == -1)
    {
        printf(__D_S_I_L_L_S__ERROR_01__);
    }
    else if (linked_List->__Size__ <= index)
    {
        printf(__D_S_I_L_L_S__ERROR_02__);
    }
    else
    {
        int_S_L_L_Node *new_Node = (int_S_L_L_Node *)malloc(sizeof(int_S_L_L_Node));

        int_S_L_L_Node *current_Node = linked_List->__Head_Node__;

        for (int i = 0; i < index - 1; i++)
        {
            current_Node = current_Node->__Next_Node__;
        }
        new_Node->__Node_Data__ = element;
        new_Node->__Next_Node__ = current_Node->__Next_Node__;
        current_Node->__Next_Node__ = new_Node;
        linked_List->__Size__++;
    }
}

void __D_S_I_L_L_S_Append__(int_S_L_List *linked_List, int element)
{
    if (linked_List->__Size__ == -1)
    {
        printf(__D_S_I_L_L_S__ERROR_01__);
    }
    else
    {
        if (linked_List->__Size__ == 0)
        {
            linked_List->__Head_Node__ = (int_S_L_L_Node *)malloc(sizeof(int_S_L_L_Node));
            linked_List->__Head_Node__->__Node_Data__ = element;
            linked_List->__Head_Node__->__Next_Node__ = NULL;
        }
        else if (linked_List->__Size__ == 1)
        {
            linked_List->__Foot_Node__ = (int_S_L_L_Node *)malloc(sizeof(int_S_L_L_Node));
            linked_List->__Foot_Node__->__Node_Data__ = element;
            linked_List->__Foot_Node__->__Next_Node__ = NULL; 
            linked_List->__Head_Node__->__Next_Node__ = linked_List->__Foot_Node__;
        }
        else
        {
            int_S_L_L_Node *new_Node = (int_S_L_L_Node *)malloc(sizeof(int_S_L_L_Node));

            linked_List->__Foot_Node__->__Next_Node__ = new_Node;
            linked_List->__Foot_Node__->__Next_Node__->__Node_Data__ = element;
            linked_List->__Foot_Node__->__Next_Node__->__Next_Node__ = NULL;
            linked_List->__Foot_Node__ = linked_List->__Foot_Node__->__Next_Node__;
        }
        linked_List->__Size__++;
    }
}

void _D_S_I_L_L_S_Remove__(int_S_L_List *linked_List, int element)
{
    if (linked_List->__Size__ == -1)
    {
        printf(__D_S_I_L_L_S__ERROR_01__);
    }
    else
    {
        int_S_L_L_Node *current_Node = linked_List->__Head_Node__;

        if (linked_List->__Head_Node__->__Node_Data__ == element)
        {
            int_S_L_L_Node *temp_Node = linked_List->__Head_Node__;
            linked_List->__Head_Node__ = linked_List->__Head_Node__->__Next_Node__;
            linked_List->__Size__--;
            free(temp_Node);
        }
        else
        {
            for (int i = 0; i < linked_List->__Size__ - 1; i++)
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
            if (current_Node->__Next_Node__ == NULL)
            {
            }
            else if (current_Node->__Next_Node__->__Node_Data__ == element)
            {
                int_S_L_L_Node *node = current_Node->__Next_Node__;
                current_Node->__Next_Node__ = current_Node->__Next_Node__->__Next_Node__;
                free(node);
                linked_List->__Size__--;
            }
        }
    }
}

void _D_S_I_L_L_S_Delete__(int_S_L_List *linked_List)
{
    if (linked_List->__Size__ == -1)
    {
        printf(__D_S_I_L_L_S__ERROR_01__);
    }
    else
    {
        int_S_L_L_Node *current_Node = linked_List->__Head_Node__;
        int_S_L_L_Node *temp;

        while (linked_List->__Head_Node__->__Next_Node__ != NULL)
        {
            temp = linked_List->__Head_Node__->__Next_Node__;
            linked_List->__Head_Node__->__Next_Node__ = linked_List->__Head_Node__->__Next_Node__->__Next_Node__;
            free(temp);
        }
        free(linked_List->__Head_Node__);
        linked_List->__Size__ = -1;
    }
}

void __D_S_I_L_L_S_Represent__(int_S_L_List *linked_List)
{
    if (linked_List->__Size__ == -1)
    {
        printf(__D_S_I_L_L_S__ERROR_01__);
    }
    else
    {
        if (linked_List->__Head_Node__ == NULL)
        {
            printf("\n| >");
        }
        else
        {
            printf("\n| ");

            int_S_L_L_Node *current_Node = linked_List->__Head_Node__;

            for (int i = 0; i < linked_List->__Size__ - 1; i++)
            {
                printf("%d >-| ", current_Node->__Node_Data__);
                current_Node = current_Node->__Next_Node__;
            }
            printf("%d >", current_Node->__Node_Data__);
        }
    }
}

void __D_S_I_L_L_S_Initialize__(int_S_L_List *new_List)
{
    new_List->__Head_Node__ = NULL;
    new_List->__Foot_Node__ = NULL;
    new_List->__Size__ = 0;

    // Initializing Methods...
    new_List->insert = __D_S_I_L_L_S_Insert__;
    new_List->append = __D_S_I_L_L_S_Append__;
    new_List->remove = _D_S_I_L_L_S_Remove__;
    new_List->delete = _D_S_I_L_L_S_Delete__;
    new_List->repr = __D_S_I_L_L_S_Represent__;
}

#define int_S_L_List_init __D_S_I_L_L_S_Initialize__