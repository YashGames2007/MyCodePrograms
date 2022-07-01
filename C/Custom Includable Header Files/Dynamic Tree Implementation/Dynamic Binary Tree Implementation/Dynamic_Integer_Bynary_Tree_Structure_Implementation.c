#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_B_I_T_S__ERROR_01__ "\n\aBinary Integer Tree :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Binary Integer Tree is Deleted!!!", __FUNCTION__
#define __D_B_I_T_S__ERROR_02__ "\n\aBinary Integer Tree :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Binary Integer Tree Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Binary_Integer_Tree_Structure_Node
{
    int __Node_Data__;
    int __Node_Level__;
    struct Dynamic_Binary_Integer_Tree_Structure_Node *__Parent_Node__;
    struct Dynamic_Binary_Integer_Tree_Structure_Node *__Left_Child_Node__;
    struct Dynamic_Binary_Integer_Tree_Structure_Node *__Right_Child_Node__;

} D_B_I_T_S_Node;

D_B_I_T_S_Node *__Create_Node__(D_B_I_T_S_Node *parent_Node, int node_Level, int node_Data)
{
    D_B_I_T_S_Node *new_Node = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
    new_Node->__Left_Child_Node__ = NULL;
    new_Node->__Right_Child_Node__ = NULL;
    new_Node->__Node_Data__ = node_Data;
    new_Node->__Node_Level__ = node_Level;
    new_Node->__Parent_Node__ = parent_Node;
}

void __Traverse_Represent_Node__(D_B_I_T_S_Node *root_Node, char *string)
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

void __Traverse_Delete_Node__(D_B_I_T_S_Node *root_Node)
{
    if (root_Node != NULL)
    {
        __Traverse_Delete_Node__(root_Node->__Left_Child_Node__);
        __Traverse_Delete_Node__(root_Node->__Right_Child_Node__);
        free(root_Node);
    }
}

void __Traverse_Remove_Node__(D_B_I_T_S_Node *root_Node, int element)
{
    if (root_Node != NULL)
    {
        if (root_Node->__Node_Data__ == element)
        {
            if (root_Node->__Parent_Node__->__Left_Child_Node__ == root_Node)
            {
                root_Node->__Parent_Node__->__Left_Child_Node__ = NULL;
            }
            else
            {
                root_Node->__Parent_Node__->__Right_Child_Node__ = NULL;
            }
            __Traverse_Delete_Node__(root_Node);
        }
        else
        {
            __Traverse_Remove_Node__(root_Node->__Left_Child_Node__, element);
            __Traverse_Remove_Node__(root_Node->__Right_Child_Node__, element);
        }
    }
}

int __Traverse_Search_Node__(D_B_I_T_S_Node *root_Node, int element, int *path, int current_Index, int *size)
{
    if (root_Node == NULL)
    {
        return 0;
    }
    if (root_Node->__Node_Data__ == element)
    {
        return 1;
    }
    if (__Traverse_Search_Node__(root_Node->__Left_Child_Node__, element, path, (current_Index + 1), size) == 1)
    {
        path[current_Index] = 0;
        *size += 1;
        return 1;
    }
    if (__Traverse_Search_Node__(root_Node->__Right_Child_Node__, element, path, (current_Index + 1), size) == 1)
    {
        path[current_Index] = 1;
        *size += 1;
        return 1;
    }
    return 0;
}

int __Traverse_Check_Node__(D_B_I_T_S_Node *root_Node)
{
    static D_B_I_T_S_Node *previous_Node = NULL;

    if (root_Node != NULL)
    {
        if (__Traverse_Check_Node__(root_Node->__Left_Child_Node__) == 0)
        {
            return 0;
        }
        if (previous_Node != NULL && root_Node->__Node_Data__ <= previous_Node->__Node_Data__)
        {
            return 0;
        }
        previous_Node = root_Node;
        return __Traverse_Check_Node__(root_Node->__Right_Child_Node__);
    }
    return 1;
}

/*
---
---
---
# Binary Integer Tree :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Binary Integer Tree in Curly Brackets.
---
### Arguments
#### 1. integer_Tree structure
---
---
## 2. delete
#### Deletes The Whole Binary Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Binary Integer Tree, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Binary Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Binary Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Binary Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Binary_Integer_Tree_Structure
{
    int __Height__;                //#### Maximum Depth of Binary Integer Tree
    D_B_I_T_S_Node *__Root_Node__; //#### Root Node Of Binary Integer Tree

    /*### Represents The Binary Integer Tree in Curly Brackets. */
    void (*repr)(struct Dynamic_Binary_Integer_Tree_Structure *structure);
    /*### Deletes The Whole Binary Integer Tree. */
    void (*delete)(struct Dynamic_Binary_Integer_Tree_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Binary_Integer_Tree_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Binary Integer Tree, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Binary_Integer_Tree_Structure *structure, int element, int *path);
    /*### Removes The First Occurrence Of The Specified Element in The Binary Integer Tree. */
    void (*remove)(struct Dynamic_Binary_Integer_Tree_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Binary Integer Tree. */
    void (*add)(struct Dynamic_Binary_Integer_Tree_Structure *structure, int *index, int indices, int element);
    /*### Checks if The Binary Tree is Binary Search Tree or Not.*/
    int (*is_BST)(struct Dynamic_Binary_Integer_Tree_Structure *structure);

} int_Binary_Tree;

