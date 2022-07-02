#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_I_B_S_T_S__ERROR_01__ "\n\aInteger Binary Search Tree :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Integer Binary Search Tree is Deleted!!!", __FUNCTION__
#define __D_I_B_S_T_S__ERROR_02__ "\n\aInteger Binary Search Tree :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Integer Binary Search Tree Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Integer_Binary_Search_Tree_Structure_Node
{
    int __Node_Data__;
    int __Node_Level__;
    struct Dynamic_Integer_Binary_Search_Tree_Structure_Node *__Parent_Node__;
    struct Dynamic_Integer_Binary_Search_Tree_Structure_Node *__Left_Child_Node__;
    struct Dynamic_Integer_Binary_Search_Tree_Structure_Node *__Right_Child_Node__;

} D_I_B_S_T_S_Node;

D_I_B_S_T_S_Node *__Create_Node__(D_I_B_S_T_S_Node *parent_Node, int node_Level, int node_Data)
{
    D_I_B_S_T_S_Node *new_Node = (D_I_B_S_T_S_Node *)malloc(sizeof(D_I_B_S_T_S_Node));
    new_Node->__Left_Child_Node__ = NULL;
    new_Node->__Right_Child_Node__ = NULL;
    new_Node->__Node_Data__ = node_Data;
    new_Node->__Node_Level__ = node_Level;
    new_Node->__Parent_Node__ = parent_Node;
}

void __Traverse_Represent_Node__(D_I_B_S_T_S_Node *root_Node, char *string)
{
    if (root_Node != NULL)
    {
        printf("\n%s[%d]", string, root_Node->__Node_Data__);
        char new_String[strlen(string) + 3];
        strcpy(new_String, string);
        strcat(new_String, " |");
        printf("\n%s", new_String);

        __Traverse_Represent_Node__(root_Node->__Left_Child_Node__, new_String);
        __Traverse_Represent_Node__(root_Node->__Right_Child_Node__, new_String);
    }
}

void __Traverse_Delete_Node__(D_I_B_S_T_S_Node *root_Node)
{
    if (root_Node != NULL)
    {
        __Traverse_Delete_Node__(root_Node->__Left_Child_Node__);
        __Traverse_Delete_Node__(root_Node->__Right_Child_Node__);
        free(root_Node);
    }
}

D_I_B_S_T_S_Node *__Traverse_InOrder_Predecessor__(D_I_B_S_T_S_Node *root_Node)
{
    root_Node = root_Node->__Left_Child_Node__;
    while (root_Node->__Right_Child_Node__ != NULL)
    {
        root_Node = root_Node->__Right_Child_Node__;
    }
    return root_Node;
}

D_I_B_S_T_S_Node *__Traverse_Remove_Node__(D_I_B_S_T_S_Node *root_Node, int element)
{
    if (root_Node == NULL)
    {
        return NULL;
    }
    if (root_Node->__Left_Child_Node__ == NULL && root_Node->__Right_Child_Node__ == NULL)
    {
        free(root_Node);
        return NULL;
    }
    
    if (element < root_Node->__Node_Data__)
    {
        root_Node->__Left_Child_Node__ = __Traverse_Remove_Node__(root_Node->__Left_Child_Node__, element);
    }
    else if (element > root_Node->__Node_Data__)
    {
        root_Node->__Right_Child_Node__ =  __Traverse_Remove_Node__(root_Node->__Right_Child_Node__, element);
    }
    else
    {
        D_I_B_S_T_S_Node *inOrder_Predecessor = __Traverse_InOrder_Predecessor__(root_Node);
        root_Node->__Node_Data__ = inOrder_Predecessor->__Node_Data__;
        root_Node->__Left_Child_Node__ =  __Traverse_Remove_Node__(root_Node->__Left_Child_Node__, inOrder_Predecessor->__Node_Data__);
    }
    return root_Node;
}

int __Traverse_Search_Node__(D_I_B_S_T_S_Node *root_Node, int element, int *path, int current_Index, int *size)
{
    if (root_Node == NULL)
    {
        return 0;
    }
    if (root_Node->__Node_Data__ == element)
    {
        return 1;
    }
    else if (root_Node->__Node_Data__ > element)
    {
        if (__Traverse_Search_Node__(root_Node->__Left_Child_Node__, element, path, (current_Index + 1), size) == 1)
        {
            path[current_Index] = 0;
            *size += 1;
            return 1;
        }
    }
    else
    {
        if (__Traverse_Search_Node__(root_Node->__Right_Child_Node__, element, path, (current_Index + 1), size) == 1)
        {
            path[current_Index] = 1;
            *size += 1;
            return 1;
        }
    }
    return 0;
}

