#include<stdio.h>
void main()
{
    int a[5]={23,14,29,11,1};
    int i,j,temp;
    printf("\nArray Before Sorting:");
    for(i=0;i<5;i++)
    {
        printf("\n%d",a[i]);
    }
    for(i=0;i<4;i++)        //pass=4    0 1   2   3
    {
        for(j=0;j< 4;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\nArray After Sorting:");
    for ( i = 0; i < 5; i++)
    {
        printf("\n%d",a[i]);
    }
    
}