#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Sort Type of An Array To Efficient Uses.
#define __Sort_Type_Unsorted__ 0
#define __Sort_Type_Ascending__ 1
#define __Sort_Type_Descending__ 2

// Defining Some Error Massages
#define __D_I_A_S__ERROR_01__ "\nDynamic Integer Array:-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Array is Deleted!!!", __FUNCTION__
#define __D_I_A_S__ERROR_02__ "\nDynamic Integer Array:-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Array Index Out of Range!!!", __FUNCTION__

/*
---
---
---
# Dynamic Integer Array:
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
#### 1. int_Array structure
---
---
## 2. delete
#### Deletes The Whole Array.
---
### Arguments
#### 1. int_Array structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_Array structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Array, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_Array structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Array.
---
### Arguments
#### 1. int_Array structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Array.
---
### Arguments
#### 1. int_Array structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Array.
---
### Arguments
#### 1. int_Array structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Array_Structure
{
    int __Size__;                     //#### Size of Array
    int *__Base_Address__;            //#### Address of 0th Index of The Array
    unsigned short int __Sort_Type__; //#### Type of Array. Possible Values: 0. Unsorted, 1. Sorted in Ascending Order, 2. Sorted In Descending Order.

    /*### Represents The Array in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Array_Structure *structure);
    /*### Deletes The Whole Array. */
    void (*delete)(struct Dynamic_Integer_Array_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Integer_Array_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Array, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Integer_Array_Structure *structure, int element);
    /*### Appends The Element At The End of The Array. */
    void (*append)(struct Dynamic_Integer_Array_Structure *structure, int element);
    /*### Removes The First Occurrence Of The Specified Element in The Array. */
    void (*remove)(struct Dynamic_Integer_Array_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Array. */
    void (*insert)(struct Dynamic_Integer_Array_Structure *structure, int index, int element);

} int_Array;

