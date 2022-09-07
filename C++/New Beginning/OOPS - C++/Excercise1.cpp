#include <iostream>
#include <cmath>

using namespace std;

class Simple_Calculation
{
protected:
    long double value;

public:
    Simple_Calculation(void) { value = 0; }

    void add(long double adder) { value += adder; }
    void sub(long double subtracter) { value -= subtracter; }
    void mul(long double multiplier) { value *= multiplier; }
    void div(long double divider) { value /= divider; }
    void mod(long double modular) { value = fmod(value, modular); }
    void expo(long double exponent) { value = pow(value, exponent); }
    void root(long double root) { value = pow(value, 1 / root); }

    long double get(void) { return value; }
};

class Scientific_Calculation : public Simple_Calculation
{
public:
    // Scientific_Calculation() { value = 0; }

    void sin() { value = std ::sin(value / 180 * M_PI); }
    void cos() { value = std ::cos(value / 180 * M_PI); }
    void tan() { value = std ::tan(value / 180 * M_PI); }
    void csc() { value = (1.L / std ::sin(value / 180 * M_PI)); }
    void sec() { value = (1.L / std ::cos(value / 180 * M_PI)); }
    void cot() { value = (1.L / std ::tan(value / 180 * M_PI)); }

    void opp() { value = (1.L / value); }

};

class Calculation : public Scientific_Calculation
{

public:
    // Calculation() { value = 0; }
};
int main()
{
    Calculation calc;

    calc.add(2);
    cout << "Get: " << calc.get() << endl;
    calc.opp();
    cout << "Get: " << calc.get() << endl;
    return 0;
}