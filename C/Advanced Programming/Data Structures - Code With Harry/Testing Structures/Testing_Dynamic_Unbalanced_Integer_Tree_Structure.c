#include <stdio.h>
#include "E:\Programming files\Code\C\Custom Includable Header Files\Dynamic Tree Implementation\Dynamic Unbalanced Tree Implementation\Dynamic_Unbalanced_Integer_Tree_Implementation.c"
#include <stdlib.h>

int traverser(D_U_I_T_S_Node *root, int *leaf)
{
    if (root->__Node_Degree__ == 0)
    {
        leaf[0]++;
    }
    int degree = root->__Node_Degree__;
    for (int i = 0; i < root->__Node_Degree__; i++)
    {
        printf("\n");
        printf("[%d]", root->__Child_Nodes__[i]->__Node_Data__);
    }
    
    for (int i = 0; i < root->__Node_Degree__; i++)
    {
        degree += traverser(root->__Child_Nodes__[i], leaf);
    }
    return degree;
}

int traverse(integer_Tree *tree, int *leaf)
{
    printf("\n");
    printf("[%d]", tree->__Root_Node__->__Node_Data__);
    int nodes = (1 + traverser(tree->__Root_Node__, leaf));
    return nodes;
}

int main()
{
    integer_Tree a;
    integer_Tree_init(&a, 5);
    int index[5];
    index[0] = 0;

    a.add(&a, NULL, 0, 4);
    a.add(&a, NULL, 0, 3);
    a.add(&a, NULL, 0, 2);
    a.add(&a, index, 1, 10);
    a.add(&a, index, 1, 20);
    index[0] = 2;
    a.add(&a, index, 1, 30);
    a.add(&a, index, 1, 40);
    index[0] = 0;
    index[1] = 1;
    a.add(&a, index, 2, 100);
    // a.__Root_Node__->__Node_Degree__++;
    // D_U_I_T_S_Node *new_Node = (D_U_I_T_S_Node *)malloc(sizeof(D_U_I_T_S_Node));
    // new_Node->__Node_Data__ = 3;
    // new_Node->__Node_Degree__ = 0;
    // new_Node->__Parent_Node__ = a.__Root_Node__;
    // new_Node->__Node_Level__ = 1;

    // a.__Root_Node__->__Child_Nodes__[1] = new_Node;
    printf("\nDone");

    // printf("\n%d", a.__Root_Node__->__Node_Data__);
    // printf("\n%d", a.__Root_Node__->__Child_Nodes__[0]->__Node_Data__);
    // printf("\n%d", a.__Root_Node__->__Child_Nodes__[1]->__Node_Data__);
    // printf("\n%d", a.__Root_Node__->__Node_Degree__);
    // int childs = a.__Root_Node__->__Node_Degree__;
    // int spaces = ((((4 * childs) + ((childs - 1) * 2)) / 2) - 2);
    // printf("\n");
    // for (int i = 0; i < spaces; i++)
    // {
    //     printf(" ");
    // }
    {
        printf("\n");
        printf("            ");
        printf("[0%d]", a.__Root_Node__->__Node_Data__);
        printf("\n");
        printf("      _______/\\_______");
        printf("\n");
        printf("     /       \\/       \\");
        printf("\n");
        printf("   ");
        printf("[0%d]", a.__Root_Node__->__Child_Nodes__[0]->__Node_Data__);
        printf("     [0%d]", a.__Root_Node__->__Child_Nodes__[1]->__Node_Data__);
        printf("     [0%d]", a.__Root_Node__->__Child_Nodes__[2]->__Node_Data__);
        printf("\n");
        printf("   _/\\_              _/\\_");
        printf("\n");
        printf("  /    \\            /    \\");
        printf("\n");
        printf("[%d]", a.__Root_Node__->__Child_Nodes__[0]->__Child_Nodes__[0]->__Node_Data__);
        printf("  [%d]", a.__Root_Node__->__Child_Nodes__[0]->__Child_Nodes__[1]->__Node_Data__);
        printf("    ");
        printf("    ");
        printf("[%d]", a.__Root_Node__->__Child_Nodes__[2]->__Child_Nodes__[0]->__Node_Data__);
        printf("  [%d]", a.__Root_Node__->__Child_Nodes__[2]->__Child_Nodes__[1]->__Node_Data__);
        printf("\n\nHello World!!!");
    }
    
    int leaf[] = {0};
    printf("\n\n#[%d]#, #[%d]#", traverse(&a, leaf), a.height); 
    printf("\n[%d]", a.__Root_Node__->__Child_Nodes__[0]->__Child_Nodes__[1]->__Child_Nodes__[0]->__Node_Level__);
    printf("\n##-#[%d]#-##", leaf[0]);
    a.repr(&a);
    a.remove(&a, 10);
    a.repr(&a);
    int path[a.height];
    int size  = a.search(&a, 100, path);
    
    printf("\n{%d", path[0]);
    for (int i = 1; i < size; i++)
    {
        printf(", %d", path[i]);
    }
    printf("}.\n");

    a.delete(&a);
    a.repr(&a);
    printf("\nDone");
    return 0;
}