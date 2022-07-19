#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Some Error Massages
#define __D_E_U_I_T_S__ERROR_01__ "\n\aEdged Unbalanced Integer Tree :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Edged Unbalanced Integer Tree is Deleted!!!", __FUNCTION__
#define __D_E_U_I_T_S__ERROR_02__ "\n\aEdged Unbalanced Integer Tree :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Edged Unbalanced Integer Tree Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Edge
{
    int __Edge_Cost__;
    struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Node *__Node_Connection_In__;
    struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Node *__Node_Connection_Out__;
} D_E_U_I_T_S_Edge;

typedef struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Node
{
    int __Node_Data__;
    int __Node_Degree__;
    int __Node_Level__;
    struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Edge *__Parent_Node_Edge__;
    struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure_Edge **__Child_Node_Edges_;

} D_E_U_I_T_S_Node;

D_E_U_I_T_S_Node *__Create_Node__(D_E_U_I_T_S_Node *parent_Node, int node_Level, int node_Data, int edge_Cost)
{
    D_E_U_I_T_S_Node *new_Node = (D_E_U_I_T_S_Node *)malloc(sizeof(D_E_U_I_T_S_Node));
    new_Node->__Child_Node_Edges_ = NULL;
    new_Node->__Node_Data__ = node_Data;
    new_Node->__Node_Degree__ = 0;
    new_Node->__Node_Level__ = node_Level;

    if (parent_Node != NULL)
    {
        D_E_U_I_T_S_Edge *new_Edge = (D_E_U_I_T_S_Edge *)malloc(sizeof(D_E_U_I_T_S_Edge));
        new_Edge->__Edge_Cost__ = edge_Cost;
        new_Edge->__Node_Connection_Out__ = new_Node;
        new_Node->__Parent_Node_Edge__ = new_Edge;
    }
    else
    {
        new_Node->__Parent_Node_Edge__ = NULL;
    }

    return new_Node;
}

void __Traverse_Represent_Node__(D_E_U_I_T_S_Node *root_Node, char *string)
{
    if (root_Node->__Parent_Node_Edge__ != NULL)
    {
        printf("\n%s-[%d]-<%d>", string, root_Node->__Node_Data__, root_Node->__Parent_Node_Edge__->__Edge_Cost__);
    }
    else
    {
        printf("\n%s[%d]", string, root_Node->__Node_Data__);
    }
    char new_String[strlen(string) + 3];
    strcpy(new_String, string);
    strcat(new_String, " |");
    printf("\n%s", new_String);

    for (int i = 0; i < root_Node->__Node_Degree__; i++)
    {
        __Traverse_Represent_Node__(root_Node->__Child_Node_Edges_[i]->__Node_Connection_Out__, new_String);
    }
}

/*
---
---
---
# Edged Unbalanced Integer Tree :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Edged Unbalanced Integer Tree in Curly Brackets.
---
### Arguments
#### 1. integer_Tree structure
---
---
## 2. delete
#### Deletes The Whole Edged Unbalanced Integer Tree.
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
#### Returns The Index of First Occurrence of The Element In The Edged Unbalanced Integer Tree, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 5. append
#### Appends The Element At The End Of The Edged Unbalanced Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Edged Unbalanced Integer Tree.
---
### Arguments
#### 1. integer_Tree structure
#### 2. int element
---
---
## 7. insert
#### Inserts The Element At Specified Index In The Edged Unbalanced Integer Tree.
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
typedef struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure
{
    int __Height__;                //#### Maximum Depth of Edged Unbalanced Integer Tree
    D_E_U_I_T_S_Node *__Root_Node__; //#### Root Node Of Edged Unbalanced Integer Tree

    /*### Represents The Edged Unbalanced Integer Tree in Curly Brackets. */
    void (*repr)(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *structure);
    /*### Deletes The Whole Edged Unbalanced Integer Tree. */
    void (*delete)(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *structure);
    /*### Returns The Index of First Occurrence of The Element In The Edged Unbalanced Integer Tree, Returns -1 If The Element is Not Present In The List. */
    int (*search)(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *structure, int element, int *path);
    /*### Removes The First Occurrence Of The Specified Element in The Edged Unbalanced Integer Tree. */
    void (*remove)(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *structure, int element);
    /*### Inserts The Element At Specified Index In The Edged Unbalanced Integer Tree. */
    void (*add)(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *structure, int *index, int indices, int element, int edge_Cost);

} int_E_U_Tree;

