#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_I_Q_S__ERROR_01__ "\nInteger Queue :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Integer Queue is Deleted!!!", __FUNCTION__
#define __D_I_Q_S__ERROR_02__ "\nInteger Queue :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Integer Queue Index Out of Range!!!", __FUNCTION__

typedef struct D_I_Q_S_Node
{
    int __Node_Data__;
    struct D_I_Q_S_Node *__Next_Node__;
    struct D_I_Q_S_Node *__Previous_Node__;
} int_Queue_Node;

/*
---
---
---
# Integer Queue :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Integer Queue in Curly Brackets.
---
### Arguments
#### 1. int_Queue structure
---
---
## 2. delete
#### Deletes The Whole Integer Queue.
---
### Arguments
#### 1. int_Queue structure
---
---
## 3. deQueue
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_Queue structure
#### 2. int index
---
---
## 4. peek
#### Returns The Index of First Occurrence of The Element In The Integer Queue, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_Queue structure
#### 2. int element
---
---
## 5. inQueue
#### Appends The Element At The End Of The Integer Queue.
---
### Arguments
#### 1. int_Queue structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Integer Queue.
---
### Arguments
#### 1. int_Queue structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Integer Queue.
---
### Arguments
#### 1. int_Queue structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Queue_Structure
{
    int __Size__; //#### Size of Integer Queue
    int_Queue_Node *__Front_End_Node__;
    int_Queue_Node *__Back_End_Node__;

    /*### Represents The Integer Queue in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Queue_Structure *structure);
    /*### Deletes The Whole Integer Queue. */
    void (*delete)(struct Dynamic_Integer_Queue_Structure *structure);
    /*### Removes The Element At First Index and Returns The Element. */
    int (*deQueue)(struct Dynamic_Integer_Queue_Structure *structure);
    /*### Returns The Index of First Occurrence of The Element In The Integer Queue, Returns -1 If The Element is Not Present In The List. */
    int (*peek)(struct Dynamic_Integer_Queue_Structure *structure, int element);
    /*### Appends The Element At The End of The Integer Queue. */
    void (*inQueue)(struct Dynamic_Integer_Queue_Structure *structure, int element);

} int_Queue;

int __D_I_Q_S_deQueue__(struct Dynamic_Integer_Queue_Structure *int_Queue)
{
    if (int_Queue->__Size__ == -1)
    {
        printf(__D_I_Q_S__ERROR_01__);
    }
    else if (int_Queue->__Size__ == 0)
    {
        printf(__D_I_Q_S__ERROR_02__);
    }
    else if (int_Queue->__Size__ == 1)
    {
        int_Queue_Node *temp_Node = int_Queue->__Front_End_Node__;
        int_Queue->__Front_End_Node__ = NULL;
        free(temp_Node);
        int_Queue->__Size__--;
    }
    else
    {
        int_Queue_Node *node = int_Queue->__Front_End_Node__;
        int_Queue_Node *new_Front_End_Node = int_Queue->__Front_End_Node__->__Previous_Node__;

        new_Front_End_Node->__Next_Node__ = NULL;
        int_Queue->__Front_End_Node__ = new_Front_End_Node;

        free(node);
        int_Queue->__Size__--;
    }
}

void __D_I_Q_S_inQueue__(struct Dynamic_Integer_Queue_Structure *int_Queue, int element)
{
    if (int_Queue->__Size__ == -1)
    {
        printf(__D_I_Q_S__ERROR_01__);
    }
    else
    {
        if (int_Queue->__Size__ == 0)
        {
            int_Queue->__Front_End_Node__ = (int_Queue_Node *)malloc(sizeof(int_Queue_Node));
            int_Queue->__Front_End_Node__->__Node_Data__ = element;
            int_Queue->__Front_End_Node__->__Next_Node__ = NULL;
        }
        else if (int_Queue->__Size__ == 1)
        {
            int_Queue->__Back_End_Node__ = (int_Queue_Node *)malloc(sizeof(int_Queue_Node));
            int_Queue->__Back_End_Node__->__Node_Data__ = element;
            int_Queue->__Back_End_Node__->__Next_Node__ = int_Queue->__Front_End_Node__;
            int_Queue->__Front_End_Node__->__Previous_Node__ = int_Queue->__Back_End_Node__;
            int_Queue->__Back_End_Node__->__Previous_Node__ = NULL;
        }
        else
        {
            int_Queue_Node *new_Node = (int_Queue_Node *)malloc(sizeof(int_Queue_Node));
            int_Queue_Node *old_Back_End_Node = int_Queue->__Back_End_Node__;

            new_Node->__Next_Node__ = old_Back_End_Node;
            new_Node->__Previous_Node__ = NULL;
            new_Node->__Node_Data__ = element;
            int_Queue->__Back_End_Node__ = new_Node;
            int_Queue->__Back_End_Node__ = new_Node;
            old_Back_End_Node->__Previous_Node__ = new_Node;
        }
        int_Queue->__Size__++;
    }
}

int __D_I_Q_S_Peek__(struct Dynamic_Integer_Queue_Structure *int_Queue, int element)
{
    int_Queue_Node *current_Node = int_Queue->__Front_End_Node__;
    for (int i = 0; i < int_Queue->__Size__; i++)
    {
        if (current_Node->__Node_Data__ == element)
        {
            return i;
        }
        else
        {
            current_Node = current_Node->__Previous_Node__;
        }
    }
    return -1;
}

void __D_I_Q_S_Represent__(struct Dynamic_Integer_Queue_Structure *int_Queue)
{
    if (int_Queue->__Size__ == -1)
    {
        printf(__D_I_Q_S__ERROR_01__);
    }
    else
    {
        if (int_Queue->__Size__ == 0)
        {
            printf("\n");
            printf("|| <]#");
        }
        else if (int_Queue->__Size__ == 1)
        {
            printf("\n");
            printf("|| <[%d]#", int_Queue->__Front_End_Node__->__Node_Data__);
        }
        else
        {
            printf("\n");
            printf("||");

            int_Queue_Node *current_Node = int_Queue->__Front_End_Node__;

            for (int i = 0; i < int_Queue->__Size__; i++)
            {
                printf(" <[%d]", current_Node->__Node_Data__);
                current_Node = current_Node->__Previous_Node__;
            }
            printf("#");
        }
    }
}

void __D_I_Q_S_Delete__(struct Dynamic_Integer_Queue_Structure *int_Queue)
{
    int_Queue_Node *current_Node = int_Queue->__Front_End_Node__;

    for (int i = 0; i < int_Queue->__Size__; i++)
    {
        int_Queue_Node *temp_Node = current_Node;
        current_Node = current_Node->__Previous_Node__;
        free(temp_Node);
    }
    int_Queue->__Size__ = -1;
}

void __D_I_Q_S_Initialize__(int_Queue *new_int_Queue)
{
    new_int_Queue->__Size__ = 0;
    new_int_Queue->__Front_End_Node__ = NULL;
    new_int_Queue->__Back_End_Node__ = NULL;

    // Functions Declaration...
    (new_int_Queue->deQueue) = __D_I_Q_S_deQueue__;
    (new_int_Queue->repr) = __D_I_Q_S_Represent__;
    (new_int_Queue->delete) = __D_I_Q_S_Delete__;
    (new_int_Queue->peek) = __D_I_Q_S_Peek__;
    (new_int_Queue->inQueue) = __D_I_Q_S_inQueue__;
}

#define int_Queue_init __D_I_Q_S_Initialize__
#define size __Size__
/*

   || <[1] <[2] <[3] <[4] <[5]*
*/