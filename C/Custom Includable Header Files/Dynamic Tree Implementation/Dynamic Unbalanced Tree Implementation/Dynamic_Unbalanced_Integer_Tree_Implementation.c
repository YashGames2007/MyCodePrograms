#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_U_I_T_S__ERROR_01__ "\n\aUnbalanced Integer Tree :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Unbalanced Integer Tree is Deleted!!!", __FUNCTION__
#define __D_U_I_T_S__ERROR_02__ "\n\aUnbalanced Integer Tree :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Unbalanced Integer Tree Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Unbalanced_Integer_Tree_Structure_Node
{
    int __Node_Data__;
    int __Node_Degree__;
    int __Node_Level__;
    struct Dynamic_Unbalanced_Integer_Tree_Structure_Node *__Parent_Node__;
    struct Dynamic_Unbalanced_Integer_Tree_Structure_Node **__Child_Nodes__;

} D_U_I_T_S_Node;

D_U_I_T_S_Node *__Create_Node__(D_U_I_T_S_Node *parent_Node, int node_Level, int node_Data)
{
    D_U_I_T_S_Node *new_Node = (D_U_I_T_S_Node *)malloc(sizeof(D_U_I_T_S_Node));
    new_Node->__Child_Nodes__ = NULL;
    new_Node->__Node_Data__ = node_Data;
    new_Node->__Node_Degree__ = 0;
    new_Node->__Node_Level__ = node_Level;
    new_Node->__Parent_Node__ = parent_Node;
}

void __Traverse_Represent_Node__(D_U_I_T_S_Node *root_Node, char *string)
{
    printf("\n%s[%d]", string, root_Node->__Node_Data__);
    char new_String[strlen(string) + 3];
    strcpy(new_String, string);
    strcat(new_String, " |");
    printf("\n%s", new_String);

    for (int i = 0; i < root_Node->__Node_Degree__; i++)
    {
        __Traverse_Represent_Node__(root_Node->__Child_Nodes__[i], new_String);
    }
}

void __Traverse_Delete_Node__(D_U_I_T_S_Node *root_Node)
{
    for (int i = 0; i < root_Node->__Node_Degree__; i++)
    {
        __Traverse_Delete_Node__(root_Node->__Child_Nodes__[i]);
    }
    free(root_Node->__Child_Nodes__);
    free(root_Node);
}

void __Traverse_Remove_Node__(D_U_I_T_S_Node *root_Node, int element)
{
    if (root_Node->__Node_Data__ == element)
    {
        if (root_Node->__Parent_Node__->__Node_Degree__ > 1)
        {
            root_Node->__Parent_Node__->__Node_Degree__--;
            int dex = 0;
            D_U_I_T_S_Node *temp[root_Node->__Parent_Node__->__Node_Degree__];

            for (int i = 0; i <= root_Node->__Parent_Node__->__Node_Degree__; i++)
            {
                if (root_Node->__Parent_Node__->__Child_Nodes__[i]->__Node_Data__ != element)
                {
                    temp[dex] = root_Node->__Parent_Node__->__Child_Nodes__[i];
                    dex++;
                }
            }
            
            root_Node->__Parent_Node__->__Child_Nodes__ = (D_U_I_T_S_Node **)realloc(root_Node->__Parent_Node__->__Child_Nodes__, (root_Node->__Parent_Node__->__Node_Degree__ * sizeof(D_U_I_T_S_Node *)));
            for (int i = 0; i < (root_Node->__Parent_Node__->__Node_Degree__); i++)
            {
                root_Node->__Parent_Node__->__Child_Nodes__[i] = temp[i];
            }
        }
        __Traverse_Delete_Node__(root_Node);
    }
    else
    {
        for (int i = 0; i < root_Node->__Node_Degree__; i++)
        {
            __Traverse_Remove_Node__(root_Node->__Child_Nodes__[i], element);
        }
    }
}