void __D_I_A_S_Insert__(struct Dynamic_Integer_Array_Structure *arr, int index, int element)
{
    if ((arr->__Sort_Type__) == __Sort_Type_Ascending__)
    {
        if (((arr->__Base_Address__)[index - 1] > element) || (element < (arr->__Base_Address__)[index]))
        {
            arr->__Sort_Type__ = __Sort_Type_Unsorted__;
        }
    }
    else if ((arr->__Sort_Type__) == __Sort_Type_Descending__)
    {
        if (((arr->__Base_Address__)[index - 1] < element) || (element > (arr->__Base_Address__)[index]))
        {
            arr->__Sort_Type__ = __Sort_Type_Unsorted__;
        }
    }
    if ((arr->__Size__) == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
    }
    else if ((arr->__Size__) <= index)
    {
        printf(__D_I_A_S__ERROR_02__);
    }
    else
    {
        int temp_Array[(arr->__Size__)];

        for (int i = 0; i < (arr->__Size__); i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        (arr->__Size__)++;
        (arr->__Base_Address__) = (int *)realloc((arr->__Base_Address__), ((arr->__Size__) * sizeof(int)));

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

void __D_I_A_S_Remove__(struct Dynamic_Integer_Array_Structure *arr, int element)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
    }
    else
    {
        int first_Occurrence_Index = arr->search(arr, element);

        int temp_Array[(arr->__Size__) - 1];

        for (int i = 0; i < first_Occurrence_Index; i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        for (int i = (first_Occurrence_Index) + 1; i < (arr->__Size__); i++)
        {
            temp_Array[i - 1] = (arr->__Base_Address__)[i];
        }

        (arr->__Base_Address__) = (int *)realloc((arr->__Base_Address__), ((arr->__Size__) - 1) * sizeof(int));

        (arr->__Size__)--;
        for (int i = 0; i < (arr->__Size__); i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
    }
}

void __D_I_A_S_Append__(struct Dynamic_Integer_Array_Structure *arr, int element)
{
    if ((arr->__Sort_Type__) == __Sort_Type_Ascending__)
    {
        if ((arr->__Base_Address__)[(arr->__Size__)] > element)
        {
            arr->__Sort_Type__ = __Sort_Type_Unsorted__;
        }
    }
    else if ((arr->__Sort_Type__) == __Sort_Type_Descending__)
    {
        if ((arr->__Base_Address__)[(arr->__Size__)] < element)
        {
            arr->__Sort_Type__ = __Sort_Type_Unsorted__;
        }
    }
    if ((arr->__Size__) == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
    }
    else if ((arr->__Size__) == 0)
    {
        (arr->__Size__) = 1;
        (arr->__Base_Address__)[0] = element;
    }
    else
    {
        int temp_Array[(arr->__Size__)];

        for (int i = 0; i < (arr->__Size__); i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        (arr->__Size__)++;
        (arr->__Base_Address__) = (int *)realloc((arr->__Base_Address__), ((arr->__Size__) * sizeof(int)));

        for (int i = 0; i < (arr->__Size__) - 1; i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
        (arr->__Base_Address__)[(arr->__Size__) - 1] = element;
    }
}

int __D_I_A_S_Search__(struct Dynamic_Integer_Array_Structure *arr, int element)
{
    if (arr->__Size__ == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
    }
    else
    {
        if ((arr->__Sort_Type__) == __Sort_Type_Unsorted__)
        {
            for (int i = 0; i < (arr->__Size__); i++)
            {
                if ((arr->__Base_Address__)[i] == element)
                {
                    return i;
                }
            }
        }
        else if ((arr->__Sort_Type__) == __Sort_Type_Ascending__)
        {
            int middle_Index, Left_Most_Searching_Index, Right_Most_Searching_Index;
            Left_Most_Searching_Index = 0;
            Right_Most_Searching_Index = (arr->__Size__) - 1;

            while (Left_Most_Searching_Index <= Right_Most_Searching_Index)
            {
                middle_Index = (Left_Most_Searching_Index + Right_Most_Searching_Index) / 2;

                if ((arr->__Base_Address__)[middle_Index] == element)
                {
                    return middle_Index;
                }
                else if ((arr->__Base_Address__)[middle_Index] < element)
                {
                    Left_Most_Searching_Index = middle_Index + 1;
                }
                else
                {
                    Right_Most_Searching_Index = middle_Index - 1;
                }
            }
        }
        else if ((arr->__Sort_Type__) == __Sort_Type_Descending__)
        {
            int middle_Index, Left_Most_Searching_Index, Right_Most_Searching_Index;
            Left_Most_Searching_Index = 0;
            Right_Most_Searching_Index = (arr->__Size__) - 1;

            while (Left_Most_Searching_Index <= Right_Most_Searching_Index)
            {
                middle_Index = (Left_Most_Searching_Index + Right_Most_Searching_Index) / 2;

                if ((arr->__Base_Address__)[middle_Index] == element)
                {
                    return middle_Index;
                }
                else if ((arr->__Base_Address__)[middle_Index] > element)
                {
                    Left_Most_Searching_Index = middle_Index + 1;
                }
                else
                {
                    Right_Most_Searching_Index = middle_Index - 1;
                }
            }
        }
    }
    return -1;
}

int __D_I_A_S_Pop__(struct Dynamic_Integer_Array_Structure *arr, int index)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
        return -1;
    }
    else if ((arr->__Size__) <= index)
    {
        printf(__D_I_A_S__ERROR_02__);
    }
    else
    {
        int popped_Element = (arr->__Base_Address__)[index];

        int temp_Array[(arr->__Size__) - 1];

        for (int i = 0; i < index; i++)
        {
            temp_Array[i] = (arr->__Base_Address__)[i];
        }

        for (int i = index + 1; i < (arr->__Size__); i++)
        {
            temp_Array[i - 1] = (arr->__Base_Address__)[i];
        }

        (arr->__Base_Address__) = (int *)realloc((arr->__Base_Address__), ((arr->__Size__) - 1) * sizeof(int));

        (arr->__Size__)--;
        for (int i = 0; i < (arr->__Size__); i++)
        {
            (arr->__Base_Address__)[i] = temp_Array[i];
        }
        return popped_Element;
    }
}

void __D_I_A_S_Represent__(struct Dynamic_Integer_Array_Structure *arr)
{
    if ((arr->__Size__) == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
    }
    else if (arr->__Size__ == 0)
    {
        printf("\nDynamic Integer Array: {}.");
    }
    else
    {
        printf("\n{%d", arr->__Base_Address__[0]);

        for (int i = 1; i < (arr->__Size__); i++)
        {
            printf(", %d", (arr->__Base_Address__)[i]);
        }
        printf("}.");
    }
}

void __D_I_A_S_Delete__(struct Dynamic_Integer_Array_Structure *arr)
{
    if (arr->__Size__ == -1)
    {
        printf(__D_I_A_S__ERROR_01__);
        printf(" Already!!!");
    }
    else
    {
        (arr->__Size__) = -1;
        free(arr->__Base_Address__);
    }
}

void __D_I_A_S_Initialize__(int_Array *new_Array)
{
    new_Array->__Size__ = 0;
    new_Array->__Sort_Type__ = __Sort_Type_Unsorted__;
    (new_Array->__Base_Address__) = (int *)malloc(sizeof(int));
    // Functions Declaration...
    (new_Array->pop) = __D_I_A_S_Pop__;
    (new_Array->repr) = __D_I_A_S_Represent__;
    (new_Array->delete) = __D_I_A_S_Delete__;
    (new_Array->search) = __D_I_A_S_Search__;
    (new_Array->append) = __D_I_A_S_Append__;
    (new_Array->remove) = __D_I_A_S_Remove__;
    (new_Array->insert) = __D_I_A_S_Insert__;
}

#define init __D_I_A_S_Initialize__
#define size __Size__
