#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_I_AVL_T_S__ERROR_01__ "\n\aInteger AVL Tree :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Integer AVL Tree is Deleted!!!", __FUNCTION__
#define __D_I_AVL_T_S__ERROR_02__ "\n\aInteger AVL Tree :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Integer AVL Tree Index Out of Range!!!", __FUNCTION__

int maximum(int _A, int _B)
{
    if (_A > _B)
    {
        return _A;
    }
    return _B;
}

typedef struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure_Node
{
    int __Node_Data__;
    int __Node_Level__;
    int __Node_Height__;
    struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure_Node *__Parent_Node__;
    struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure_Node *__Left_Child_Node__;
    struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure_Node *__Right_Child_Node__;

} D_I_AVL_T_S_Node;

int __Node_Balance_Factor__(D_I_AVL_T_S_Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else if (node->__Left_Child_Node__ == NULL && node->__Right_Child_Node__ == NULL)
    {
        return 0;
    }
    else if (node->__Left_Child_Node__ == NULL)
    {
        return node->__Right_Child_Node__->__Node_Height__ + 1;
    }
    else if (node->__Right_Child_Node__ == NULL)
    {
        return node->__Left_Child_Node__->__Node_Height__ + 1;
    }
    else
    {
        return abs(node->__Left_Child_Node__->__Node_Height__ - node->__Right_Child_Node__->__Node_Height__);
    }
}

int __Node_Parameters_Update__(D_I_AVL_T_S_Node *node, int node_Level)
{
    if (node == NULL)
    {
        return 0;
    }
    node->__Node_Level__ = node_Level;
    
    if (node->__Left_Child_Node__ == NULL && node->__Right_Child_Node__ == NULL)
    {
        node->__Node_Height__ = 1;
    }
    else
    {
        node->__Node_Height__ = maximum(__Node_Parameters_Update__(node->__Left_Child_Node__, node_Level + 1), __Node_Parameters_Update__(node->__Right_Child_Node__, node_Level + 1)) + 1;
    }
    return node->__Node_Height__;
}

D_I_AVL_T_S_Node *__Create_Node__(D_I_AVL_T_S_Node *parent_Node, int node_Level, int node_Data)
{
    D_I_AVL_T_S_Node *new_Node = (D_I_AVL_T_S_Node *)malloc(sizeof(D_I_AVL_T_S_Node));
    new_Node->__Left_Child_Node__ = NULL;
    new_Node->__Right_Child_Node__ = NULL;
    new_Node->__Node_Data__ = node_Data;
    new_Node->__Node_Level__ = node_Level;
    new_Node->__Node_Height__ = 0;
    new_Node->__Parent_Node__ = parent_Node;
}

D_I_AVL_T_S_Node *__Traverse_InOrder_Predecessor__(D_I_AVL_T_S_Node *root_Node)
{
    root_Node = root_Node->__Left_Child_Node__;
    while (root_Node->__Right_Child_Node__ != NULL)
    {
        root_Node = root_Node->__Right_Child_Node__;
    }
    return root_Node;
}

D_I_AVL_T_S_Node *__Traverse_Remove_Node__(D_I_AVL_T_S_Node *root_Node, int element)
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
        // root_Node->__Left_Child_Node__->__Parent_Node__ = root_Node;
    }
    else if (element > root_Node->__Node_Data__)
    {
        root_Node->__Right_Child_Node__ = __Traverse_Remove_Node__(root_Node->__Right_Child_Node__, element);
        // root_Node->__Right_Child_Node__->__Parent_Node__ = root_Node;
    }
    else
    {
        D_I_AVL_T_S_Node *inOrder_Predecessor = __Traverse_InOrder_Predecessor__(root_Node);
        root_Node->__Node_Data__ = inOrder_Predecessor->__Node_Data__;
        root_Node->__Left_Child_Node__ = __Traverse_Remove_Node__(root_Node->__Left_Child_Node__, inOrder_Predecessor->__Node_Data__);
        // root_Node->__Left_Child_Node__->__Parent_Node__ = root_Node;
    }
    return root_Node;
}