/*
---
---
---
# Integer Binary Search Tree :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Integer Binary Search Tree in Curly Brackets.
---
### Arguments
#### 1. int_BS_Tree structure
---
---
## 2. delete
#### Deletes The Whole Integer Binary Search Tree.
---
### Arguments
#### 1. int_BS_Tree structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_BS_Tree structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Integer Binary Search Tree, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_BS_Tree structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Integer Binary Search Tree.
---
### Arguments
#### 1. int_BS_Tree structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Integer Binary Search Tree.
---
### Arguments
#### 1. int_BS_Tree structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Integer Binary Search Tree.
---
### Arguments
#### 1. int_BS_Tree structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Binary_Search_Tree_Structure
{
    int __Height__;                  //#### Maximum Depth of Integer Binary Search Tree
    D_I_B_S_T_S_Node *__Root_Node__; //#### Root Node Of Integer Binary Search Tree

    /*### Represents The Integer Binary Search Tree in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure);
    /*### Deletes The Whole Integer Binary Search Tree. */
    void (*delete)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Integer Binary Search Tree, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure, int element, int *path);
    /*### Removes The First Occurrence Of The Specified Element in The Integer Binary Search Tree. */
    void (*remove)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Integer Binary Search Tree. */
    void (*add)(struct Dynamic_Integer_Binary_Search_Tree_Structure *structure, int element);

} int_B_S_Tree;

void __D_I_B_S_T_S_Add__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree, int element)
{
    D_I_B_S_T_S_Node *previous_Node = NULL;
    D_I_B_S_T_S_Node *root_Node = int_BS_Tree->__Root_Node__;

    while (root_Node != NULL)
    {
        previous_Node = root_Node;
        if (root_Node->__Node_Data__ == element)
        {
            return;
        }
        else if (root_Node->__Node_Data__ > element)
        {
            root_Node = root_Node->__Left_Child_Node__;
        }
        else
        {
            root_Node = root_Node->__Right_Child_Node__;
        }
    }
    
    D_I_B_S_T_S_Node *new_Node = __Create_Node__(previous_Node, (previous_Node->__Node_Level__ + 1), element);

    if (previous_Node->__Node_Data__ > element)
    {
        previous_Node->__Left_Child_Node__ = new_Node;
    }
    else
    {
        previous_Node->__Right_Child_Node__ = new_Node;
    }
}

void __D_I_B_S_T_S_Remove__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree, int element)
{
    __Traverse_Remove_Node__(int_BS_Tree->__Root_Node__, element);
}

int __D_I_B_S_T_S_Search__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree, int element, int *path)
{
    if (int_BS_Tree->__Root_Node__->__Node_Data__ == element)
    {
        return 0;
    }
    int size = 0;
    path[0] = -1;
    __Traverse_Search_Node__(int_BS_Tree->__Root_Node__, element, path, 0, &size);
    return size;
}

int __D_I_B_S_T_S_Pop__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree, int index)
{
}

void __D_I_B_S_T_S_Represent__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree)
{
    if (int_BS_Tree->__Height__ == -1)
    {
        printf(__D_I_B_S_T_S__ERROR_01__);
    }
    else
    {
        printf("\n");
        __Traverse_Represent_Node__(int_BS_Tree->__Root_Node__, "");
        printf("\n");
        for (int i = 0; i < int_BS_Tree->__Height__; i++)
        {
            printf("---");
        }

        printf("\n");
    }
}

void __D_I_B_S_T_S_Delete__(struct Dynamic_Integer_Binary_Search_Tree_Structure *int_BS_Tree)
{
    __Traverse_Delete_Node__(int_BS_Tree->__Root_Node__);
    int_BS_Tree->__Height__ = -1;
}

void __D_I_B_S_T_S_Initialize__(struct Dynamic_Integer_Binary_Search_Tree_Structure *new_int_BS_Tree, int element)
{
    new_int_BS_Tree->__Height__ = 0;
    new_int_BS_Tree->__Root_Node__ = __Create_Node__(NULL, 0, element);

    // Functions Declaration...
    (new_int_BS_Tree->pop) = __D_I_B_S_T_S_Pop__;
    (new_int_BS_Tree->repr) = __D_I_B_S_T_S_Represent__;
    (new_int_BS_Tree->delete) = __D_I_B_S_T_S_Delete__;
    (new_int_BS_Tree->search) = __D_I_B_S_T_S_Search__;
    (new_int_BS_Tree->remove) = __D_I_B_S_T_S_Remove__;
    (new_int_BS_Tree->add) = __D_I_B_S_T_S_Add__;
}

#define int_B_S_Tree_init __D_I_B_S_T_S_Initialize__
#define height __Height__