#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Dynamic Graphs Implementation\Dynamic Directed Graph Structure Implementation\Dynamic_Integer_Directed_Graph_Structure.c"

int main()
{    
    int_D_Graph a;
    printf("\nOk!1");
    int_D_Graph_init(&a, 5);
    a.create_New_Node(&a, 1, 10);
    a.create_New_Node(&a, 2, 10);
    a.create_New_Node(&a, 3, 10);
    a.create_New_Node(&a, 4, 10);
    a.create_New_Node(&a, 5, 10);
    a.join_Connection(&a, 0, 1);
    a.join_Connection(&a, 0, 4);
    a.join_Connection(&a, 0, 5);
    a.join_Connection(&a, 1, 0);
    a.join_Connection(&a, 1, 2);
    a.join_Connection(&a, 2, 3);
    int_D_I_D_G_S_Node *node1 = a.get_Connection(&a, 0, 0);
    int_D_I_D_G_S_Node *node2 = a.get_Connection(&a, 1, 0);
    printf("\nNeighbours1: %d, Neighbours2: %d", node1->__Connected_Node_Count__, node2->__Connected_Node_Count__);
    printf("\nData1: %d, Data2: %d", node1->__Node_Data__, node2->__Node_Data__);
    int _size;
    int *arr = a.traverse_DFS(&a, &_size);

    printf("\n{%d", arr[0]);
    for (int i = 1; i < _size; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("}.");

    printf("\nDone ... !!!");
    return 0;
}