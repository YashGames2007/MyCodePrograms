#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_D_L_L__ERROR_01__ "\nDoubly Linked List :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Linked List is Deleted!!!", __FUNCTION__
#define __D_D_L_L__ERROR_02__ "\nDoubly Linked List :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Linked List Index Out of Range!!!", __FUNCTION__

typedef struct D_D_L_L_Node
{
    int __Node_Data__;
    struct D_D_L_L_Node *__Previous_Node__;
    struct D_D_L_L_Node *__Next_Node__;
} int_D_L_L_Node;

/*
---
---
---
# Doubly Linked List :
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
#### 1. int_D_D_L_List structure
---
---
## 2. delete
#### Deletes The Whole Linked List.
---
### Arguments
#### 1. int_D_D_L_List structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_D_D_L_List structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Linked List, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_D_D_L_List structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Linked List.
---
### Arguments
#### 1. int_D_D_L_List structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Linked List.
---
### Arguments
#### 1. int_D_D_L_List structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Linked List.
---
### Arguments
#### 1. int_D_D_L_List structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Doubly_Linked_List_Structure
{
    int_D_L_L_Node *__Head_Node__;
    int_D_L_L_Node *__Foot_Node__;
    int __Size__;                     //#### Size of Linked List
    /*### Represents The Linked List in Curly Brackets. */
    void (*repr)(struct Dynamic_Doubly_Linked_List_Structure *structure);
    /*### Deletes The Whole Linked List. */
    void (*delete)(struct Dynamic_Doubly_Linked_List_Structure *structure);
    /*### Appends The Element At The End of The Linked List. */
    void (*append)(struct Dynamic_Doubly_Linked_List_Structure *structure, int element);
    /*### Removes The First Occurrence Of The Specified Element in The Linked List. */
    void (*remove)(struct Dynamic_Doubly_Linked_List_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Linked List. */
    void (*insert)(struct Dynamic_Doubly_Linked_List_Structure *structure, int index, int element);

} int_D_D_L_List;

void __D_D_L_L_Insert__(struct Dynamic_Doubly_Linked_List_Structure *Linked_List, int index, int element)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_D_L_L__ERROR_01__);
    }
    else if (Linked_List->__Size__ <= index)
    {
        printf(__D_D_L_L__ERROR_02__);
    }
    else
    {
        int_D_L_L_Node *new_Node = (int_D_L_L_Node *)malloc(sizeof(int_D_L_L_Node));

        int_D_L_L_Node *current_Node = Linked_List->__Head_Node__;

        for (int i = 0; i < index - 1; i++)
        {
            current_Node = current_Node->__Next_Node__;
        }
        new_Node->__Node_Data__ = element;
        new_Node->__Next_Node__ = current_Node->__Next_Node__;
        new_Node->__Previous_Node__ = current_Node;
        current_Node->__Next_Node__->__Previous_Node__ = new_Node;
        current_Node->__Next_Node__ = new_Node;
        Linked_List->__Size__++;
    }
}

void __D_D_L_L_Remove__(struct Dynamic_Doubly_Linked_List_Structure *Linked_List, int element)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_D_L_L__ERROR_01__);
    }
    else
    {
        int_D_L_L_Node *current_Node = Linked_List->__Head_Node__;

        if (Linked_List->__Head_Node__->__Node_Data__ == element)
        {
            int_D_L_L_Node *temp_Node = Linked_List->__Head_Node__;
            Linked_List->__Head_Node__ = Linked_List->__Head_Node__->__Next_Node__;
            Linked_List->__Head_Node__->__Previous_Node__ = NULL;
            Linked_List->__Size__--;
            free(temp_Node);
        }
        else
        {
            for (int i = 0; i < Linked_List->__Size__ - 1; i++)
            {
                if (current_Node->__Node_Data__ == element)
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
                current_Node->__Previous_Node__->__Next_Node__ = NULL;
                Linked_List->__Foot_Node__ = current_Node->__Previous_Node__;
                free(current_Node);
            }
            else if (current_Node->__Node_Data__ == element)
            {
                int_D_L_L_Node *node = current_Node;

                current_Node->__Previous_Node__->__Next_Node__ = current_Node->__Next_Node__;
                current_Node->__Next_Node__->__Previous_Node__ = current_Node->__Previous_Node__;
                free(node);
                Linked_List->__Size__--;
            }
        }
    }
}

