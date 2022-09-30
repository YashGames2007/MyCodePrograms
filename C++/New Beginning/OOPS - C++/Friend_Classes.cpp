#include <iostream>
#include <cmath>
using namespace std;

class Square;
class Circle;
class Shape;

class Square
{
private:
    int side;
    int _ID;
    friend class Shape;
    friend class Circle;

public:
    inline int get_Side(void) { return side; }
    inline int get_Perimeter(void) { return (4 * side); }
    inline int get_Area(void) { return (side * side); }
    inline int get_Diagonal(void) { return int(side * sqrt(2.F)); }
    void shape_Details(void);
};

class Circle
{
private:
    int radius;
    int _ID;
    friend class Shape;
    friend class Square;

public:
    inline int get_Radius(void) { return radius; }
    inline int get_Diameter(void) { return (2 * radius); }
    inline int get_Circumference(void) { return (2 * M_PI * radius); }
    inline int get_Area(void) { return (M_PI * radius * radius); }
    void shape_Details(void);
};

class Shape
{
private:
    static int shape_IDs;

public:
    static Square create_Square(int side);
    static Circle create_Circle(int radius);
    static void exchange_IDs(Square &, Circle &);
    static void exchange_IDs(Circle &, Square &);
};

int Shape ::shape_IDs = 0;

Square Shape ::create_Square(int side)
{
    Square new_Square;
    new_Square.side = side;
    new_Square._ID = shape_IDs;
    shape_IDs++;
    return new_Square;
}

Circle Shape ::create_Circle(int radius)
{
    Circle new_Circle;
    new_Circle.radius = radius;
    new_Circle._ID = shape_IDs;
    shape_IDs++;
    return new_Circle;
}

void Shape :: exchange_IDs(Square &square, Circle &circle)
{
    int temporary_ID = square._ID;
    square._ID = circle._ID;
    circle._ID = temporary_ID;
    return;
}

void Shape :: exchange_IDs(Circle &circle, Square &square)
{
    int temporary_ID = square._ID;
    square._ID = circle._ID;
    circle._ID = temporary_ID;
    return;
}

void Square ::shape_Details(void)
{
    cout << "Object Properties :::" << endl
         << "Shape Type     [Class   Attribute] : Square Class" << endl
         << "Shape ID       [Private Attribute] : " << _ID << " $" << endl
         << endl
         << "Shape Properties  :::" << endl
         << "Side Length          [Approximate] : " << side << " Units." << endl
         << "Diagonal Length      [Approximate] : " << get_Diagonal() << " Units." << endl
         << "Square Perimeter     [Approximate] : " << get_Perimeter() << " Units." << endl
         << "Square Area          [Approximate] : " << get_Area() << " Sq. Units." << endl
         << endl
         << endl;
}

void Circle ::shape_Details(void)
{
    cout << "Object Properties :::" << endl
         << "Shape Type     [Class   Attribute] : Circle Class" << endl
         << "Shape ID       [Private Attribute] : " << _ID << " $" << endl
         << endl
         << "Shape Properties  :::" << endl
         << "Circle Radius        [Approximate] : " << radius << " Units." << endl
         << "Circle Diameter      [Approximate] : " << get_Diameter() << " Units." << endl
         << "Circle Circumference [Approximate] : " << get_Circumference() << " Units." << endl
         << "Circle Area          [Approximate] : " << get_Area() << " Sq. Units." << endl
         << endl
         << endl;
}

int main()
{
    Square sq1 = Shape ::create_Square(10);
    Circle ci1 = Shape ::create_Circle(14);

    sq1.shape_Details();
    ci1.shape_Details();
    Shape :: exchange_IDs(sq1, ci1);
    sq1.shape_Details();
    ci1.shape_Details();

    cout << endl;
    return 0;
}