int __Traverse_Search_Node__(D_U_I_T_S_Node *root_Node, int element, int *path, int current_Index, int *size)
{
    if (root_Node->__Node_Data__ == element)
    {
        return 1;
    }
    for (int i = 0; i < root_Node->__Node_Degree__; i++)
    {
        if (__Traverse_Search_Node__(root_Node->__Child_Nodes__[i], element, path, (current_Index + 1), size) == 1)
        {
            printf("\nIn: %d", current_Index);
            path[current_Index] = i;
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
# Unbalanced Integer Tree :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Unbalanced Integer Tree in Curly Brackets.
---
### Arguments
#### 1. integer_Tree structure
---
---
## 2. delete
#### Deletes The Whole Unbalanced Integer Tree.
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
#### Returns The Index of First Occurrence of The Element In The Unbalanced Integer Tree, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Unbalanced Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Unbalanced Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Unbalanced Integer Tree.
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
typedef struct Dynamic_Unbalanced_Integer_Tree_Structure
{
    int __Height__;                //#### Maximum Depth of Unbalanced Integer Tree
    D_U_I_T_S_Node *__Root_Node__; //#### Root Node Of Unbalanced Integer Tree

    /*### Represents The Unbalanced Integer Tree in Curly Brackets. */
    void (*repr)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure);
    /*### Deletes The Whole Unbalanced Integer Tree. */
    void (*delete)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure, int index);
    /*### Returns The Index of First Occurrence of The Element In The Unbalanced Integer Tree, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure, int element, int *path);
    /*### Removes The First Occurrence Of The Specified Element in The Unbalanced Integer Tree. */
    void (*remove)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Unbalanced Integer Tree. */
    void (*add)(struct Dynamic_Unbalanced_Integer_Tree_Structure *structure, int *index, int indices, int element);

} integer_Tree;

void __D_U_I_T_S_Add__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree, int *index, int indices, int element)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_U_I_T_S__ERROR_01__);
    }
    else if (indices == 0)
    {
        D_U_I_T_S_Node *new_Node = __Create_Node__(integer_Tree->__Root_Node__, 1, element);

        if (integer_Tree->__Root_Node__->__Node_Degree__ == 0)
        {
            integer_Tree->__Root_Node__->__Child_Nodes__ = (D_U_I_T_S_Node **)malloc(sizeof(D_U_I_T_S_Node *));
            integer_Tree->__Root_Node__->__Child_Nodes__[0] = new_Node;
            integer_Tree->__Height__ = 1;
            integer_Tree->__Root_Node__->__Node_Degree__++;
        }
        else
        {
            D_U_I_T_S_Node *temp[integer_Tree->__Root_Node__->__Node_Degree__];

            for (int i = 0; i < integer_Tree->__Root_Node__->__Node_Degree__; i++)
            {
                temp[i] = integer_Tree->__Root_Node__->__Child_Nodes__[i];
            }
            integer_Tree->__Root_Node__->__Node_Degree__++;
            integer_Tree->__Root_Node__->__Child_Nodes__ = (D_U_I_T_S_Node **)realloc(integer_Tree->__Root_Node__->__Child_Nodes__, integer_Tree->__Root_Node__->__Node_Degree__ * sizeof(D_U_I_T_S_Node *));
            for (int i = 0; (i + 1) < integer_Tree->__Root_Node__->__Node_Degree__; i++)
            {
                integer_Tree->__Root_Node__->__Child_Nodes__[i] = temp[i];
            }
            integer_Tree->__Root_Node__->__Child_Nodes__[integer_Tree->__Root_Node__->__Node_Degree__ - 1] = new_Node;
        }
    }
    else
    {
        if (indices == 1)
        {
            D_U_I_T_S_Node *current_Node = integer_Tree->__Root_Node__->__Child_Nodes__[index[0]];

            D_U_I_T_S_Node *new_Node = __Create_Node__(current_Node, 2, element);

            if (current_Node->__Node_Degree__ == 0)
            {
                current_Node->__Child_Nodes__ = (D_U_I_T_S_Node **)malloc(sizeof(D_U_I_T_S_Node *));
                current_Node->__Child_Nodes__[0] = new_Node;
                if (integer_Tree->__Height__ < 2)
                {
                    integer_Tree->__Height__ = 2;
                }
                current_Node->__Node_Degree__++;
            }
            else
            {
                D_U_I_T_S_Node *temp[current_Node->__Node_Degree__];

                for (int i = 0; i < current_Node->__Node_Degree__; i++)
                {
                    temp[i] = current_Node->__Child_Nodes__[i];
                }
                current_Node->__Node_Degree__++;
                current_Node->__Child_Nodes__ = (D_U_I_T_S_Node **)realloc(current_Node->__Child_Nodes__, (current_Node->__Node_Degree__ * sizeof(D_U_I_T_S_Node *)));
                for (int i = 0; (i + 1) < current_Node->__Node_Degree__; i++)
                {
                    current_Node->__Child_Nodes__[i] = temp[i];
                }
                current_Node->__Child_Nodes__[current_Node->__Node_Degree__ - 1] = new_Node;
            }
        }
        else
        {
            D_U_I_T_S_Node *current_Node = integer_Tree->__Root_Node__;
            for (int i = 0; i < indices; i++)
            {
                current_Node = current_Node->__Child_Nodes__[index[i]];
            }

            D_U_I_T_S_Node *new_Node = __Create_Node__(current_Node, (current_Node->__Node_Level__ + 1), element);

            if (current_Node->__Node_Degree__ == 0)
            {
                current_Node->__Child_Nodes__ = (D_U_I_T_S_Node **)malloc(sizeof(D_U_I_T_S_Node *));
                current_Node->__Child_Nodes__[0] = new_Node;
                if (integer_Tree->__Height__ < 2)
                {
                    integer_Tree->__Height__ = 2;
                }
                current_Node->__Node_Degree__++;
            }
            else
            {
                D_U_I_T_S_Node *temp[current_Node->__Node_Degree__];

                for (int i = 0; i < current_Node->__Node_Degree__; i++)
                {
                    temp[i] = current_Node->__Child_Nodes__[i];
                }
                current_Node->__Node_Degree__++;
                current_Node->__Child_Nodes__ = (D_U_I_T_S_Node **)realloc(current_Node->__Child_Nodes__, (current_Node->__Node_Degree__ * sizeof(D_U_I_T_S_Node *)));
                for (int i = 0; (i + 1) < current_Node->__Node_Degree__; i++)
                {
                    current_Node->__Child_Nodes__[i] = temp[i];
                }
                current_Node->__Child_Nodes__[current_Node->__Node_Degree__ - 1] = new_Node;
            }

            if (integer_Tree->__Height__ < new_Node->__Node_Level__)
            {
                integer_Tree->__Height__ = new_Node->__Node_Level__;
            }
        }
    }
}