void __D_B_I_T_S_Add__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree, int *index, int indices, int element)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_B_I_T_S__ERROR_01__);
    }
    else if (indices == 0)
    {
        D_B_I_T_S_Node *new_Node = __Create_Node__(integer_Tree->__Root_Node__, 1, element);

        if (integer_Tree->__Root_Node__->__Left_Child_Node__ == NULL)
        {
            integer_Tree->__Root_Node__->__Left_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
            integer_Tree->__Root_Node__->__Left_Child_Node__ = new_Node;
            integer_Tree->__Height__ = 1;
        }
        else if (integer_Tree->__Root_Node__->__Right_Child_Node__ == NULL)
        {
            integer_Tree->__Root_Node__->__Right_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
            integer_Tree->__Root_Node__->__Right_Child_Node__ = new_Node;
            integer_Tree->__Height__ = 1;
        }
    }
    else
    {
        if (indices == 1)
        {
            D_B_I_T_S_Node *current_Node = NULL;
            if (index[0] == 0)
            {
                current_Node = integer_Tree->__Root_Node__->__Left_Child_Node__;
            }
            else
            {
                current_Node = integer_Tree->__Root_Node__->__Right_Child_Node__;
            }
            D_B_I_T_S_Node *new_Node = __Create_Node__(current_Node, 2, element);

            if (current_Node->__Left_Child_Node__ == NULL)
            {
                current_Node->__Left_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
                current_Node->__Left_Child_Node__ = new_Node;
                if (integer_Tree->__Height__ < 2)
                {
                    integer_Tree->__Height__ = 2;
                }
            }
            else if (current_Node->__Right_Child_Node__ == NULL)
            {
                current_Node->__Right_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
                current_Node->__Right_Child_Node__ = new_Node;
                if (integer_Tree->__Height__ < 2)
                {
                    integer_Tree->__Height__ = 2;
                }
            }
        }
        else
        {
            D_B_I_T_S_Node *current_Node = integer_Tree->__Root_Node__;
            for (int i = 0; i < indices; i++)
            {
                if (index[i] == 0)
                {
                    current_Node = current_Node->__Left_Child_Node__;
                }
                else
                {
                    current_Node = current_Node->__Right_Child_Node__;
                }
            }

            D_B_I_T_S_Node *new_Node = __Create_Node__(current_Node, (current_Node->__Node_Level__ + 1), element);

            if (current_Node->__Left_Child_Node__ == NULL)
            {
                current_Node->__Left_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
                current_Node->__Left_Child_Node__ = new_Node;
            }
            else if (current_Node->__Right_Child_Node__ == NULL)
            {
                current_Node->__Right_Child_Node__ = (D_B_I_T_S_Node *)malloc(sizeof(D_B_I_T_S_Node));
                current_Node->__Right_Child_Node__ = new_Node;
            }
            if (integer_Tree->__Height__ < new_Node->__Node_Level__)
            {
                integer_Tree->__Height__ = new_Node->__Node_Level__;
            }
        }
    }
}

int __D_B_I_T_S_Is_BST__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree)
{
    return __Traverse_Check_Node__(integer_Tree->__Root_Node__);
}

void __D_B_I_T_S_Remove__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree, int element)
{
    if (integer_Tree->__Root_Node__->__Node_Data__ == element)
    {
        integer_Tree->delete (integer_Tree);
        return;
    }
    __Traverse_Remove_Node__(integer_Tree->__Root_Node__, element);
}

int __D_B_I_T_S_Search__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree, int element, int *path)
{
    if (integer_Tree->__Root_Node__->__Node_Data__ == element)
    {
        return 0;
    }
    int size = 0;
    __Traverse_Search_Node__(integer_Tree->__Root_Node__, element, path, 0, &size);
    return size;
}

int __D_B_I_T_S_Pop__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree, int index)
{
}

void __D_B_I_T_S_Represent__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_B_I_T_S__ERROR_01__);
    }
    else
    {
        printf("\n");
        __Traverse_Represent_Node__(integer_Tree->__Root_Node__, "");
        printf("\n");
        for (int i = 0; i < integer_Tree->__Height__; i++)
        {
            printf("---");
        }

        printf("\n");
    }
}

void __D_B_I_T_S_Delete__(struct Dynamic_Binary_Integer_Tree_Structure *integer_Tree)
{
    __Traverse_Delete_Node__(integer_Tree->__Root_Node__);
    integer_Tree->__Height__ = -1;
}

void __D_B_I_T_S_Initialize__(struct Dynamic_Binary_Integer_Tree_Structure *new_integer_Tree, int element)
{
    new_integer_Tree->__Height__ = 0;
    new_integer_Tree->__Root_Node__ = __Create_Node__(NULL, 0, element);

    // Functions Declaration...
    (new_integer_Tree->pop) = __D_B_I_T_S_Pop__;
    (new_integer_Tree->repr) = __D_B_I_T_S_Represent__;
    (new_integer_Tree->delete) = __D_B_I_T_S_Delete__;
    (new_integer_Tree->search) = __D_B_I_T_S_Search__;
    (new_integer_Tree->remove) = __D_B_I_T_S_Remove__;
    (new_integer_Tree->add) = __D_B_I_T_S_Add__;
    (new_integer_Tree->is_BST) = __D_B_I_T_S_Is_BST__;
}

#define int_Binary_Tree_init __D_B_I_T_S_Initialize__
#define height __Height__