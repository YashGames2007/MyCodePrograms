#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Custom_Headers.c"
#include Integer_Array
#include Pointer_Array
#include Integer_Queue
#include Integer_Stack

// Defining Some Error Massages
#define __D_I_D_G_S__ERROR_01__ "\nDirected Integer Graph :-| ERROR 01 |-<%s> Operation Can't Be Performed, Because Integer Directed Graph is Deleted!!!", __FUNCTION__
#define __D_I_D_G_S__ERROR_02__ "\nDirected Integer Graph :-| ERROR 02 |-<%s> Operation Can't Be Performed, Because Integer Directed Graph Index Out of Range!!!", __FUNCTION__

typedef struct Dynamic_Integer_Directed_Graph_Structure_Node
{
    int __Node_Data__;
    unsigned int __Node_ID__;
    ptr_Array __Connected_Nodes__;
    int __Connected_Node_Count__;
} int_D_I_D_G_S_Node;

/*
---
---
---
# Directed Integer Graph :
---
---
---
## Methods
---
---
## 1. repr
#### Represents The Integer Directed Graph in Curly Brackets.
---
### Arguments
#### 1. int_D_Graph structure
---
---
## 2. delete
#### Deletes The Whole Integer Directed Graph.
---
### Arguments
#### 1. int_D_Graph structure
---
---
## 3. pop
#### Removes The Element At Given Index and Returns The Element.
---
### Arguments
#### 1. int_D_Graph structure
#### 2. int index
---
---
## 4. search
#### Returns The Index of First Occurrence of The Element In The Integer Directed Graph, Returns -1 If The Element is Not Present In The List.
---
### Arguments
#### 1. int_D_Graph structure
#### 2. int element
---
---
## 5. create_New_Node
#### Appends The Element At The End Of The Integer Directed Graph.
---
### Arguments
#### 1. int_D_Graph structure
#### 2. int element
---
---
## 6. remove
#### Removes The First Occurrence Of The Specified Element in The Integer Directed Graph.
---
### Arguments
#### 1. int_D_Graph structure
#### 2. int element
---
---
## 7. join_Connection
#### Inserts The Element At Specified Index In The Integer Directed Graph.
---
### Arguments
#### 1. int_D_Graph structure
#### 2. int index
#### 3. int element
---
---
---
---
---
*/
typedef struct Dynamic_Integer_Directed_Graph_Structure
{
    int __Size__; //#### Size of Integer Directed Graph
    int_D_I_D_G_S_Node *__Base_Node__;

    ptr_Array __Included_Nodes__;
    int_Array __Included_Identities__;

    /*### Represents The Integer Directed Graph in Curly Brackets. */
    void (*repr)(struct Dynamic_Integer_Directed_Graph_Structure *structure);
    /*### Deletes The Whole Integer Directed Graph. */
    void (*delete)(struct Dynamic_Integer_Directed_Graph_Structure *structure);
    /*### Removes The Element At Given Index and Returns The Element. */
    int (*pop)(struct Dynamic_Integer_Directed_Graph_Structure *structure, int index);
    /*### Removes The Element At Given Index and Returns The Element. */
    int *(*traverse_BFS)(struct Dynamic_Integer_Directed_Graph_Structure *structure, int *_size);
    /*### Removes The Element At Given Index and Returns The Element. */
    int *(*traverse_DFS)(struct Dynamic_Integer_Directed_Graph_Structure *structure, int *_size);
    /*### Returns The ID of First Occurrence of The Element In The Integer Directed Graph, Returns -1 If The Element is Not Present In The List. */
    unsigned int (*search)(struct Dynamic_Integer_Directed_Graph_Structure *structure, int element);
    /*### Appends The Element At The End of The Integer Directed Graph. */
    void (*create_New_Node)(struct Dynamic_Integer_Directed_Graph_Structure *structure, unsigned int _ID, int element);
    /*### Removes The First Occurrence Of The Specified Element in The Integer Directed Graph. */
    void (*remove)(struct Dynamic_Integer_Directed_Graph_Structure *structure, unsigned int _ID);
    /*### Inserts The Element At Specified Index In The Integer Directed Graph. */
    void (*join_Connection)(struct Dynamic_Integer_Directed_Graph_Structure *structure, unsigned int _ID_1, unsigned int _ID_2);
    /*### Inserts The Element At Specified Index In The Integer Directed Graph. */
    int_D_I_D_G_S_Node *(*get_Connection)(struct Dynamic_Integer_Directed_Graph_Structure *structure, unsigned int _ID_1, int index);
    /*### Inserts The Element At Specified Index In The Integer Directed Graph. */
    int_D_I_D_G_S_Node *(*get)(struct Dynamic_Integer_Directed_Graph_Structure *structure, unsigned int _ID);

} int_D_Graph;

