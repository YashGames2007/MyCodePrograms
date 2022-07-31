#include <iostream>
#include <cmath>
using namespace std;

enum Axis
{
    x_Axis,
    y_Axis,
    z_Axis,
    time_Axis
};

class Vector;
class Vector_1;
class Vector_2;
class Vector_3;
class Vector_4;

class Vector
{
    friend class Vector_1;
    friend class Vector_2;
    friend class Vector_3;
    friend class Vector_4;

private:
    static int vector_IDs;

public:
    static float get_Point_To_Line_Distance(Vector_1 line, Vector_2 point);
    static float get_Point_To_Plane_Distance(Vector_1 plane, Vector_3 point);
    static float get_Point_To_Space_Distance(Vector_1 space, Vector_4 point);

} vector;

int Vector::vector_IDs = 0;

class Vector_1
{
    friend class Vector;

private:
    float Coordinate;
    Axis _axis;
    int vector_ID;

public:
    Vector_1(float, Axis);
    ~Vector_1()
    {
        cout << "Destructing..." << endl;
    }
    float get_Distance(Vector_1);
};

class Vector_2
{
    friend class Vector;

private:
    float Coordinate_1;
    Axis axis_1;
    float Coordinate_2;
    Axis axis_2;
    int vector_ID;

public:
    Vector_2(float, float, Axis, Axis);
    float get_Distance(Vector_2);
};

class Vector_3
{
    friend class Vector;

private:
    float Coordinate_1;
    Axis axis_1;
    float Coordinate_2;
    Axis axis_2;
    float Coordinate_3;
    Axis axis_3;
    int vector_ID;

public:
    Vector_3(float, float, float, Axis, Axis, Axis);
    float get_Distance(Vector_3);
};

class Vector_4
{
    friend class Vector;

private:
    float x_Coordinate;
    float y_Coordinate;
    float z_Coordinate;
    float time_Coordinate;
    int vector_ID;

public:
    Vector_4(float, float, float, float);
    float get_Distance(Vector_4);
};

Vector_1::Vector_1(float point, Axis axis = x_Axis)
{
    Coordinate = point;
    _axis = axis;
    vector_ID = Vector::vector_IDs;
    Vector::vector_IDs++;
}

float Vector_1::get_Distance(Vector_1 vec)
{
    float distance = abs(Coordinate - vec.Coordinate);
    return distance;
}

Vector_2::Vector_2(float co_ordinate_1, float co_ordinate_2, Axis axis1_Type = x_Axis, Axis axis2_Type = y_Axis)
{
    if (axis1_Type < axis2_Type)
    {
        Coordinate_1 = co_ordinate_1;
        axis_1 = axis1_Type;
        Coordinate_2 = co_ordinate_2;
        axis_2 = axis2_Type;
    }
    else
    {
        Coordinate_1 = co_ordinate_2;
        axis_1 = axis2_Type;
        Coordinate_2 = co_ordinate_1;
        axis_2 = axis1_Type;
    }

    vector_ID = Vector::vector_IDs;
    Vector::vector_IDs++;
}

float Vector_2::get_Distance(Vector_2 vec)
{
    if ((axis_1 == vec.axis_1) && (axis_2 == vec.axis_2))
    {
        float distance = abs(sqrt((pow((Coordinate_1 - vec.Coordinate_1), 2)) + (pow((Coordinate_2 - vec.Coordinate_2), 2))));
        return distance;
    }
    else
    {
        __throw_invalid_argument("Invalid Axis Combination!");
    }
    return 0;
}

Vector_3::Vector_3(float co_ordinate_1, float co_ordinate_2, float co_ordinate_3, Axis axis_1_Type = x_Axis, Axis axis_2_Type = y_Axis, Axis axis_3_Type = z_Axis)
{
    if ((axis_1_Type < axis_2_Type) && (axis_2_Type < axis_3_Type))
    {
        Coordinate_1 = co_ordinate_1;
        axis_1 = axis_1_Type;
        Coordinate_2 = co_ordinate_2;
        axis_2 = axis_2_Type;
        Coordinate_3 = co_ordinate_3;
        axis_3 = axis_3_Type;
    }
    else if ((axis_2_Type < axis_3_Type) && (axis_3_Type < axis_1_Type))
    {
        Coordinate_1 = co_ordinate_2;
        axis_1 = axis_2_Type;
        Coordinate_2 = co_ordinate_3;
        axis_2 = axis_3_Type;
        Coordinate_3 = co_ordinate_1;
        axis_3 = axis_1_Type;
    }
    else
    {
        Coordinate_1 = co_ordinate_3;
        axis_1 = axis_3_Type;
        Coordinate_2 = co_ordinate_1;
        axis_2 = axis_1_Type;
        Coordinate_3 = co_ordinate_2;
        axis_3 = axis_2_Type;
    }
    vector_ID = Vector::vector_IDs;
    Vector::vector_IDs++;
}

float Vector_3::get_Distance(Vector_3 vec)
{
    if ((axis_1 == vec.axis_1) && (axis_2 == vec.axis_2) && (axis_3 == vec.axis_3))
    {
        float distance = abs(sqrt((pow((Coordinate_1 - vec.Coordinate_1), 2)) + (pow((Coordinate_2 - vec.Coordinate_2), 2)) + (pow((Coordinate_3 - vec.Coordinate_3), 2))));
        return distance;
    }
    else
    {
        __throw_invalid_argument("Invalid Axis Combination!");
    }

    return 0;
}

Vector_4::Vector_4(float x, float y, float z, float time)
{
    x_Coordinate = x;
    y_Coordinate = y;
    z_Coordinate = z;
    time_Coordinate = time;
    vector_ID = Vector::vector_IDs;
    Vector::vector_IDs++;
}

float Vector_4::get_Distance(Vector_4 vec)
{
    if ((x_Coordinate == vec.x_Coordinate) && (y_Coordinate == vec.y_Coordinate) && (z_Coordinate == vec.z_Coordinate) && (time_Coordinate == vec.time_Coordinate))
    {
        float distance = abs(sqrt((pow((x_Coordinate - vec.x_Coordinate), 2)) + (pow((y_Coordinate - vec.y_Coordinate), 2)) + (pow((z_Coordinate - vec.z_Coordinate), 2)) + (pow((time_Coordinate - vec.time_Coordinate), 2))));
        return distance;
    }
    else
    {
        __throw_invalid_argument("Invalid Axis Combination!");
    }

    return 0;
}

int main()
{
    Vector_1 x(15.F);
    Vector_1 y(10.F);
    cout << "Distance (x, y) = " << x.get_Distance(y) << endl;
    Vector_2 a(-3.F, -4.F, y_Axis, x_Axis);
    Vector_2 b(0.F, 0.F);
    cout << "Distance (a, b) = " << a.get_Distance(b) << endl;

    return 0;
}