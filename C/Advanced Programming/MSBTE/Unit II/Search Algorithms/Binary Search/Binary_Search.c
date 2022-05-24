#include<stdio.h>
void main()
{
    int top,bottom,mid,size,i,key,k[100];
    printf("\n Enter size of array:");
    scanf("%d",&size);
    printf("\nEnter %d values in sorted order:",size);
    for(i=0;i<size;i++)
    {
        scanf("%d", &k[i]);
    }
    printf("\nEnter value to be serch:");
    scanf("%d",&key);
    top=0;
    bottom=size-1;
    mid=(top+bottom)/2;
    while (top<=bottom)
    {
        if (k[mid]<key)

            top=mid+1;
            else if(k[mid]==key)
            {
                printf("\nElement found at index %d",mid);
                break;
            }
            else
                bottom=mid-1;
                mid=(top+bottom)/2;
    }
    if(top>bottom)
    printf("\nElement not found");
}