void __D_D_L_L_Append__(struct Dynamic_Doubly_Linked_List_Structure *Linked_List, int element)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_D_L_L__ERROR_01__);
    }
    else
    {
        if (Linked_List->__Size__ == 0)
        {
            Linked_List->__Head_Node__ = (int_D_L_L_Node *)malloc(sizeof(int_D_L_L_Node));
            Linked_List->__Head_Node__->__Node_Data__ = element;
            Linked_List->__Head_Node__->__Previous_Node__ = NULL;
            Linked_List->__Head_Node__->__Next_Node__ = NULL;
        }
        else if (Linked_List->__Size__ == 1)
        {
            Linked_List->__Foot_Node__ = (int_D_L_L_Node *)malloc(sizeof(int_D_L_L_Node));
            Linked_List->__Foot_Node__->__Node_Data__ = element;
            Linked_List->__Foot_Node__->__Previous_Node__ = Linked_List->__Head_Node__;
            Linked_List->__Head_Node__->__Next_Node__ = Linked_List->__Foot_Node__;
            Linked_List->__Foot_Node__->__Next_Node__ = NULL;
        }
        else
        {
            int_D_L_L_Node *new_Node = (int_D_L_L_Node *)malloc(sizeof(int_D_L_L_Node));

            new_Node->__Node_Data__ = element;

            new_Node->__Previous_Node__ = Linked_List->__Foot_Node__;
            Linked_List->__Foot_Node__->__Next_Node__ = new_Node;
            new_Node->__Next_Node__ = NULL;
            Linked_List->__Foot_Node__ = Linked_List->__Foot_Node__->__Next_Node__;
        }
        Linked_List->__Size__++;
    }
}

void __D_D_L_L_Represent__(struct Dynamic_Doubly_Linked_List_Structure *Linked_List)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_D_L_L__ERROR_01__);
    }
    else
    {
        if (Linked_List->__Size__ == 0)
        {
            printf("\n||=>><><<=||");
        }
        else
        {
            printf("\n||=<<=|| ");

            int_D_L_L_Node *current_Node = Linked_List->__Foot_Node__;

            for (int i = 0; i < Linked_List->__Size__ - 1; i++)
            {
                printf("%d ||=>>=<<=|| ", current_Node->__Node_Data__);
                current_Node = current_Node->__Previous_Node__;
            }
            printf("%d ||=>>=||", current_Node->__Node_Data__);
        }
    }
}

void __D_D_L_L_Delete__(struct Dynamic_Doubly_Linked_List_Structure *Linked_List)
{
    if (Linked_List->__Size__ == -1)
    {
        printf(__D_D_L_L__ERROR_01__);
    }
    else
    {
        int_D_L_L_Node *current_Node = Linked_List->__Head_Node__;
        int_D_L_L_Node *temp;

        while (Linked_List->__Head_Node__->__Next_Node__ != NULL)
        {
            temp = Linked_List->__Head_Node__->__Next_Node__;
            Linked_List->__Head_Node__->__Next_Node__ = Linked_List->__Head_Node__->__Next_Node__->__Next_Node__;
            free(temp);
        }
        free(Linked_List->__Head_Node__);
        Linked_List->__Size__ = -1;
    }
}

void __D_D_L_L_Initialize__(int_D_D_L_List *new_Linked_List)
{
    new_Linked_List->__Size__ = 0;
    
    // Functions Declaration...
    (new_Linked_List->repr) = __D_D_L_L_Represent__;
    (new_Linked_List->delete) = __D_D_L_L_Delete__;
    (new_Linked_List->append) = __D_D_L_L_Append__;
    (new_Linked_List->remove) = __D_D_L_L_Remove__;
    (new_Linked_List->insert) = __D_D_L_L_Insert__;
}

#define init __D_D_L_L_Initialize__
#define size __Size__