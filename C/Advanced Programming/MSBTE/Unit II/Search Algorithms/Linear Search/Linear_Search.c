#include <stdio.h>
void main()
{
    int a[5],i,key;
    printf("\nEnter 5 elements in array:");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nArray contains following elements:");
    for ( i = 0; i < 5; i++)
    {
        printf("\n%d",a[i]);
    }
    printf("\nEnter element to search:");
    scanf("%d", &key);
    for(i=0;i<5;i++)
    {
        if (a[i]==key)
        break;    
    }
    if(i==5)
    {
        printf("\nElement nkot found");
    }
    else
    {
        printf("\n Element found at %d position in array",i);
    }
}