void __Node_Clock_Wise_Rotation__(D_I_AVL_T_S_Node *root_Node)
{
    printf("\nCW");
    if (root_Node->__Parent_Node__ == NULL)
    {
        D_I_AVL_T_S_Node *left_Node = root_Node->__Left_Child_Node__;
        if (left_Node != NULL)
        {
            root_Node->__Left_Child_Node__->__Parent_Node__ = NULL;
            root_Node->__Left_Child_Node__ = root_Node->__Left_Child_Node__->__Right_Child_Node__;
            if (left_Node->__Right_Child_Node__ != NULL)
            {
                left_Node->__Right_Child_Node__->__Parent_Node__ = root_Node;
            }
            left_Node->__Right_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = left_Node;
    }
    else if (root_Node->__Parent_Node__->__Left_Child_Node__ == root_Node)
    {
        root_Node->__Parent_Node__->__Left_Child_Node__ = root_Node->__Left_Child_Node__;
        if (root_Node->__Left_Child_Node__ != NULL)
        {
            root_Node->__Left_Child_Node__->__Parent_Node__ = root_Node->__Parent_Node__;
            root_Node->__Left_Child_Node__ = root_Node->__Left_Child_Node__->__Right_Child_Node__;
            if (root_Node->__Parent_Node__->__Left_Child_Node__->__Right_Child_Node__ != NULL)
            {
                root_Node->__Parent_Node__->__Left_Child_Node__->__Right_Child_Node__->__Parent_Node__ = root_Node;
            }
            root_Node->__Parent_Node__->__Left_Child_Node__->__Right_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = root_Node->__Parent_Node__->__Left_Child_Node__;
    }
    else
    {
        root_Node->__Parent_Node__->__Right_Child_Node__ = root_Node->__Left_Child_Node__;
        if (root_Node->__Left_Child_Node__ != NULL)
        {
            root_Node->__Left_Child_Node__->__Parent_Node__ = root_Node->__Parent_Node__;
            root_Node->__Left_Child_Node__ = root_Node->__Left_Child_Node__->__Right_Child_Node__;
            if (root_Node->__Parent_Node__->__Right_Child_Node__->__Right_Child_Node__ != NULL)
            {
                root_Node->__Parent_Node__->__Right_Child_Node__->__Right_Child_Node__->__Parent_Node__ = root_Node;
            }
            root_Node->__Parent_Node__->__Right_Child_Node__->__Right_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = root_Node->__Parent_Node__->__Right_Child_Node__;
    }
}

void __Node_Anti_Clock_Wise_Rotation__(D_I_AVL_T_S_Node *root_Node)
{
    printf("\nACW");
    if (root_Node->__Parent_Node__ == NULL)
    {
        printf("\nIf - AC");
        D_I_AVL_T_S_Node *right_Node = root_Node->__Right_Child_Node__;
        if (root_Node->__Right_Child_Node__ != NULL)
        {
            root_Node->__Right_Child_Node__->__Parent_Node__ = NULL;
            root_Node->__Right_Child_Node__ = root_Node->__Right_Child_Node__->__Left_Child_Node__;
            if (right_Node->__Left_Child_Node__ != NULL)
            {
                right_Node->__Left_Child_Node__->__Parent_Node__ = root_Node;
            }
            right_Node->__Left_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = right_Node;
    }
    else if (root_Node->__Parent_Node__->__Left_Child_Node__ == root_Node)
    {
        printf("\nElif - AC");
        root_Node->__Parent_Node__->__Left_Child_Node__ = root_Node->__Right_Child_Node__;
        if (root_Node->__Right_Child_Node__ != NULL)
        {
            root_Node->__Right_Child_Node__->__Parent_Node__ = root_Node->__Parent_Node__;
            root_Node->__Right_Child_Node__ = root_Node->__Right_Child_Node__->__Left_Child_Node__;
            if (root_Node->__Right_Child_Node__ != NULL)
            {
                root_Node->__Right_Child_Node__->__Parent_Node__ = root_Node;
            }
            root_Node->__Parent_Node__->__Left_Child_Node__->__Left_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = root_Node->__Parent_Node__->__Left_Child_Node__;
    }
    else
    {
        printf("\nElse - AC");
        root_Node->__Parent_Node__->__Right_Child_Node__ = root_Node->__Right_Child_Node__;
        if (root_Node->__Right_Child_Node__ != NULL)
        {
            root_Node->__Right_Child_Node__->__Parent_Node__ = root_Node->__Parent_Node__;
            root_Node->__Right_Child_Node__ = root_Node->__Right_Child_Node__->__Left_Child_Node__;
            if (root_Node->__Right_Child_Node__ != NULL)
            {
                root_Node->__Right_Child_Node__->__Parent_Node__ = root_Node;
            }
            root_Node->__Parent_Node__->__Right_Child_Node__->__Left_Child_Node__ = root_Node;
        }
        root_Node->__Parent_Node__ = root_Node->__Parent_Node__->__Right_Child_Node__;
    }
}

void __Traverse_Represent_Node__(D_I_AVL_T_S_Node *root_Node, char *string)
{
    if (root_Node != NULL)
    {
        printf("\n%s-F%d-H%d-L%d-[%d]", string, __Node_Balance_Factor__(root_Node), root_Node->__Node_Height__, root_Node->__Node_Level__, root_Node->__Node_Data__);
        char new_String[strlen(string) + 3];
        strcpy(new_String, string);
        strcat(new_String, " |");
        printf("\n%s", new_String);

        __Traverse_Represent_Node__(root_Node->__Left_Child_Node__, new_String);
        __Traverse_Represent_Node__(root_Node->__Right_Child_Node__, new_String);
    }
}

void __Traverse_Delete_Node__(D_I_AVL_T_S_Node *root_Node)
{
    if (root_Node != NULL)
    {
        __Traverse_Delete_Node__(root_Node->__Left_Child_Node__);
        __Traverse_Delete_Node__(root_Node->__Right_Child_Node__);
        free(root_Node);
    }
}

int __Traverse_Search_Node__(D_I_AVL_T_S_Node *root_Node, int element, int *path, int current_Index, int *size)
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
            (*size) += 1;
            return 1;
        }
    }
    else
    {
        if (__Traverse_Search_Node__(root_Node->__Right_Child_Node__, element, path, (current_Index + 1), size) == 1)
        {
            path[current_Index] = 1;
            (*size) += 1;
            return 1;
        }
    }
    return 0;
}

void __Node_Rotation__(D_I_AVL_T_S_Node *inserted_Node)
{
    int rotation_1 = 1, rotation_2 = 1, rotation_Temp = 1;
    D_I_AVL_T_S_Node *node = inserted_Node;
    while (node->__Parent_Node__ != NULL)
    {
        printf("\nwhile");

        rotation_2 = rotation_1;
        rotation_1 = rotation_Temp;
        if (node->__Parent_Node__->__Left_Child_Node__ == node)
        {
            rotation_Temp = 1;
            printf("\n1 : %d", inserted_Node->__Node_Data__);
        }
        else
        {
            rotation_Temp = 2;
            printf("\n2 : %d", inserted_Node->__Node_Data__);
        }
        printf("\nOk");
        if (__Node_Balance_Factor__(node) >= 2)
        {
            printf("\nR1: %d, R2: %d, Ins: %d, Curr: %d", rotation_1, rotation_2, inserted_Node->__Node_Data__, node->__Node_Data__);
            if (rotation_1 == 1 && rotation_2 == 1)
            {
                __Node_Clock_Wise_Rotation__(node);
            }
            else if (rotation_1 == 2 && rotation_2 == 2)
            {
                __Node_Anti_Clock_Wise_Rotation__(node);
            }
            else if (rotation_1 == 1 && rotation_2 == 2)
            {
                __Node_Anti_Clock_Wise_Rotation__(node->__Left_Child_Node__);
                __Node_Clock_Wise_Rotation__(node);
            }
            else if (rotation_1 == 2 && rotation_2 == 1)
            {
                __Node_Clock_Wise_Rotation__(node->__Right_Child_Node__);
                __Node_Anti_Clock_Wise_Rotation__(node);
            }
            break;
        }
        node = node->__Parent_Node__;
    }
}

/*
---
---
---
# Integer AVL Tree :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Integer AVL Tree in Curly Brackets.
---
### Arguments
#### 1. int_avl_Tree structure
---
---
## 2. delete
#### Deletes The Whole Integer AVL Tree.
---
### Arguments
#### 1. int_avl_Tree structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_avl_Tree structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Integer AVL Tree, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_avl_Tree structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Integer AVL Tree.
---
### Arguments
#### 1. int_avl_Tree structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Integer AVL Tree.
---
### Arguments
#### 1. int_avl_Tree structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Integer AVL Tree.
---
### Arguments
#### 1. int_avl_Tree structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure
{
    int __Height__;                  //#### Maximum Depth of Integer AVL Tree
    D_I_AVL_T_S_Node *__Root_Node__; //#### Root Node Of Integer AVL Tree

    /*### Represents The Integer AVL Tree in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure);
    /*### Deletes The Whole Integer AVL Tree. */
    void (*delete)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Integer AVL Tree, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure, int element, int *path);
    /*### Removes The First Occurrence Of The Specified Element in The Integer AVL Tree. */
    void (*remove)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Integer AVL Tree. */
    void (*add)(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *structure, int element);

} int_AVL_Tree;