void __D_U_I_T_S_Remove__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree, int element)
{
    if (integer_Tree->__Root_Node__->__Node_Data__ == element)
    {
        integer_Tree->delete(integer_Tree);
        return;
    }
    __Traverse_Remove_Node__(integer_Tree->__Root_Node__, element);
}

int __D_U_I_T_S_Search__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree, int element, int *path)
{
    if (integer_Tree->__Root_Node__->__Node_Data__ == element)
    {
        return 0;
    }
    int size = 0;
    __Traverse_Search_Node__(integer_Tree->__Root_Node__, element, path, 0, &size);
    printf("\nSize: %d", *(&(size)));
    return size;
}

int __D_U_I_T_S_Pop__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree, int index)
{
}

void __D_U_I_T_S_Represent__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_U_I_T_S__ERROR_01__);
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

void __D_U_I_T_S_Delete__(struct Dynamic_Unbalanced_Integer_Tree_Structure *integer_Tree)
{
    __Traverse_Delete_Node__(integer_Tree->__Root_Node__);
    integer_Tree->__Height__ = -1;
}

void __D_U_I_T_S_Initialize__(integer_Tree *new_integer_Tree, int element)
{
    new_integer_Tree->__Height__ = 0;
    new_integer_Tree->__Root_Node__ = __Create_Node__(NULL, 0, element);

    // Functions Declaration...
    (new_integer_Tree->pop) = __D_U_I_T_S_Pop__;
    (new_integer_Tree->repr) = __D_U_I_T_S_Represent__;
    (new_integer_Tree->delete) = __D_U_I_T_S_Delete__;
    (new_integer_Tree->search) = __D_U_I_T_S_Search__;
    (new_integer_Tree->remove) = __D_U_I_T_S_Remove__;
    (new_integer_Tree->add) = __D_U_I_T_S_Add__;
}

#define integer_Tree_init __D_U_I_T_S_Initialize__
#define height __Height__