int_D_I_D_G_S_Node *__D_I_D_G_S_Get_Connection__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, unsigned int _ID_1, int index)
{
    int dex = int_Direct_Graph->__Included_Identities__.search(&(int_Direct_Graph->__Included_Identities__), _ID_1);
    if (dex != -1)
    {
        int_D_I_D_G_S_Node *node_1 = int_Direct_Graph->__Included_Nodes__.get(&(int_Direct_Graph->__Included_Nodes__), dex);
        if (node_1->__Connected_Node_Count__ <= index)
        {
            printf(__D_I_D_G_S__ERROR_02__);
            return NULL;
        }
        return node_1->__Connected_Nodes__.get(&(node_1->__Connected_Nodes__), index);
    }
}

int_D_I_D_G_S_Node *__D_I_D_G_S_Get__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, unsigned int _ID)
{
    int index = int_Direct_Graph->__Included_Identities__.search(&(int_Direct_Graph->__Included_Identities__), _ID);
    if (index != -1)
    {
        return int_Direct_Graph->__Included_Nodes__.__Base_Address__[index];
    }
    return NULL;
}

void __D_I_D_G_S_Join_Connection__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, unsigned int _ID_1, unsigned int _ID_2)
{
    if (int_Direct_Graph->__Included_Identities__.search(&(int_Direct_Graph->__Included_Identities__), _ID_1) != -1 && int_Direct_Graph->__Included_Identities__.search(&(int_Direct_Graph->__Included_Identities__), _ID_2) != -1)
    {
        int_D_I_D_G_S_Node *node_1, *node_2;
        for (int i = 0; i < int_Direct_Graph->__Size__; i++)
        {
            node_1 = (int_D_I_D_G_S_Node *)int_Direct_Graph->__Included_Nodes__.get(&(int_Direct_Graph->__Included_Nodes__), i);
            if (node_1->__Node_ID__ == _ID_1)
            {
                break;
            }
        }
        for (int i = 0; i < int_Direct_Graph->__Size__; i++)
        {
            node_2 = (int_D_I_D_G_S_Node *)int_Direct_Graph->__Included_Nodes__.get(&(int_Direct_Graph->__Included_Nodes__), i);
            if (node_2->__Node_ID__ == _ID_2)
            {
                break;
            }
        }
        if (node_1->__Connected_Nodes__.search(&(node_1->__Connected_Nodes__), node_2) != -1)
        {
            return;
        }

        node_1->__Connected_Node_Count__++;
        node_2->__Connected_Node_Count__++;
        node_1->__Connected_Nodes__.append(&(node_1->__Connected_Nodes__), node_2);
        node_2->__Connected_Nodes__.append(&(node_2->__Connected_Nodes__), node_1);
    }
}

void __D_I_D_G_S_Remove__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, unsigned int _ID)
{
}

void __D_I_D_G_S_Create_New_Node__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, unsigned int _ID, int element)
{
    if (int_Direct_Graph->__Included_Identities__.search(&(int_Direct_Graph->__Included_Identities__), _ID) == -1)
    {
        int_D_I_D_G_S_Node *new_Node = (int_D_I_D_G_S_Node *)malloc(sizeof(int_D_I_D_G_S_Node));
        new_Node->__Connected_Node_Count__ = 0;
        ptr_Array_init(&(new_Node->__Connected_Nodes__));
        new_Node->__Node_ID__ = _ID;
        new_Node->__Node_Data__ = element;
        int_Direct_Graph->__Included_Nodes__.append(&(int_Direct_Graph->__Included_Nodes__), new_Node);
        int_Direct_Graph->__Size__++;
        int_Direct_Graph->__Included_Identities__.append(&(int_Direct_Graph->__Included_Identities__), _ID);
    }
}

unsigned int __D_I_D_G_S_Search__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, int element)
{
}

int __D_I_D_G_S_Pop__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, int index)
{
}

int *__D_I_D_G_S_Depth_First_Search_Traversal__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, int *_size)
{
    int_Array visited_Node_IDs;
    int_Array_init(&visited_Node_IDs);
    int_Stack exploration_Stack;
    int_Stack_init(&exploration_Stack);

    int_D_I_D_G_S_Node *temp_Node;
    int_D_I_D_G_S_Node *current_Node = int_Direct_Graph->__Base_Node__;
    exploration_Stack.push(&exploration_Stack, current_Node->__Node_ID__);

    int _ID;
    while (exploration_Stack.__Size__ != 0)
    {
        _ID = exploration_Stack.pop(&exploration_Stack);
        current_Node = int_Direct_Graph->get(int_Direct_Graph, _ID);
        visited_Node_IDs.append(&visited_Node_IDs, current_Node->__Node_ID__);

        for (int i = 0; i < current_Node->__Connected_Node_Count__; i++)
        {
            temp_Node = int_Direct_Graph->get_Connection(int_Direct_Graph, current_Node->__Node_ID__, i);

            if (visited_Node_IDs.search(&visited_Node_IDs, temp_Node->__Node_ID__) == -1)
            {
                exploration_Stack.push(&exploration_Stack, temp_Node->__Node_ID__);
            }
        }
    }
    
    *_size = visited_Node_IDs.__Size__;
    return visited_Node_IDs.__Base_Address__;
}