void __D_E_U_I_T_S_Add__(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *integer_Tree, int *index, int indices, int element, int edge_cost)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_E_U_I_T_S__ERROR_01__);
    }
    else if (indices == 0)
    {
        D_E_U_I_T_S_Node *new_Node = __Create_Node__(integer_Tree->__Root_Node__, 1, element, edge_cost);

        if (integer_Tree->__Root_Node__->__Node_Degree__ == 0)
        {
            integer_Tree->__Root_Node__->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)malloc(sizeof(D_E_U_I_T_S_Edge *));
            integer_Tree->__Root_Node__->__Child_Node_Edges_[0] = new_Node->__Parent_Node_Edge__;
            integer_Tree->__Height__ = 1;
            integer_Tree->__Root_Node__->__Node_Degree__++;
            new_Node->__Parent_Node_Edge__->__Node_Connection_In__ = integer_Tree->__Root_Node__;
        }
        else
        {
            D_E_U_I_T_S_Edge *temp[integer_Tree->__Root_Node__->__Node_Degree__];

            for (int i = 0; i < integer_Tree->__Root_Node__->__Node_Degree__; i++)
            {
                temp[i] = integer_Tree->__Root_Node__->__Child_Node_Edges_[i];
            }
            integer_Tree->__Root_Node__->__Node_Degree__++;
            integer_Tree->__Root_Node__->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)realloc(integer_Tree->__Root_Node__->__Child_Node_Edges_, integer_Tree->__Root_Node__->__Node_Degree__ * sizeof(D_E_U_I_T_S_Edge *));
            for (int i = 0; (i + 1) < integer_Tree->__Root_Node__->__Node_Degree__; i++)
            {
                integer_Tree->__Root_Node__->__Child_Node_Edges_[i] = temp[i];
            }
            integer_Tree->__Root_Node__->__Child_Node_Edges_[integer_Tree->__Root_Node__->__Node_Degree__ - 1] = new_Node->__Parent_Node_Edge__;
            new_Node->__Parent_Node_Edge__->__Node_Connection_In__ = integer_Tree->__Root_Node__;
        }
    }
    else
    {
        if (indices == 1)
        {
            D_E_U_I_T_S_Node *current_Node = integer_Tree->__Root_Node__->__Child_Node_Edges_[index[0]]->__Node_Connection_Out__;

            D_E_U_I_T_S_Node *new_Node = __Create_Node__(current_Node, 2, element, edge_cost);

            if (current_Node->__Node_Degree__ == 0)
            {
                current_Node->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)malloc(sizeof(D_E_U_I_T_S_Edge *));
                current_Node->__Child_Node_Edges_[0] = new_Node->__Parent_Node_Edge__;
                if (integer_Tree->__Height__ < 2)
                {
                    integer_Tree->__Height__ = 2;
                }
                current_Node->__Node_Degree__++;
            }
            else
            {
                D_E_U_I_T_S_Edge *temp[current_Node->__Node_Degree__];

                for (int i = 0; i < current_Node->__Node_Degree__; i++)
                {
                    temp[i] = current_Node->__Child_Node_Edges_[i];
                }
                current_Node->__Node_Degree__++;
                current_Node->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)realloc(current_Node->__Child_Node_Edges_, (current_Node->__Node_Degree__ * sizeof(D_E_U_I_T_S_Edge *)));
                for (int i = 0; (i + 1) < current_Node->__Node_Degree__; i++)
                {
                    current_Node->__Child_Node_Edges_[i] = temp[i];
                }
                current_Node->__Child_Node_Edges_[current_Node->__Node_Degree__ - 1] = new_Node->__Parent_Node_Edge__;
                new_Node->__Parent_Node_Edge__->__Node_Connection_In__ = current_Node;
            }
        }
        else
        {
            D_E_U_I_T_S_Node *current_Node = integer_Tree->__Root_Node__;
            for (int i = 0; i < indices; i++)
            {
                current_Node = current_Node->__Child_Node_Edges_[index[i]]->__Node_Connection_Out__;
            }

            D_E_U_I_T_S_Node *new_Node = __Create_Node__(current_Node, (current_Node->__Node_Level__ + 1), element, edge_cost);

            if (current_Node->__Node_Degree__ == 0)
            {
                current_Node->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)malloc(sizeof(D_E_U_I_T_S_Edge *));
                current_Node->__Child_Node_Edges_[0] = new_Node->__Parent_Node_Edge__;
                new_Node->__Parent_Node_Edge__->__Node_Connection_In__ = current_Node;
                current_Node->__Node_Degree__++;
            }
            else
            {
                D_E_U_I_T_S_Edge *temp[current_Node->__Node_Degree__];

                for (int i = 0; i < current_Node->__Node_Degree__; i++)
                {
                    temp[i] = current_Node->__Child_Node_Edges_[i];
                }
                current_Node->__Node_Degree__++;
                current_Node->__Child_Node_Edges_ = (D_E_U_I_T_S_Edge **)realloc(current_Node->__Child_Node_Edges_, (current_Node->__Node_Degree__ * sizeof(D_E_U_I_T_S_Edge *)));
                for (int i = 0; (i + 1) < current_Node->__Node_Degree__; i++)
                {
                    current_Node->__Child_Node_Edges_[i] = temp[i];
                }
                current_Node->__Child_Node_Edges_[current_Node->__Node_Degree__ - 1] = new_Node->__Parent_Node_Edge__;
                new_Node->__Parent_Node_Edge__->__Node_Connection_In__ = current_Node;
            }

            if (integer_Tree->__Height__ < new_Node->__Node_Level__)
            {
                integer_Tree->__Height__ = new_Node->__Node_Level__;
            }
        }
    }
}

