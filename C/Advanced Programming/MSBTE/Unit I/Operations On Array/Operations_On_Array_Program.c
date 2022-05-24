#include<stdio.h>
void main()
{
    int n=0,a[n],loc,i;
    printf("\n Enter How many elements you want to store in array:");
    scanf("%d",&n);
    printf("\n Enter your elements:");
    for(i=0;i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n Your elements are:");
    for(i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
    printf("\nDelete Operation:");
    printf("\n Enter the location where you wish to delete element=");
    scanf("%d",&loc);
    if (loc>=n+1)
    {
        printf("\nDeletion not possible");
    }
    else
    {
        for(i=loc=1;i<n;i++)
        {
            a[i]=a[i + 1];
        }    
    }
    printf("\n Array after delete operation:");
    for(i=0;i<n;i++)
    {
        printf("\n%d",a[i]);
    }
}