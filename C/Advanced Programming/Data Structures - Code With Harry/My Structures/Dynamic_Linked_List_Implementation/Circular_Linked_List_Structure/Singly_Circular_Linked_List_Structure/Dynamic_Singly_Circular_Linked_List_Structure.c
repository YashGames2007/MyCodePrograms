#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_S_C_L_L_S__ERROR_01__ "\nSingly Circular Linked List:-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Linked List is Deleted!!!", __FUNCTION__
#define __D_S_C_L_L_S__ERROR_02__ "\nSingly Circular Linked List:-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Linked List Index Out of Range!!!", __FUNCTION__

/*
---
---
---
# Singly Circular Linked List:
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
typedef struct Dynamic_Integer_Singly_Circular_Linked_List__Structure
{
    int __Size__;                     //#### Size of Linked List

    /*### Represents The Linked List in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure);
    /*### Deletes The Whole Linked List. */
    void (*delete)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Linked List, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure, int element);
    /*### Appends The Element At The End of The Linked List. */
    void (*append)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure, int element);
    /*### Removes The First Occurrence Of The Specified Element in The Linked List. */
    void (*remove)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Linked List. */
    void (*insert)(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *structure, int index, int element);

} int_S_C_L_List;

void __D_S_C_L_L_S_Insert__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr, int index, int element)
{
}

void __D_S_C_L_L_S_Remove__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr, int element)
{
}

void __D_S_C_L_L_S_Append__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr, int element)
{
}

int __D_S_C_L_L_S_Search__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr, int element)
{
}

int __D_S_C_L_L_S_Pop__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr, int index)
{
}

void __D_S_C_L_L_S_Represent__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr)
{
}

void __D_S_C_L_L_S_Delete__(struct Dynamic_Integer_Singly_Circular_Linked_List__Structure *arr)
{
}

void __D_S_C_L_L_S_Initialize__(int_S_C_L_List *new_Linked_List)
{
    new_Linked_List->__Size__ = 0;
    
    // Functions Declaration...
    (new_Linked_List->pop) = __D_S_C_L_L_S_Pop__;
    (new_Linked_List->repr) = __D_S_C_L_L_S_Represent__;
    (new_Linked_List->delete) = __D_S_C_L_L_S_Delete__;
    (new_Linked_List->search) = __D_S_C_L_L_S_Search__;
    (new_Linked_List->append) = __D_S_C_L_L_S_Append__;
    (new_Linked_List->remove) = __D_S_C_L_L_S_Remove__;
    (new_Linked_List->insert) = __D_S_C_L_L_S_Insert__;
}

#define init __D_S_C_L_L_S_Initialize__
#define size __Size__