void __D_E_U_I_T_S_Represent__(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *integer_Tree)
{
    if (integer_Tree->__Height__ == -1)
    {
        printf(__D_E_U_I_T_S__ERROR_01__);
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

void __D_E_U_I_T_S_Initialize__(struct Dynamic_Edged_Unbalanced_Integer_Tree_Structure *new_integer_Tree, int element)
{
    new_integer_Tree->__Height__ = 0;
    new_integer_Tree->__Root_Node__ = __Create_Node__(NULL, 0, element, 0);

    // Functions Declaration...
    (new_integer_Tree->repr) = __D_E_U_I_T_S_Represent__;
    (new_integer_Tree->add) = __D_E_U_I_T_S_Add__;
}

#define int_E_U_Tree_init __D_E_U_I_T_S_Initialize__
#define height __Height__

int main2()
{
    int_E_U_Tree a;
    int_E_U_Tree_init(&a, 5);
    a.repr(&a);
    a.add(&a, NULL, 0, 1, 1);
    a.repr(&a);

    int index[5];
    index[0] = 0;

    a.add(&a, NULL, 0, 2, 2);
    a.add(&a, NULL, 0, 3, 3);
    a.add(&a, NULL, 0, 4, 4);
    a.add(&a, index, 1, 10, 5);
    a.add(&a, index, 1, 20, 6);
    index[0] = 2;
    a.add(&a, index, 1, 30, 7);
    a.add(&a, index, 1, 40, 8);
    index[0] = 0;
    index[1] = 1;
    a.add(&a, index, 2, 100, 9);
    a.repr(&a);
    printf("\nHello World!");
    return 0;
}