void __D_I_AVL_T_S_Add__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree, int element)
{
    D_I_AVL_T_S_Node *previous_Node = NULL;
    D_I_AVL_T_S_Node *root_Node = int_avl_Tree->__Root_Node__;

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

    D_I_AVL_T_S_Node *new_Node = __Create_Node__(previous_Node, (previous_Node->__Node_Level__ + 1), element);

    if (previous_Node->__Node_Data__ > element)
    {
        previous_Node->__Left_Child_Node__ = new_Node;
    }
    else
    {
        previous_Node->__Right_Child_Node__ = new_Node;
    }
    D_I_AVL_T_S_Node *temp;
    // D_I_AVL_T_S_Node *current_Node = new_Node->__Parent_Node__;
    // while (current_Node != NULL)
    // {
    //     if (current_Node->__Node_Height__ < (new_Node->__Node_Level__ - current_Node->__Node_Level__))
    //     {
    //         current_Node->__Node_Height__ = new_Node->__Node_Level__ - current_Node->__Node_Level__;
    //     }
    //     current_Node = current_Node->__Parent_Node__;
    // }
    // int_avl_Tree->__Height__ = int_avl_Tree->__Root_Node__->__Node_Height__;
    printf("\nHeight1");
    int_avl_Tree->__Height__ = __Node_Parameters_Update__(int_avl_Tree->__Root_Node__, 0);
    printf("\nRotation");
    __Node_Rotation__(new_Node);
    printf("\nHeight2");
    int_avl_Tree->__Height__ = __Node_Parameters_Update__(int_avl_Tree->__Root_Node__, 0);
}