int *__D_I_D_G_S_Breadth_First_Search_Traversal__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph, int *_size)
{
    int_D_I_D_G_S_Node *current_Node = int_Direct_Graph->__Base_Node__;
    int_D_I_D_G_S_Node *temp_Node = current_Node;

    int_Queue exploration_Queue;
    int_Queue_init(&exploration_Queue);
    int_Array visited_Node_IDs;
    int_Array_init(&visited_Node_IDs);

    visited_Node_IDs.append(&visited_Node_IDs, current_Node->__Node_ID__);
    exploration_Queue.inQueue(&exploration_Queue, current_Node->__Node_ID__);
    int _ID;

    while (exploration_Queue.__Size__ != 0)
    {
        _ID = exploration_Queue.deQueue(&exploration_Queue);
        current_Node = int_Direct_Graph->get(int_Direct_Graph, _ID);

        for (int i = 0; i < current_Node->__Connected_Node_Count__; i++)
        {
            temp_Node = int_Direct_Graph->get_Connection(int_Direct_Graph, current_Node->__Node_ID__, i);

            if (visited_Node_IDs.search(&visited_Node_IDs, temp_Node->__Node_ID__) == -1)
            {
                visited_Node_IDs.append(&visited_Node_IDs, temp_Node->__Node_ID__);
                exploration_Queue.inQueue(&exploration_Queue, temp_Node->__Node_ID__);
            }
        }
    }
    *_size = visited_Node_IDs.__Size__;
    return visited_Node_IDs.__Base_Address__;
}

void __D_I_D_G_S_Represent__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph)
{
}

void __D_I_D_G_S_Delete__(struct Dynamic_Integer_Directed_Graph_Structure *int_Direct_Graph)
{
}

void __D_I_D_G_S_Initialize__(int_D_Graph *new_int_Direct_Graph, int node_Data)
{
    new_int_Direct_Graph->__Size__ = 1;
    new_int_Direct_Graph->__Base_Node__ = (int_D_I_D_G_S_Node *)malloc(sizeof(int_D_I_D_G_S_Node));
    new_int_Direct_Graph->__Base_Node__->__Connected_Node_Count__ = 0;
    ptr_Array_init(&(new_int_Direct_Graph->__Base_Node__->__Connected_Nodes__));
    new_int_Direct_Graph->__Base_Node__->__Node_ID__ = 0;
    new_int_Direct_Graph->__Base_Node__->__Node_Data__ = node_Data;

    ptr_Array_init(&(new_int_Direct_Graph->__Included_Nodes__));
    int_Array_init(&(new_int_Direct_Graph->__Included_Identities__));
    new_int_Direct_Graph->__Included_Identities__.append(&(new_int_Direct_Graph->__Included_Identities__), 0);
    new_int_Direct_Graph->__Included_Nodes__.append(&(new_int_Direct_Graph->__Included_Nodes__), new_int_Direct_Graph->__Base_Node__);
    // Functions Declaration...
    (new_int_Direct_Graph->pop) = __D_I_D_G_S_Pop__;
    (new_int_Direct_Graph->get) = __D_I_D_G_S_Get__;
    (new_int_Direct_Graph->delete) = __D_I_D_G_S_Delete__;
    (new_int_Direct_Graph->remove) = __D_I_D_G_S_Remove__;
    (new_int_Direct_Graph->search) = __D_I_D_G_S_Search__;
    (new_int_Direct_Graph->repr) = __D_I_D_G_S_Represent__;
    (new_int_Direct_Graph->get_Connection) = __D_I_D_G_S_Get_Connection__;
    (new_int_Direct_Graph->create_New_Node) = __D_I_D_G_S_Create_New_Node__;
    (new_int_Direct_Graph->join_Connection) = __D_I_D_G_S_Join_Connection__;
    (new_int_Direct_Graph->traverse_BFS) = __D_I_D_G_S_Breadth_First_Search_Traversal__;
    (new_int_Direct_Graph->traverse_DFS) = __D_I_D_G_S_Depth_First_Search_Traversal__;
}

#define int_D_Graph_init __D_I_D_G_S_Initialize__
#define size __Size__