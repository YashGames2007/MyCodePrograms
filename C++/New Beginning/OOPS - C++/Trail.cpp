#include <iostream>
using namespace std;

class Grand_Base
{
    int a, b;
    Grand_Base &self = *this;

public:
    virtual void print(void) { cout << "Grand Base: " << a << ", " << b << endl; }
    Grand_Base(int, int);
};

Grand_Base::Grand_Base(int a = 0, int b = 0)
{
    self.a = a;
    self.b = b;
    self.print();
}

class Base : public Grand_Base
{
    int c, d;
    Base &self = *this;

public:
    virtual void print(void) { cout << "Base: " << c << ", " << d << endl; }
    Base(int, int, int, int);
};

Base::Base(int a = 0, int b = 0, int c = 0, int d = 0) : Grand_Base(a, b)
{
    self.c = c;
    self.d = d;
    self.print();
}

class Derivation : public Base
{
    int e, f;
    Derivation &self = *this;

public:
    Derivation operator+(Derivation);
    virtual void print(void) { cout << "Derivation: " << e << ", " << f << endl; }
    void set(int, int);
    Derivation(int, int, int, int, int, int);
};

Derivation::Derivation(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0) : Base(a, b, c, d)
{
    self.e = e;
    self.f = f;
    self.print();
    cout << endl;
}

void Derivation::set(int e, int f)
{
    self.e = e;
    self.f = f;
}

Derivation Derivation::operator+(Derivation other)
{
    Derivation result;
    result.e = self.e + other.e;
    result.f = self.f + other.f;
    return result;
}

int main()
{
    // Derivation *a = new Derivation[10];

    // a[0].set(3, 4);
    // a[0].Grand_Base::print();
    // a[0].Base::print();
    // a[0].print();

    // a[1].set(4, 5);
    // a[1].Grand_Base::print();
    // a[1].Base::print();
    // a[1].print();

    // Derivation x = a[0] + a[1];

    // x.print();

    Grand_Base *_Grand_Base_Pointer, _Grand_Base_Variable;
    Base *_Base_Pointer, _Base_Variable;
    Derivation *_Derivation_Pointer, _Derivation_Variable;

    // ~~====================================================================**
    // * Possible Combinations...                                           -||
    // ~~====================================================================||
    // @ _Grand_Base_Pointer = &_Grand_Base_Variable;         - Valid       -||
    // @ _Grand_Base_Pointer = &_Base_Variable;               - Valid       -||
    // @ _Grand_Base_Pointer = &_Derivation_Variable;         - Valid       -||
    // ~~====================================================================||
    // ! _Base_Pointer = &_Grand_Base_Variable;               - Invalid     -||
    // @ _Base_Pointer = &_Base_Variable;                     - Valid       -||
    // @ _Base_Pointer = &_Derivation_Variable;               - Valid       -||
    // ~~====================================================================||
    // ! _Derivation_Pointer = &_Grand_Base_Variable;         - Invalid     -||
    // ! _Derivation_Pointer = &_Base_Variable;               - Invalid     -||
    // @ _Derivation_Pointer = &_Derivation_Variable          - Valid       -||
    // ~~====================================================================**

    _Base_Pointer = &_Base_Variable;

    cout << "After Words..." << endl;
    _Base_Pointer->print();

    return 0;
}