void __D_I_AVL_T_S_Remove__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree, int element)
{
    D_I_AVL_T_S_Node *node = __Traverse_Remove_Node__(int_avl_Tree->__Root_Node__, element);
    // if (node != NULL && node->__Parent_Node__ != NULL)
    // {
    //     printf("\nData: %d", node->__Parent_Node__->__Node_Data__);
    // }
}

int __D_I_AVL_T_S_Search__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree, int element, int *path)
{
    printf("\nHeight: %d", int_avl_Tree->__Height__);
    int size = 0;
    printf("\nHeight: %d", int_avl_Tree->__Height__);
    printf("\nAdd: %x", &int_avl_Tree->__Height__);
    printf("\nAdd: %x", path);
    path[0] = -1;
    __Traverse_Search_Node__(int_avl_Tree->__Root_Node__, element, path, 0, &size);
    printf("\nHeight: %d", int_avl_Tree->__Height__);
    return size;
}

int __D_I_AVL_T_S_Pop__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree, int index)
{
}

void __D_I_AVL_T_S_Represent__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree)
{
    if (int_avl_Tree->__Height__ == -1)
    {
        printf(__D_I_AVL_T_S__ERROR_01__);
    }
    else
    {
        printf("\n");
        __Traverse_Represent_Node__(int_avl_Tree->__Root_Node__, "");
        printf("\n");
        for (int i = 0; i < int_avl_Tree->__Height__; i++)
        {
            printf("---");
        }

        printf("\n");
    }
}

void __D_I_AVL_T_S_Delete__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *int_avl_Tree)
{
    __Traverse_Delete_Node__(int_avl_Tree->__Root_Node__);
    int_avl_Tree->__Height__ = -1;
}

void __D_I_AVL_T_S_Initialize__(struct Dynamic_Integer_Adelson_Velskii_and_Landis_Tree_Structure *new_int_avl_Tree, int element)
{
    new_int_avl_Tree->__Height__ = 0;
    new_int_avl_Tree->__Root_Node__ = __Create_Node__(NULL, 0, element);

    // Functions Declaration...
    (new_int_avl_Tree->pop) = __D_I_AVL_T_S_Pop__;
    (new_int_avl_Tree->repr) = __D_I_AVL_T_S_Represent__;
    (new_int_avl_Tree->delete) = __D_I_AVL_T_S_Delete__;
    (new_int_avl_Tree->search) = __D_I_AVL_T_S_Search__;
    (new_int_avl_Tree->remove) = __D_I_AVL_T_S_Remove__;
    (new_int_avl_Tree->add) = __D_I_AVL_T_S_Add__;
}

#define int_AVL_Tree_init __D_I_AVL_T_S_Initialize__
#define height __Height__