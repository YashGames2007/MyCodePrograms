#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES
// const long double pi = M_PI;

/* Creates a 2 Dimensional Point Vector. */
typedef struct Vector_2D
{
    long int x_Point; // Value of 2D Point on X Axis.
    long int y_Point; // Value of 2D Point on Y Axis.
} vector2;

/* Returns The Euclidean Distance Between Two Vector2 datatypes */
double euclidean_distance(vector2 a, vector2 b);
/* Returns The Manhattan Distance Between Two Vector2 datatypes */
double manhattan_distance(vector2 a, vector2 b);
/* Returns The Area of Circle By Calculating Its Radius Using Given Distance Finder Function Pointer.*/
long double circle_Area_Finder(vector2 a, vector2 b, double (*distance_Calculator) (vector2, vector2));

int main()
{
    vector2 p = {4, 3}; // 2 Dimensional Point p. (x, y) = (4, 3)
    vector2 q = {5, 7}; // 2 Dimensional Point p. (x, y) = (5, 7)

    printf("\nP: [%ld][%ld], Q: [%ld][%ld].", p.x_Point, p.y_Point, q.x_Point, q.y_Point);
    printf("\n");
    printf("\nThe Euclidean Distance Between P and Q is:  %lf", euclidean_distance(p, q));
    printf("\nThe Manhattan Distance Between P and Q is:  %lf", manhattan_distance(p, q));
    printf("\n");
    printf("\nThe Area of The Circle Having Distance Between P and Q as It's Radius Using Euclidean Distance Function is: \n%.44Lf", circle_Area_Finder(p, q, euclidean_distance));
    printf("\n");
    printf("\nThe Area of The Circle Having Distance Between P and Q as It's Radius Using Manhattan Distance Function is: \n%.44Lf", circle_Area_Finder(p, q, manhattan_distance));

    return 0;
}
double euclidean_distance(vector2 a, vector2 b)
{
    double distance = 0; // Distance Between A & B.
    // Calculating The Distance...
    distance = (double) abs(sqrt((pow((b.x_Point - a.x_Point), 2) + pow((b.y_Point - a.y_Point), 2))));
    return distance;
}
double manhattan_distance(vector2 a, vector2 b)
{
    double distance = 0; // Distance Between A & B.
    // Calculating The Distance...
    distance = (double) abs(((b.x_Point - a.x_Point) + (b.y_Point - a.y_Point)));
    return distance;
}
long double circle_Area_Finder(vector2 a, vector2 b, double (*distance_Calculator) (vector2, vector2))
{
    long double area = 0; // Area of The Circle.
    double radius = 0; // Radius of The Circle.

    // Calculating Radius Using Given Finder...
    radius = (*distance_Calculator)(a, b);
    // Calculating Area of The Circle Using Pre-Defined Value of Pi in Math.h...
    area = (long double) (M_PI * (pow(radius, 2)));
    return area;
}