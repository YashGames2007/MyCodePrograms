#include <stdio.h>
#include <stdlib.h>

// Defining Some Error Massages
#define __D_P_A_S__ERROR_01__ "\nDynamic Pointer Array:-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Array is Deleted!!!", __FUNCTION__
#define __D_P_A_S__ERROR_02__ "\nDynamic Pointer Array:-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Array Index Out of Range!!!", __FUNCTION__

/*
---
---
---
# Dynamic Pointer Array:
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Array in Curly Brackets.
---
### Arguments
#### 1. ptr_Array structure
---
---
## 2. delete
#### Deletes The Whole Array.
---
### Arguments
#### 1. ptr_Array structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. ptr_Array structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Array, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. ptr_Array structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Array.
---
### Arguments
#### 1. ptr_Array structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Array.
---
### Arguments
#### 1. ptr_Array structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Array.
---
### Arguments
#### 1. ptr_Array structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Pointer_Array_Structure
{
    int __Size__;            //#### Size of Array
    void **__Base_Address__; //#### Address of 0th Index of The Array

    /*### Delete The Whole Array. */
    void (*delete)(struct Dynamic_Pointer_Array_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    void *(*pop)(struct Dynamic_Pointer_Array_Structure *structure, int index);
    /*### Returns The Element At Given Index. */
    void *(*get)(struct Dynamic_Pointer_Array_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Array, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Pointer_Array_Structure *structure, void *element);
    /*### Appends The Element At The End of The Array. */
    void (*append)(struct Dynamic_Pointer_Array_Structure *structure, void *element);
    /*### Removes The First Occurrence Of The Specified Element in The Array. */
    void (*remove)(struct Dynamic_Pointer_Array_Structure *structure, void *element);
    /*### Inserts The Element At Specified Index In The Array. */
    void (*insert)(struct Dynamic_Pointer_Array_Structure *structure, int index, void *element);

} ptr_Array;

void __D_P_A_S_Insert__(struct Dynamic_Pointer_Array_Structure *arr, int index, void *element)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
    }
    else if ((arr->__Size__) <= index)
    {
        printf(__D_P_A_S__ERROR_02__);
    }
    else
    {
        void *temp_Array[(arr->__Size__)];

        for (int i = 0; i < (arr->__Size__); i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        (arr->__Size__)++;
        (arr->__Base_Address__) = (void **)realloc((arr->__Base_Address__), ((arr->__Size__) * sizeof(void *)));

        for (int i = 0; i < index; i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
        (arr->__Base_Address__)[index] = element;

        for (int i = (index + 1); i < (arr->__Size__); i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i - 1];
        }
    }
}

void __D_P_A_S_Remove__(struct Dynamic_Pointer_Array_Structure *arr, void *element)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
    }
    else
    {
        int first_Occurrence_Index = arr->search(arr, element);

        void *temp_Array[(arr->__Size__) - 1];

        for (int i = 0; i < first_Occurrence_Index; i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        for (int i = (first_Occurrence_Index) + 1; i < (arr->__Size__); i++)
        {
            temp_Array[i - 1] = (arr->__Base_Address__)[i];
        }

        (arr->__Base_Address__) = (void **)realloc((arr->__Base_Address__), ((arr->__Size__) - 1) * sizeof(void *));

        (arr->__Size__)--;
        for (int i = 0; i < (arr->__Size__); i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
    }
}

void __D_P_A_S_Append__(struct Dynamic_Pointer_Array_Structure *arr, void *element)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
    }
    else if ((arr->__Size__) == 0)
    {
        (arr->__Size__) = 1;
        (arr->__Base_Address__)[0] = element;
    }
    else
    {
        void *temp_Array[(arr->__Size__)];

        for (int i = 0; i < (arr->__Size__); i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        (arr->__Size__)++;
        (arr->__Base_Address__) = (void **)realloc((arr->__Base_Address__), ((arr->__Size__) * sizeof(void *)));

        for (int i = 0; i < (arr->__Size__) - 1; i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
        (arr->__Base_Address__)[(arr->__Size__) - 1] = element;
    }
}

int __D_P_A_S_Search__(struct Dynamic_Pointer_Array_Structure *arr, void *element)
{
    if (arr->__Size__ == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
    }
    else
    {
        for (int i = 0; i < (arr->__Size__); i++)
        {
            if ((arr->__Base_Address__)[i] == element)
            {
                return i;
            }
        }

        return -1;
    }
}

void *__D_P_A_S_Pop__(struct Dynamic_Pointer_Array_Structure *arr, int index)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
        return NULL;
    }
    else if ((arr->__Size__) <= index)
    {
        printf(__D_P_A_S__ERROR_02__);
    }
    else
    {
        void *popped_Element = (arr->__Base_Address__)[index];

        void *temp_Array[(arr->__Size__) - 1];

        for (int i = 0; i < index; i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        for (int i = index + 1; i < (arr->__Size__); i++)
        {
            temp_Array[i - 1] = (arr->__Base_Address__)[i];
        }

        (arr->__Base_Address__) = (void **)realloc((arr->__Base_Address__), ((arr->__Size__) - 1) * sizeof(void *));

        (arr->__Size__)--;
        for (int i = 0; i < (arr->__Size__); i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
        return popped_Element;
    }
}

void *__D_P_A_S_Get__(struct Dynamic_Pointer_Array_Structure *arr, int index)
{
    if (index >= arr->__Size__)
    {
        printf(__D_P_A_S__ERROR_02__);
        return NULL;
    }
    
    return arr->__Base_Address__[abs(index)];
}

void __D_P_A_S_Delete__(struct Dynamic_Pointer_Array_Structure *arr)
{
    if (arr->__Size__ == -1)
    {
        printf(__D_P_A_S__ERROR_01__);
        printf(" Already!!!");
    }
    else
    {
        (arr->__Size__) = -1;
        free(arr->__Base_Address__);
    }
}

void __D_P_A_S_Initialize__(ptr_Array *new_Array)
{
    new_Array->__Size__ = 0;
    new_Array->__Base_Address__ = (void **)malloc(sizeof(void *));
    // Functions Declaration...
    (new_Array->pop) = __D_P_A_S_Pop__;
    (new_Array->get) = __D_P_A_S_Get__;
    (new_Array->delete) = __D_P_A_S_Delete__;
    (new_Array->search) = __D_P_A_S_Search__;
    (new_Array->append) = __D_P_A_S_Append__;
    (new_Array->remove) = __D_P_A_S_Remove__;
    (new_Array->insert) = __D_P_A_S_Insert__;
}

#define ptr_Array_init __D_P_A_S_Initialize__
#define size __Size__