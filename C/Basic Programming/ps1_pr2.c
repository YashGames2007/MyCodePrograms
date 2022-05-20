#include <stdio.h>

int main()
{
    float radius;

    printf("Enter the Radius of the circle :- ");
    scanf("%f", &radius);

    printf("The circumference of the circle is %f and Area is %f", 2 * 3.14 * radius, 3.14 * (radius * radius));
    return 0;
}