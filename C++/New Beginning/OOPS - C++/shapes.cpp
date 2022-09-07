#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
private:
    float side, length, breadth, height, base;
    double radius;
    enum shapes {square, rectangle, triangle, circle};

public:
    shapes shape_Type;
    double area;
    float perimeter;
    void create(char _type, double side_OR_radius);
    void create(char _type, float length_OR_base, float breadth_OR_height);
};


void Shape ::create(char _type, double side_OR_radius)
{
    if (_type == 's')
    {
        shape_Type = square;
        side = side_OR_radius;

        perimeter = (4 * side);
        area = (pow(side, 2));
    }
    else if (_type == 'c')
    {
        shape_Type = circle;
        radius = side_OR_radius;
        long double pi = 3.141592653589793238L;
        perimeter = (2 * pi * radius);
        area = (pi * (pow(radius, 2)));
    }
}

void Shape ::create(char _type, float length_OR_base, float breadth_OR_height)
{
    if (_type == 't')
    {
        shape_Type = triangle;

        base = length_OR_base;
        height = breadth_OR_height;

        perimeter = (3 * base);
        area = (0.5 * base * height);
    }
    else if (_type == 'r')
    {
        shape_Type = rectangle;

        length = length_OR_base;
        breadth = breadth_OR_height;

        perimeter = ((2 * length) + (2 * breadth));
        area = (length * breadth);
    }
    
}

int main()
{
    Shape s1;
    s1.create('s', 4.5);
    cout << "Area of Square is " << s1.area << endl;
    cout << "Perimeter of Square is " << s1.perimeter << endl;
    // cout << "Hello World!" << endl;

    Shape s2;
    s2.create('t', 5, 10);
    cout << "Area of Triangle is " << s2.area << endl;
    cout << "Perimeter of Triangle is " << s2.perimeter << endl;
    return 0;
}