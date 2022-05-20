#include <stdio.h>

int main()
{
    int length, breadth;

    printf("Hello Programmers !!!\n");

    printf("Enter the length of the rectangle :- ");
    scanf("%d", &length);

    printf("Enter the Breadth of the rectangle:- ");
    scanf("%d", &breadth);

    printf("The Area & Perimeter of the Rectangle is %d & %d respectively.", length * breadth, (2 * length) + (2 * breadth));
    return 0;
}