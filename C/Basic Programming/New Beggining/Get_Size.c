#include <stdio.h>

int main()
{
    printf("\nPrinting The Size Allocation For Different Data Types In Your PC's Memory...\n");
    printf("\nThe Size in The Memory [RAM] of An char           :  %d", sizeof(char));
    printf("\nThe Size in The Memory [RAM] of An unsigned char  :  %d", sizeof(unsigned char));
    printf("\n");
    printf("\nThe Size in The Memory [RAM] of An short int      :  %d", sizeof(short int));
    printf("\n");
    printf("\nThe Size in The Memory [RAM] of An int            :  %d", sizeof(int));
    printf("\nThe Size in The Memory [RAM] of An long int       :  %d", sizeof(long int));
    printf("\nThe Size in The Memory [RAM] of An unsigned int   :  %d", sizeof(unsigned int));
    printf("\nThe Size in The Memory [RAM] of An float          :  %d", sizeof(float));
    printf("\n");
    printf("\nThe Size in The Memory [RAM] of An double         :  %d", sizeof(double));
    printf("\n");
    printf("\nThe Size in The Memory [RAM] of An long double    : %d ", sizeof(long double));
    printf("\n");
    printf("\n");
    return 0;
}