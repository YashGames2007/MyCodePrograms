#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
    T x_Axis;
    T y_Axis;

public:
    Vector(T x, T y);
    T cross_Section(Vector &);
    T &operator[](int axis)
    {
        if (axis == 1)
        {
            return x_Axis;
        }
        else if (axis == 2)
        {
            return y_Axis;
        }
        T *err = new T(-1);
        return *(err);
    }
    template <class U>
    friend ostream &operator<<(ostream &out, Vector<U> &vec);
};

template <class T>
Vector<T>::Vector(T x, T y)
{
    this->x_Axis = x;
    this->y_Axis = y;
}

template <class T>
T Vector<T>::cross_Section(Vector &vec)
{
    return ((this->x_Axis * vec.y_Axis) + (this->y_Axis * vec.x_Axis));
}

template <class T>
ostream &operator<<(ostream &out, Vector<T> &vec)
{
    out << "{" << vec.x_Axis << ", " << vec.y_Axis << "}";
    return out;
}

int main()
{
    Vector<int> a(4, 5);
    Vector<int> b(1, 3);
    cout << "Cross: " << a.cross_Section(b) << endl;
    cout << "Cross: " << b.cross_Section(a) << endl;
    cout << a << " & " << b << endl;
    a[2] = 8;
    cout << a << " & " << b << endl;
    return 0;
}